//
//  unicode/hangul.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 17. 11:29
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Definitions for hangul algorithms.
#ifndef _UNICODE_HANGUL_H
#define _UNICODE_HANGUL_H

#include <seshat/codepoint.h>

#include <cstdint>
#include <string>

namespace seshat {
namespace unicode {
namespace hangul {

#define HANGUL_SYLLABLE_BEGIN   0xAC00  // '가' <HANGUL SYLLABLE GA>
#define HANGUL_CHOSUNG_BEGIN    0x1100  // 'ᄀ' <HANGUL CHOSEONG KIYEOK>
#define HANGUL_JUNGSUNG_BEGIN   0x1161  // <HANGUL JUNGSEONG A>
#define HANGUL_JONGSUNG_BEGIN   0x11A8  // <HANGUL JONGSEONG KIYEOK>

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

/// \brief  Unicode character property Hangul_Syllable_Type.
enum class HangulSyllableType {
    L,      // Leading_Jamo
    LV,     // LV_Syllable
    LVT,    // LVT_Syllable
    NA,     // Not_Applicable
    T,      // Trailing_Jamo
    V       // Vowel_Jamo
};

// Unicode character property
/// \brief  Get Hangul_Syllable_Type property value of given code point.
HangulSyllableType hangul_syllable_type(CodePoint cp);

// Hangul jamo name mapping
//
extern const char* JAMO_L_TABLE[L_COUNT];
extern const char* JAMO_V_TABLE[V_COUNT];
extern const char* JAMO_T_TABLE[T_COUNT];

// Naming
/// \brief  Builds hangul syllable name for Name Unicode property.
/// \param  syllab_code
///         Valid hangul syllable code point.
///
/// Behavior for not a hangul syllable code point is undefined.
std::string syllable_name(uint32_t syllab_code);

// Conjoining
//

/// \brief  True when code point is a composable hangul L jamo.
/*!
// COMPOSABLE_L(uint32_t) - Detect if given code point is in
//  range which is canonically composable Hangul L Jamo.
 */
#define COMPOSABLE_L(code) \
    ((0x1100 <= (code) && (code) <= 0x1112) ? true : false)

/// \brief  True when code point is a composable hangul V jamo.
/*!
// COMPOSABLE_V(uint32_t) - Detect if given code point is in
//  range which is canonically composable Hangul V Jamo.
 */
#define COMPOSABLE_V(code) \
    ((0x1161 <= (code) && (code) <= 0x1175) ? true : false)

/// \brief  True when code point is a composable hangul T jamo.
/*!
// COMPOSABLE_T(uint32_t) - Detect if given code point is in
//  range which is canonically composable Hangul T Jamo.
 */
#define COMPOSABLE_T(code) \
    ((0x11A8 <= (code) && (code) <= 0x11C2) ? true : false)

/// \brief  Returns true if the code point pair is composable.
/*!
// bool composable_pair(uint32_t, uint32_t) - If given code point
//  pair is L-V or LV-T, the pair is composable hangul pair.
 */
inline bool composable_pair(uint32_t first, uint32_t last)
{
    return ((COMPOSABLE_L(first) && COMPOSABLE_V(last)) ||
        (hangul_syllable_type(first) == HangulSyllableType::LV &&
            COMPOSABLE_T(last)) ? true : false);
}

/// \brief  Decompose hangul syllable to canonical decomposed sequence.
const CodePointSequence decompose(uint32_t cp);

/// \brief  Compose the composable hangul jamo pair.
///
/// Canonical compose L and V type or LV and T type.\n
/// Return value: Canonical composed Hangul syllable.\n
/// Notes: Out of composable L-V or LV-T pair cause undefined behavior. So
/// before using this function, check the pair with composable_pair() function.
uint32_t compose(uint32_t first, uint32_t last);

} // namespace hangul
} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_HANGUL_H */
