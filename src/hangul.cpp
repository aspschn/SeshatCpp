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

HangulSyllableType hangul_syllable_type(uint32_t cp)
{
    if (S_BASE <= cp && cp <= S_BASE + S_COUNT - 1) {
        uint32_t s_index = S_INDEX(cp);
        uint32_t t_part = T_PART(T_INDEX(s_index));
        if (t_part == T_BASE) { // Jongseong not exists
            return HangulSyllableType::LV;
        } else {
            return HangulSyllableType::LVT;
        }
    }
    if ((L_BASE <= cp && cp <= 0x115F) ||
        (0xA960 <= cp && cp <= 0xA97C))
        return HangulSyllableType::L;
    if ((0x1160 <= cp && cp <= 0x11A7) ||
        (0xD7B0 <= cp && cp <= 0xD7C6))
        return HangulSyllableType::V;
    if ((0x11A8 <= cp && cp <= 0x11FF) ||
        (0xD7CB <= cp && cp <= 0xD7FB))
        return HangulSyllableType::T;
    return HangulSyllableType::NA;
}

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

uint32_t compose(uint32_t first, uint32_t last)
{
    if (COMPOSABLE_L(first) && COMPOSABLE_V(last)) {
        uint32_t l_index = first - L_BASE;
        uint32_t v_index = last - V_BASE;
        return S_BASE + (l_index * N_COUNT) + (v_index * T_COUNT);
    }
    if (hangul_syllable_type(first) == HangulSyllableType::LV &&
            COMPOSABLE_T(last)) {
        uint32_t t_index = last - T_BASE;
        return first + t_index;
    }
    return 0x0; // Default: Not defined.
}

} // namespace hangul
} // namespace unicode
} // namespace seshat
