/*
//  hangul.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 17. 16:27
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/hangul.h>

namespace seshat {
namespace unicode {
namespace hangul {

const char* JAMO_L_TABLE[L_COUNT] =  {
    "G", "GG", "N", "D", "DD", "R", "M", "B", "BB", "S",
    "SS", "", "J", "JJ", "C", "K", "T", "P", "H"
};

const char* JAMO_V_TABLE[V_COUNT] = {
    "A", "AE", "YA", "YAE", "EO", "E", "YEO", "YE", "O", "WA", "WAE", "OE",
    "YO", "U", "WEO", "WE", "WI", "YU", "EU", "YI", "I"
};

const char* JAMO_T_TABLE[T_COUNT] = {
    "", "G", "GG", "GS", "N", "NJ", "NH", "D", "L", "LG",
    "LM", "LB", "LS", "LT", "LP", "LH", "M", "B", "BS", "S",
    "SS", "NG", "J", "C", "K", "T", "P", "H"
};

std::string syllable_name(uint32_t syllab_code)
{
    uint32_t s_index = S_INDEX(syllab_code);
    uint32_t l_index = L_INDEX(s_index);
    uint32_t v_index = V_INDEX(s_index);
    uint32_t t_index = T_INDEX(s_index);

    std::string name = std::string(JAMO_L_TABLE[l_index])
        + JAMO_V_TABLE[v_index] + JAMO_T_TABLE[t_index];

    return name;
}

const CodePointSequence decompose(uint32_t cp)
{
    // Code point not hangul syllable.
    if (!(HANGUL_SYLLABLE_BEGIN <= cp &&
        cp <= HANGUL_SYLLABLE_BEGIN + S_COUNT - 1)) {
        return CodePointSequence();
    }

    uint32_t s_index = S_INDEX(cp);
    uint32_t l_part = L_PART(L_INDEX(s_index));
    uint32_t v_part = V_PART(V_INDEX(s_index));
    uint32_t t_part = T_PART(T_INDEX(s_index));

    if (t_part == T_BASE) { // Jongseong not exists
        return CodePointSequence {
            CodePoint(l_part), CodePoint(v_part)
        };
    } else {
        return CodePointSequence {
            CodePoint(l_part), CodePoint(v_part), CodePoint(t_part)
        };
    }
}

} // namespace hangul
} // namespace unicode
} // namespace seshat
