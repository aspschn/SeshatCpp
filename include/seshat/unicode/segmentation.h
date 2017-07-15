 /*
//  unicode/segmentation.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 19. 18:03
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode text segmentation functions such as Grapheme Cluster Boundary,
//  Word Boundary, Sentence Boundary.
*/
#ifndef _UNICODE_SEGMENTATION_H
#define _UNICODE_SEGMENTATION_H

#include <seshat/codepoint.h>

#include <cstdint>

namespace seshat {
namespace unicode {

// Functions and enums for CLDR segmentation rules.
namespace cldr {
    class Gcb {
    private:
        uint32_t _cp;
    public:
        Gcb(uint32_t cp);
        bool cr() const; // CR
        bool lf() const; // LF
        bool control() const; // CN
        bool extend() const; // EX
        bool zwj() const; // ZWJ
        bool regional_indicator() const; // RI
        bool prepend() const; // PP
        bool spacing_mark() const; // SM
        bool l() const; // L
        bool v() const; // V
        bool t() const; // T
        bool lv() const; // LV
        bool lvt() const; // LVT
        bool e_base() const; // EB, and many others.
        bool e_modifier() const; // EM
        bool extended_pict() const; // Many others.
        bool e_base_gaz() const; // EBG
        bool emoji_nrk() const; // Emoji - (Regional_Indicator + [*#0-9©®™〰〽])
    };
} // namespace cldr

template <typename It>
It grapheme_bound(It first, It last);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_SEGMENTATION_H */
