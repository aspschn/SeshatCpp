/*
//  properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:07
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/properties.h>

#include <seshat/unicode/emoji.h>
#include <seshat/unicode/gc.h>
#include <seshat/unicode/hangul.h>
#include "ucd/block.h"
#include "ucd/core.h"
#include "ucd/script.h"

namespace seshat {
namespace unicode {

/*
Script script(uint32_t cp)
{
    auto found = ucd::script_table.find(CodePointRange(cp, cp));

    if (found != ucd::script_table.end()) {
        return found->second;
    }
    return Script::Zzzz;
}
*/

Block block(uint32_t cp)
{
    auto found = ucd::block_table.find(CodePointRange(cp, cp));

    if (found != ucd::block_table.end()) {
        return found->second;
    }
    return Block::NB;
}

Gcb gcb(uint32_t cp)
{
    using hangul::HangulSyllableType;
    using hangul::hangul_syllable_type;

    if (cp == 0x000D)
        return Gcb::CR;
    if (cp == 0x000A)
        return Gcb::LF;
    // Gcb::CN (Control)
    //
    // General_Category = Line_Separator, or
    // General_Category = Paragraph_Separator, or
    // General_Category = Control, or
    // General_Category = Unassigned and Default_Ignorable_Code_Point, or
    // General_Category = Surrogate, or
    // General_Category = Format
    // and not U+000D CARRIAGE RETURN
    // and not U+000A LINE FEED
    // and not U+200C ZERO WIDTH NON-JOINER (ZWNJ)
    // and not U+200D ZERO WIDTH JOINER (ZWJ)
    if (gc(cp) == Gc::Zl ||
        gc(cp) == Gc::Zp ||
        gc(cp) == Gc::Cc ||
        (gc(cp) == Gc::Cn && default_ignorable_code_point(cp) == true) ||
        gc(cp) == Gc::Cs ||
        (gc(cp) == Gc::Cf &&
            cp != 0x000D && cp != 0x000A && cp != 0x200C && cp != 0x200D))
        return Gcb::CN;
    if (grapheme_extend(cp))
        return Gcb::EX; // Extend
    if (cp == 0x200D)
        return Gcb::ZWJ;
    // Gcb::RI (Regional_Indicator)
    //
    // U+1F1E6 REGIONAL INDICATOR SYMBOL LETTER A
    // ..U+1F1FF REGIONAL INDICATOR SYMBOL LETTER Z
    if (0x1F1E6 <= cp && cp <= 0x1F1FF)
        return Gcb::RI;
    // Gcb::PP (Prepend)
    //
    // Indic_Syllabic_Category = Consonant_Preceding_Repha, or
    // Indic_Syllabic_Category = Consonant_Prefixed, or
    // Prepended_Concatenation_Mark = Yes
    if ((0x0600 <= cp && cp <=0x0605) ||
        (cp == 0x070F) ||
        (cp == 0x06DD) ||
        (cp == 0x08E2) ||
        (cp == 0x0D4E) ||
        (cp == 0x110BD) ||
        (0x111C2 <= cp && cp <= 0x111C3))
        return Gcb::PP;
    // Gcb::SM (SpacingMark)
    //
    // Grapheme_Cluster_Break ≠ Extend, and
    // General_Category = Spacing_Mark, or
    // any of the following (which have General_Category = Other_Letter):
    // U+0E33 ( ำ ) THAI CHARACTER SARA AM
    // U+0EB3 ( ຳ ) LAO VOWEL SIGN AM

    // Exceptions: The following (which have General_Category = Spacing_Mark and would otherwise be included) are specifically excluded:
    // U+102B ( ါ ) MYANMAR VOWEL SIGN TALL AA
    // U+102C ( ာ ) MYANMAR VOWEL SIGN AA
    // U+1038 ( း ) MYANMAR SIGN VISARGA
    // U+1062 ( ၢ ) MYANMAR VOWEL SIGN SGAW KAREN EU
    // ..U+1064 ( ၤ ) MYANMAR TONE MARK SGAW KAREN KE PHO
    // U+1067 ( ၧ ) MYANMAR VOWEL SIGN WESTERN PWO KAREN EU
    // ..U+106D ( ၭ ) MYANMAR SIGN WESTERN PWO KAREN TONE-5
    // U+1083 ( ႃ ) MYANMAR VOWEL SIGN SHAN AA
    // U+1087 ( ႇ ) MYANMAR SIGN SHAN TONE-2
    // ..U+108C ( ႌ ) MYANMAR SIGN SHAN COUNCIL TONE-3
    // U+108F ( ႏ ) MYANMAR SIGN RUMAI PALAUNG TONE-5
    // U+109A ( ႚ ) MYANMAR SIGN KHAMTI TONE-1
    // ..U+109C ( ႜ ) MYANMAR VOWEL SIGN AITON A
    // U+1A61 ( ᩡ ) TAI THAM VOWEL SIGN A
    // U+1A63 ( ᩣ ) TAI THAM VOWEL SIGN AA
    // U+1A64 ( ᩤ ) TAI THAM VOWEL SIGN TALL AA
    // U+AA7B ( ꩻ ) MYANMAR SIGN PAO KAREN TONE
    // U+AA7D ( ꩽ ) MYANMAR SIGN TAI LAING TONE-5
    // U+11720 ( 𑜠 ) AHOM VOWEL SIGN A
    // U+11721 ( 𑜡 ) AHOM VOWEL SIGN AA
    if (!(grapheme_extend(cp)) &&
        gc(cp) == Gc::Mc ||
        (cp == 0x0E33 || cp == 0x0EB3)) {
        if (cp != 0x102B ||
            cp != 0x102C ||
            cp != 0x1038 ||
            !(0x1062 <= cp && cp <= 0x1064) ||
            !(0x1067 <= cp && cp <= 0x106D) ||
            cp != 0x1083 ||
            !(0x1087 <= cp && cp <= 0x108C) ||
            cp != 0x108F ||
            !(0x109A <= cp && cp <= 0x109C) ||
            cp != 0x1A61 ||
            cp != 0x1A63 ||
            cp != 0x1A64 ||
            cp != 0xAA7B ||
            cp != 0xAA7D ||
            cp != 0x11720 ||
            cp != 0x11721) {
            return Gcb::SM;
        }
    }
    if (hangul_syllable_type(cp) == HangulSyllableType::L)
        return Gcb::L;
    if (hangul_syllable_type(cp) == HangulSyllableType::V)
        return Gcb::V;
    if (hangul_syllable_type(cp) == HangulSyllableType::T)
        return Gcb::T;
    if (hangul_syllable_type(cp) == HangulSyllableType::LV)
        return Gcb::LV;
    if (hangul_syllable_type(cp) == HangulSyllableType::LVT)
        return Gcb::LVT;
    // Gcb::EB (E_Base)
    //
    // Emoji characters listed as Emoji_Modifier_Base=Yes in emoji-data.txt,
    // which do not occur after ZWJ in emoji-zwj-sequences.txt. See [UTR51].
    if (0) // TODO: IMPLEMENT!
        return Gcb::EB;
    if (emoji::emoji_modifier(cp))
        return Gcb::EM;
    if (0) // TODO: IMPLEMENT!
        return Gcb::GAZ;
    if (0) // TODO: IMPLEMENT!
        return Gcb::EBG;
    return Gcb::XX; // Other
}

