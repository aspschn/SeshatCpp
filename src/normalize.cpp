/*
//  normalize.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 11:59
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/normalize.h>

#include <seshat/unicode/dm.h>
#include <seshat/unicode/hangul.h>
#include <seshat/unicode/normalization_props.h> // comp_ex(), quick checks
#include <seshat/unicode/properties.h>

namespace seshat {
namespace unicode {

bool starter(uint32_t cp)
{
    // Refer D107 in Starters, 3.11 (Unicode 9.0.0 & 10.0.0)
    auto cp_gc = gc(cp);
    auto cp_ccc = ccc(cp);

    if (cp_gc != Gc::Mn && cp_gc != Gc::Mc && cp_gc != Gc::Me) {
        return (cp_ccc == 0) ? true : false;
    } else {
        switch (cp_gc) {
        case Gc::Mn:
        case Gc::Mc:
            return (cp_ccc <= 0) ? true : false;
        case Gc::Me:
            return (cp_ccc == 0) ? true : false;
        default:
            return false;
        }
    }
    return false;
}

bool reorderable(uint32_t cp_1, uint32_t cp_2)
{
    // Refer D108 in Canonical Ordering Algorithm
    if (ccc(cp_1) > ccc(cp_2) && ccc(cp_2) > 0) {
        return true;
    }
    return false;
}

void canonical_ordering(CodePointSequence& sequence)
{
    // This ordering algorithm acts like a bubble sort
    const auto last = sequence.begin() + 1;
    auto sorted = sequence.end();
    while (sorted != last) {
        auto end = sorted;
        for (auto it = sequence.begin(); it != end - 1; ++it) {
            if (reorderable(it[0], it[1])) {
                std::iter_swap(it, it + 1);
            }
        }
        --sorted;
    }
}

bool full_composition_exclusion(uint32_t cp)
{
    return comp_ex(cp);
}

bool primary_composite(uint32_t cp)
{
    // According to D114 (Unicode 9.0.0 & 10.0.0),
    // Primary composite is "A Canonical Decomposable Character which
    // is not a Full Composition Exclusion."
    return (dt(cp) == Dt::Can && !full_composition_exclusion(cp));
}

bool blocked(CodePointSequenceConstIter first,
    CodePointSequenceConstIter last)
{
    if ( !(ccc(*first) == 0) ) return false;
    auto iter = last;
    if (--iter == first) return false;
    if (ccc(*iter) == 0 || ccc(*iter) >= ccc(*last)) {
        return true;
    }
    return false;
}

CodePointSequence nfd(const CodePointSequence& sequence)
{
    CodePointSequence decomp;

    // Decompose each code points
    for (auto cp: sequence) {
        if (dt(cp) == Dt::Can) {
            // For Hangul, using conjoining algorithm instead of search dm.
            auto mapping = (block(cp) != Block::Hangul) ?
                dm(cp) : hangul::decompose(cp);
            for (auto each: mapping) {
                decomp.append(each);
            }
        } else {
            decomp.append(cp);
        }
    }
    // Re-order the decomposed sequence
    canonical_ordering(decomp);

    // Do recursively until pass quick check
    if (nfd_qc(decomp) != QcValue::Yes) {
        return nfd(decomp);
    }
    return decomp;
}

// void compose(CodePointSequence&) - Compose the sequence that decomposed.
//  Used for NFC or NFKC composition. The input sequence should be already
//  decomposed with NFD or NFKD.
static void compose(CodePointSequence& sequence)
{
    // Return immediately if a single character.
    if (sequence.length() == 1) return;

    // Starting from the second character.
    decltype(sequence.begin())::difference_type offset = 1;
    while (offset < sequence.length()) {
        // Find the last Starter.
        auto it = sequence.begin() + offset;
        auto b_it = it - 1; // Back iterator.
        while (b_it != sequence.begin() && !starter(*b_it)) --b_it;
        if (starter(*b_it) && !blocked(b_it, it)) {
            auto mapped = (hangul::composable_pair(*b_it, *it)) ?
                hangul::compose(*b_it, *it) : rdm({ *b_it, *it });
            if (mapped != 0x0 && primary_composite(mapped)) {
                *b_it = mapped;
                sequence.erase(it);
                --offset; // Move back because a code point deleted.
            }
        }
        ++offset;
    }
    // return sequence;
}

CodePointSequence nfc(const CodePointSequence& sequence)
{
    if (sequence.length() == 0) return sequence;

    // Make NFD normalization form.
    auto ret = nfd(sequence);

    compose(ret);
    return ret;
}

CodePointSequence nfkd(const CodePointSequence& sequence)
{
    CodePointSequence decomp;

    // Decompose each code points.
    for (auto cp: sequence) {
        auto mapping = dm(cp);
        // Using Hangul decomposition if Hangul syllable.
        if (block(cp) == Block::Hangul && dt(cp) == Dt::Can)
            mapping = hangul::decompose(cp);
        if (mapping.length() > 0) {
            decomp.insert(decomp.end(), mapping.begin(), mapping.end());
        } else {
            decomp.append(cp);
        }
    }
    // Re-order the decomposed sequence
    canonical_ordering(decomp);

    // Do recursively until pass quick check
    if (nfkd_qc(decomp) != QcValue::Yes) {
        return nfkd(decomp);
    }
    return decomp;
}

CodePointSequence nfkc(const CodePointSequence& sequence)
{
    if (sequence.length() == 0) return sequence;

    // Make NFKD normalization form.
    auto ret = nfkd(sequence);

    compose(ret);
    return ret;
}

} // namespace unicode
} // namespace seshat
