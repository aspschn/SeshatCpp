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

CodePointSequence::size_type grapheme_bound(const CodePointSequence& seq,
    CodePointSequence::size_type pos)
{
    decltype(pos) boundary = pos;
    auto eot = seq.end();

    auto it = seq.begin();
    for (decltype(pos) i = 0; i < pos; ++i)
        ++it;
    for (; it != eot; ++it) {
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
        // GB10 -
        // GB999 - otherwise, break everywhere
        break;
    }
    return boundary;
}

} // namespace unicode
} // namespace seshat
