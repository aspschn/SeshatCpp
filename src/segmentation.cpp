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
        if ((gcb((*it).code()) == Gcb::CR) &&
            (gcb((*(it + 1)).code()) == Gcb::LF)) {
            ++boundary;
            continue;
        }
        // GB4 - break before controls
        if ((gcb((*it).code()) == Gcb::CN) ||
            (gcb((*it).code()) == Gcb::CR) ||
            (gcb((*it).code()) == Gcb::LF)) {
            break;
        }
        // GB5 - break after controls
        // GB6 - do not break Hangul syllable sequences
        if ((gcb((*it).code()) == Gcb::L)
            &&
            ((gcb((*(it + 1)).code()) == Gcb::L) ||
            (gcb((*(it + 1)).code()) == Gcb::V) ||
            (gcb((*(it + 1)).code()) == Gcb::LV) ||
            (gcb((*(it + 1)).code()) == Gcb::LVT))) {
            ++boundary;
            continue;
        }
        // GB7 - do not break Hangul syllable sequences
        if ((gcb((*it).code()) == Gcb::LV) ||
            (gcb((*it).code()) == Gcb::V)
            &&
            ((gcb((*(it + 1)).code()) == Gcb::V) ||
            (gcb((*(it + 1)).code()) == Gcb::T))) {
            ++boundary;
            continue;
        }
        // GB8 - do not break Hangul syllable sequences
        if (((gcb((*it).code()) == Gcb::LVT) ||
            (gcb((*it).code()) == Gcb::T))
            &&
            (gcb((*(it + 1)).code()) == Gcb::T)) {
            ++boundary;
            continue;
        }
        // GB9 - do not break before Extend or ZWJ
        if ((gcb((*(it + 1)).code()) == Gcb::EX) ||
            (gcb((*(it + 1)).code()) == Gcb::ZWJ)) {
            ++boundary;
            continue;
        }
        // GB9a - do not break before SpacingMark
        if (gcb((*(it + 1)).code()) == Gcb::SM) {
            ++boundary;
            continue;
        }
        // GB9b - do not break after Prepend
        if (gcb((*it).code()) == Gcb::PP) {
            ++boundary;
            continue;
        }
        // GB10 - do not break within emoji modifier sequences
        if (gcb((*(it + 1)).code()) == Gcb::EM) {
            if ((gcb((*it).code()) == Gcb::EB) ||
                (gcb((*it).code()) == Gcb::EBG)) {
                ++boundary;
                continue;
            }
            // Seek back until found EB or EBG
            if ((gcb((*it).code()) == Gcb::EX)) {
                for (auto back_it = it - 1; back_it != first; --back_it) {
                    // Continue to seek if EX
                    if (gcb((*back_it).code()) == Gcb::EX)
                        continue;
                    // If EB or EBG found, the sequence is
                    // Emoji Modifier Sequence
                    if ((gcb((*back_it).code()) == Gcb::EB) ||
                        (gcb((*back_it).code()) == Gcb::EBG)) {
                        ++boundary;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        // GB11 - do not break within emoji zwj sequences
        if ((gcb((*it).code()) == Gcb::ZWJ)
            &&
            ((gcb((*(it + 1)).code()) == Gcb::GAZ) ||
            (gcb((*(it + 1)).code()) == Gcb::EBG))) {
            ++boundary;
            continue;
        }
        // GB12 - do not break within emoji flag sequences
        // GB13 - do not break within emoji flag sequences
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