bool odi(uint32_t cp)
{
    auto found = ucd::odi_table.find(CodePointRange(cp, cp));
    return (found != ucd::odi_table.end()) ? true : false;
}

bool ogr_ext(uint32_t cp)
{
    auto found = ucd::ogr_ext_table.find(CodePointRange(cp, cp));
    return (found != ucd::ogr_ext_table.end()) ? true : false;
}

bool prepended_concatenation_mark(uint32_t cp)
{
    auto found = ucd::pcm_table.find(CodePointRange(cp, cp));
    return (found != ucd::pcm_table.end()) ? true : false;
}

bool grapheme_extend(uint32_t cp)
{
    // # Derived Property: Grapheme_Extend
    // #  Generated from: Me + Mn + Other_Grapheme_Extend
    if (gc(cp) == Gc::Me || gc(cp) == Gc::Mn || ogr_ext(cp) == true)
        return true;
    return false;
}

bool default_ignorable_code_point(uint32_t cp)
{
    // # Derived Property: Default_Ignorable_Code_Point
    // #  Generated from
    // #    Other_Default_Ignorable_Code_Point
    // #  + Cf (Format characters)
    // #  + Variation_Selector
    // #  - White_Space
    // #  - FFF9..FFFB (Annotation Characters)
    // #  - 0600..0605, 06DD, 070F, 08E2, 110BD (exceptional Cf characters that should be visible)
    if (odi(cp) || gc(cp) == Gc::Cf || variation_selector(cp)) {
        if (!(white_space(cp)) && !(0xFFF9 <= cp && cp <= 0xFFFB) &&
            !(cp == 0x0600) && !(cp == 0x0605) && !(cp == 0x06DD) &&
            !(cp == 0x070F) && !(cp == 0x08E2) && !(cp == 0x110BD)) {
            return true;
        }
    }
    return false;
}

bool variation_selector(uint32_t cp)
{
    // From PropList.txt (Unicode 9.0.0)
    // 180B..180D    ; Variation_Selector # Mn   [3]
    // FE00..FE0F    ; Variation_Selector # Mn  [16]
    // E0100..E01EF  ; Variation_Selector # Mn [240]
    // # Total code points: 259
    if ((0x180B <= cp && cp <= 0x180D) ||
        (0xFE00 <= cp && cp <= 0xFE0F) ||
        (0xE0100 <= cp && cp <= 0xE01EF))
        return true;
    else
        return false;
}

bool white_space(uint32_t cp)
{
    auto found = ucd::wspace_table.find(CodePointRange(cp, cp));
    return (found != ucd::wspace_table.end()) ? true : false;
}

} // namespace unicode
} // namespace seshat
