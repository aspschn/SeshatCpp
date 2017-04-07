/*
//  unicodedata.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 05. 20:37
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Enums, database for Unicode Data.
*/
#ifndef _UNICODEDATA_H
#define _UNICODEDATA_H

#include <cstdint>
#include <map>

namespace seshat {

// Gc: General_Category enum
enum class Gc {
    C,
    Cc, Cf, Cn, Co, Cs,
    L,
    LC, Ll, Lm, Lo, Lt, Lu,
    M,
    Mc, Me, Mn,
    N,
    Nd, Nl, No,
    P, Pc, Pd, Pe, Pf, Pi, Po, Ps,
    S,
    Sc, Sk, Sm, So,
    Z,
    Zl, Zp, Zs,
};

extern const std::map<uint32_t, Gc> gc_table;

// 3400-4DB5: CJK Ideograph Extension A (Lo)
#define CJK_IDEO_EXT_A_FRST 0x3400 // '<CJK Ideograph Extension A, First>'
#define CJK_IDEO_EXT_A_LAST 0x4DB5 // '<CJK Ideograph Extension A, Last>'
// 4E00-9FD5: CJK Ideograph (Lo)
#define CJK_IDEO_FRST       0x4E00 // '<CJK Ideograph, First>'
#define CJK_IDEO_LAST       0x9FD5 // '<CJK Ideograph, Last>'
// AC00-D7A3: Hangul Syllable (Lo)
#define HANGUL_SYLLAB_FRST  0xAC00 // '<Hangul Syllable, First>'
#define HANGUL_SYLLAB_LAST  0xD7A3 // '<Hangul Syllable, Last>'
// D800-DB7F: Non Private Use High Surrogate (Cs)
#define NON_PU_HIGH_SRG_FRST 0xD800 // '<Non Private Use High Surrogate, First>'
#define NON_PU_HIGH_SRG_LAST 0xDB7F // '<Non Private Use High Surrogate, Last>'
// DB80-DBFF: Private Use High Surrogate (Cs)
#define PU_HIGH_SRG_FRST    0xDB80 // '<Private Use High Surrogate, First>'
#define PU_HIGH_SRG_LAST    0xDBFF // '<Private Use High Surrogate, Last>'
// DC00-DFFF: Low Surrogate (Cs)
#define LOW_SRG_FRST        0xDC00 // '<Low Surrogate, First>'
#define LOW_SRG_LAST        0xDFFF // '<Low Surrogate, Last>'
// E000-F8FF: Private Use (Co)
#define PU_FRST             0xE000 // '<Private Use, First>'
#define PU_LAST             0xF8FF // '<Private Use, Last>'
// 17000-187EC: Tangut Ideograph (Lo)
#define TANGUT_IDEO_FRST    0x17000 // '<Tangut Ideograph, First>'
#define TANGUT_IDEO_LAST    0x187EC // '<Tangut Ideograph, Last>'
// 20000-2A6D6: CJK Ideograph Extension B (Lo)
#define CJK_IDEO_EXT_B_FRST 0x20000 // '<CJK Ideograph Extension B, First>'
#define CJK_IDEO_EXT_B_LAST 0x2A6D6 // '<CJK Ideograph Extension B, Last>'
// 2A700-2B734: CJK Ideograph Extension C (Lo)
#define CJK_IDEO_EXT_C_FRST 0x2A700 // '<CJK Ideograph Extension C, First>'
#define CJK_IDEO_EXT_C_LAST 0x2B734 // '<CJK Ideograph Extension C, Last>'
// 2B740-2B81D: CJK Ideograph Extension D (Lo)
#define CJK_IDEO_EXT_D_FRST 0x2B740 // '<CJK Ideograph Extension D, First>'
#define CJK_IDEO_EXT_D_LAST 0x2B81D // '<CJK Ideograph Extension D, Last>'
// 2B820-2CEA1: CJK Ideograph Extension E (Lo)
#define CJK_IDEO_EXT_E_FRST 0x2B820 // '<CJK Ideograph Extension E, First>'
#define CJK_IDEO_EXT_E_LAST 0x2CEA1 // '<CJK Ideograph Extension E, Last>'
// F0000-FFFFD: Plane 15 Private Use (Co)
#define PLANE_15_PU_FRST    0xF0000 // '<Plane 15 Private Use, First>'
#define PLANE_15_PU_LAST    0xFFFFD // '<Plane 15 Private Use, Last>'
// 100000-10FFFD: Plane 16 Private Use (Co)
#define PLANE_16_PU_FRST    0x100000 // '<Plane 16 Private Use, First>'
#define PLANE_16_PU_LAST    0x10FFFD // '<Plane 16 Private Use, Last>'


} // namespace seshat

#endif /* _UNICODEDATA_H */
