/*
//  segmentation.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 19. 18:24
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/segmentation.h>

#include <seshat/unicode/properties.h>

namespace seshat {
namespace unicode {

template <typename It>
It grapheme_bound(It first, It last)
{
    auto boundary = first;
    auto eot = last;

    for (auto it = first; it != eot; ++it) {
        // GB1 - break at the sot
        // GB2 - break at the eot
        if ((it + 1) == eot) {
            break;
        }
        // GB3 - do not break between a CR and LF
        if ((gcb(*it) == Gcb::CR) &&
            (gcb(*(it + 1)) == Gcb::LF)) {
            ++boundary;
            continue;
        }
        // GB4 - break before controls
        if ((gcb(*it) == Gcb::CN) ||
            (gcb(*it) == Gcb::CR) ||
            (gcb(*it) == Gcb::LF)) {
            break;
        }
        // GB5 - break after controls
        // GB6 - do not break Hangul syllable sequences
        if ((gcb(*it) == Gcb::L)
            &&
            ((gcb(*(it + 1)) == Gcb::L) ||
            (gcb(*(it + 1)) == Gcb::V) ||
            (gcb(*(it + 1)) == Gcb::LV) ||
            (gcb(*(it + 1)) == Gcb::LVT))) {
            ++boundary;
            continue;
        }
        // GB7 - do not break Hangul syllable sequences
        if ((gcb(*it) == Gcb::LV) ||
            (gcb(*it) == Gcb::V)
            &&
            ((gcb(*(it + 1)) == Gcb::V) ||
            (gcb(*(it + 1)) == Gcb::T))) {
            ++boundary;
            continue;
        }
        // GB8 - do not break Hangul syllable sequences
        if (((gcb(*it) == Gcb::LVT) ||
            (gcb(*it) == Gcb::T))
            &&
            (gcb(*(it + 1)) == Gcb::T)) {
            ++boundary;
            continue;
        }
        // GB9 - do not break before Extend or ZWJ
        if ((gcb(*(it + 1)) == Gcb::EX) ||
            (gcb(*(it + 1)) == Gcb::ZWJ)) {
            ++boundary;
            continue;
        }
        // GB9a - do not break before SpacingMark
        if (gcb(*(it + 1)) == Gcb::SM) {
            ++boundary;
            continue;
        }
        // GB9b - do not break after Prepend
        if (gcb(*it) == Gcb::PP) {
            ++boundary;
            continue;
        }
        // GB10 - do not break within emoji modifier sequences
        if (gcb(*(it + 1)) == Gcb::EM) {
            if ((gcb(*it) == Gcb::EB) ||
                (gcb(*it) == Gcb::EBG)) {
                ++boundary;
                continue;
            }
            // Seek back until found EB or EBG
            if ((gcb(*it) == Gcb::EX)) {
                for (auto back_it = it - 1; back_it != first; --back_it) {
                    // Continue to seek if EX
                    if (gcb(*back_it) == Gcb::EX)
                        continue;
                    // If EB or EBG found, the sequence is
                    // Emoji Modifier Sequence
                    if ((gcb(*back_it) == Gcb::EB) ||
                        (gcb(*back_it) == Gcb::EBG)) {
                        ++boundary;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        // GB11 - do not break within emoji zwj sequences
        // Emoji ZWJ Sequence break not works properly since it
        // requires CLDR expanded rule.
        if ((gcb(*it) == Gcb::ZWJ)
            &&
            ((gcb(*(it + 1)) == Gcb::GAZ) ||
            (gcb(*(it + 1)) == Gcb::EBG))) {
            ++boundary;
            continue;
        }
        // GB12 - do not break within emoji flag sequences
        // GB13 - do not break within emoji flag sequences
        if ((gcb(*it) == Gcb::RI)
            &&
            (gcb(*(it + 1)) == Gcb::RI)) {
            ++boundary;
            break;
        }
        // GB999 - otherwise, break everywhere
        break;
    }
    return boundary;
}

template
CodePointSequenceIter grapheme_bound<CodePointSequenceIter>(
    CodePointSequenceIter first, CodePointSequenceIter last);

template
CodePointSequenceConstIter grapheme_bound<CodePointSequenceConstIter>(
    CodePointSequenceConstIter first, CodePointSequenceConstIter last);

} // namespace unicode
} // namespace seshat
