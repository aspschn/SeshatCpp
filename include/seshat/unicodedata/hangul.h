/*
//  unicodedata/hangul.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 17. 11:29
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UNICODEDATA_HANGUL_H
#define _UNICODEDATA_HANGUL_H

#include <cstdint>
#include <map>
#include <string>

namespace seshat {
namespace hangul {

#define HANGUL_SYLLABLE_BEGIN   0xAC00  // '가' <HANGUL SYLLABLE GA>
#define HANGUL_CHOSUNG_BEGIN    0x1100
#define HANGUL_JUNGSUNG_BEGIN   0x1161
#define HANGUL_JONGSUNG_BEGIN   0x11A8

#define S_BASE  0xAC00  // Syllable
#define L_BASE  0x1100  // Leading
#define V_BASE  0x1161  // Vowel
#define T_BASE  0x11A7  // Trailing

#define L_COUNT 19
#define V_COUNT 21
#define T_COUNT 28
#define N_COUNT 588     // V_COUNT * T_COUNT
#define S_COUNT 11172   // L_COUNT * N_COUNT

#define S_INDEX(s)      ((s) - S_BASE)
#define L_INDEX(s_idx)  ((s_idx) / N_COUNT)
#define V_INDEX(s_idx)  (((s_idx) % N_COUNT) / T_COUNT)
#define T_INDEX(s_idx)  ((s_idx) % T_COUNT)

#define L_PART(l_idx)   (L_BASE + (l_idx))
#define V_PART(v_idx)   (V_BASE + (v_idx))
#define T_PART(t_idx)   (T_BASE + (t_idx))

// Hangul jamo name mapping
//
extern const char* JAMO_L_TABLE[L_COUNT];
extern const char* JAMO_V_TABLE[V_COUNT];
extern const char* JAMO_T_TABLE[T_COUNT];

// Naming
std::string syllable_name(uint32_t syllab_code);

} // namespace hangul
} // namespace seshat

#endif /* _UNICODEDATA_HANGUL_H */
