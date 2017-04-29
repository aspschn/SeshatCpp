/*
//  normalize.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 11:59
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/normalize.h>

#include <seshat/unicode/ccc.h>
#include <seshat/unicode/gc.h>

namespace seshat {
namespace unicode {

bool starter(uint32_t cp)
{
    // Refer D107 in Starters, 3.11 (Unicode 9.0.0)
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
            if (reorderable(it[0].code(), it[1].code())) {
                std::iter_swap(it, it + 1);
            }
        }
        --sorted;
    }
}

} // namespace unicode
} // namespace seshat
