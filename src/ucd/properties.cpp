/*
//  ucd/properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 23. 18:54
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//
//
*/
#include "properties.h"

#include <seshat/unicode/emoji.h>
#include <seshat/unicode/hangul.h>
#include <seshat/unicode/version.h>

#include "age.h"
#include "block.h"
#include "case_mapping.h"
#include "ccc.h"
#include "core.h"
#include "dt.h"
// #include "gc.h"
#include "gcb.h"
#include "normalization_props.h"
#include "script.h"

namespace seshat {
namespace unicode {
namespace ucd {

Version age(uint32_t cp)
{
    auto found = ucd::age_table.find(CodePointRange(cp, cp));
    if (found != ucd::age_table.end())
        return Version { found->second.major, found->second.minor, 0 };
    return Version { 0, 0, 0 };
}

Block block(uint32_t cp)
{
    auto found = ucd::block_table.find(CodePointRange(cp, cp));

    if (found != ucd::block_table.end()) {
        return found->second;
    }
    return Block::NB;
}

uint8_t ccc(uint32_t cp)
{
    auto found = ucd::ccc_table.find(CodePointRange(cp, cp));

    if (found != ucd::ccc_table.end()) {
        return found->second;
    } else {
        return 0;
    }
}

Dt dt(uint32_t cp)
{
    auto found = ucd::dt_table.find(CodePointRange(cp, cp));

    if (found != ucd::dt_table.end()) {
        return found->second;
    }
    return Dt::None;
}

/*
Gc gc(uint32_t cp)
{
    // Find the gc matching the range that code point belongs
    uint32_t code = cp;
    auto found = ucd::gc_table.find(CodePointRange(code, code));

    if (found != ucd::gc_table.end()) {
        return found->second;
    } else {
        return Gc::Cn;
    }
}
*/

/*
Gcb gcb(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");

    using hangul::HangulSyllableType;
    using hangul::hangul_syllable_type;

    // http://www.unicode.org/reports/tr29/#Grapheme_Cluster_Break_Property_Values
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
    if (emoji::emoji_modifier(cp))
        return Gcb::EM;
    auto found = ucd::gcb_table.find(CodePointRange(cp, cp));
    if (found != ucd::gcb_table.end()) {
        return found->second;
    }
    return Gcb::XX; // Other
}
*/

bool grapheme_extend(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");
    // # Derived Property: Grapheme_Extend
    // #  Generated from: Me + Mn + Other_Grapheme_Extend
    if (gc(cp) == Gc::Me || gc(cp) == Gc::Mn || ogr_ext(cp) == true)
        return true;
    return false;
}

bool cased(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");
    // D135 (From The Unicode Standard 3.13 Default Case Algorithms, 10.0.0)
    // A character C is defined to be cased if and only if C has the
    // Lowercase or Uppercase property or has a General_Category value of
    // Titlecase_Letter.
    if (lowercase(cp) || uppercase(cp) || gc(cp) == Gc::Lt) {
        return true;
    }
    return false;
}

bool default_ignorable_code_point(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");
    // From DerivedCoreProperties.txt (Unicode 10.0.0)
    // # Derived Property: Default_Ignorable_Code_Point
    // #  Generated from
    // #    Other_Default_Ignorable_Code_Point
    // #  + Cf (Format characters)
    // #  + Variation_Selector
    // #  - White_Space
    // #  - FFF9..FFFB (Annotation Characters)
    // #  - Prepended_Concatenation_Mark (Exceptional format characters that should be visible)
    if (odi(cp) || gc(cp) == Gc::Cf || variation_selector(cp)) {
        if (!(white_space(cp)) && !(0xFFF9 <= cp && cp <= 0xFFFB) &&
            !(prepended_concatenation_mark(cp))) {
            return true;
        }
    }
    return false;
}

bool variation_selector(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");
    // From PropList.txt (Unicode 10.0.0)
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

bool white_space(uint32_t cp)
{
    auto found = ucd::wspace_table.find(CodePointRange(cp, cp));
    return (found != ucd::wspace_table.end()) ? true : false;
}

bool other_lowercase(uint32_t cp)
{
    auto found = ucd::olower_table.find(CodePointRange(cp, cp));
    return (found != ucd::olower_table.end()) ? true : false;
}

bool other_uppercase(uint32_t cp)
{
    auto found = ucd::oupper_table.find(CodePointRange(cp, cp));
    return (found != ucd::oupper_table.end()) ? true : false;
}

bool dash(uint32_t cp)
{
    auto found = ucd::dash_table.find(CodePointRange(cp, cp));
    return (found != ucd::dash_table.end()) ? true : false;
}

bool hyphen(uint32_t cp)
{
    auto found = ucd::hyphen_table.find(CodePointRange(cp, cp));
    return (found != ucd::hyphen_table.end()) ? true : false;
}

bool bidi_control(uint32_t cp)
{
    auto found = ucd::bidi_control_table.find(CodePointRange(cp, cp));
    return (found != ucd::bidi_control_table.end()) ? true : false;
}

bool join_control(uint32_t cp)
{
    auto found = ucd::join_control_table.find(CodePointRange(cp, cp));
    return (found != ucd::join_control_table.end()) ? true : false;
}

bool quotation_mark(uint32_t cp)
{
    auto found = ucd::qmark_table.find(CodePointRange(cp, cp));
    return (found != ucd::qmark_table.end()) ? true : false;
}

bool terminal_punctuation(uint32_t cp)
{
    auto found = ucd::term_table.find(CodePointRange(cp, cp));
    return (found != ucd::term_table.end()) ? true : false;
}

bool other_math(uint32_t cp)
{
    auto found = ucd::omath_table.find(CodePointRange(cp, cp));
    return (found != ucd::omath_table.end()) ? true : false;
}

bool hex_digit(uint32_t cp)
{
    auto found = ucd::hex_table.find(CodePointRange(cp, cp));
    return (found != ucd::hex_table.end()) ? true : false;
}

bool ascii_hex_digit(uint32_t cp)
{
    auto found = ucd::ahex_table.find(CodePointRange(cp, cp));
    return (found != ucd::ahex_table.end()) ? true : false;
}

bool oalpha(uint32_t cp)
{
    auto found = ucd::oalpha_table.find(CodePointRange(cp, cp));
    return (found != ucd::oalpha_table.end()) ? true : false;
}

bool ideographic(uint32_t cp)
{
    auto found = ucd::ideographic_table.find(CodePointRange(cp, cp));
    return (found != ucd::ideographic_table.end()) ? true : false;
}

bool diacritic(uint32_t cp)
{
    auto found = ucd::diacritic_table.find(CodePointRange(cp, cp));
    return (found != ucd::diacritic_table.end()) ? true : false;
}

bool extender(uint32_t cp)
{
    auto found = ucd::extender_table.find(CodePointRange(cp, cp));
    return (found != ucd::extender_table.end()) ? true : false;
}

bool math(uint32_t cp)
{
    static_assert(UnicodeVersion == (Version { 10, 0, 0 }), "Version error.");
    // From DerivedCoreProperties.txt (Unicode 10.0.0)
    // # Derived Property: Math
    // #  Generated from: Sm + Other_Math
    return gc(cp) == Gc::Sm || other_math(cp);
}

bool nchar(uint32_t cp)
{
    auto found = ucd::nchar_table.find(CodePointRange(cp, cp));
    return (found != ucd::nchar_table.end()) ? true : false;
}

bool ids_binary_operator(uint32_t cp)
{
    auto found = ucd::idsb_table.find(CodePointRange(cp, cp));
    return (found != ucd::idsb_table.end()) ? true : false;
}

bool ids_trinary_operator(uint32_t cp)
{
    auto found = ucd::idst_table.find(CodePointRange(cp, cp));
    return (found != ucd::idst_table.end()) ? true : false;
}

bool radical(uint32_t cp)
{
    auto found = ucd::radical_table.find(CodePointRange(cp, cp));
    return (found != ucd::radical_table.end()) ? true : false;
}

bool unified_ideograph(uint32_t cp)
{
    auto found = ucd::uideo_table.find(CodePointRange(cp, cp));
    return (found != ucd::uideo_table.end()) ? true : false;
}

bool deprecated(uint32_t cp)
{
    auto found = ucd::deprecated_table.find(CodePointRange(cp, cp));
    return (found != ucd::deprecated_table.end()) ? true : false;
}

bool soft_dotted(uint32_t cp)
{
    auto found = ucd::soft_dotted_table.find(CodePointRange(cp, cp));
    return (found != ucd::soft_dotted_table.end()) ? true : false;
}

bool logical_order_exception(uint32_t cp)
{
    auto found = ucd::loe_table.find(CodePointRange(cp, cp));
    return (found != ucd::loe_table.end()) ? true : false;
}

bool oids(uint32_t cp)
{
    auto found = ucd::oids_table.find(CodePointRange(cp, cp));
    return (found != ucd::oids_table.end()) ? true : false;
}

bool oidc(uint32_t cp)
{
    auto found = ucd::oidc_table.find(CodePointRange(cp, cp));
    return (found != ucd::oidc_table.end()) ? true : false;
}

bool sentence_terminal(uint32_t cp)
{
    auto found = ucd::sterm_table.find(CodePointRange(cp, cp));
    return (found != ucd::sterm_table.end()) ? true : false;
}

bool pattern_white_space(uint32_t cp)
{
    auto found = ucd::pat_ws_table.find(CodePointRange(cp, cp));
    return (found != ucd::pat_ws_table.end()) ? true : false;
}

bool pattern_syntax(uint32_t cp)
{
    auto found = ucd::pat_syn_table.find(CodePointRange(cp, cp));
    return (found != ucd::pat_syn_table.end()) ? true : false;
}

bool regional_indicator(uint32_t cp)
{
    auto found = ucd::ri_table.find(CodePointRange(cp, cp));
    return (found != ucd::ri_table.end()) ? true : false;
}

bool lowercase(uint32_t cp)
{
    // From DerivedCoreProperties.txt (Unicode 10.0.0)
    // # Derived Property: Lowercase
    // #  Generated from: Ll + Other_Lowercase
    if (gc(cp) == Gc::Ll || other_lowercase(cp))
        return true;
    return false;
}

bool uppercase(uint32_t cp)
{
    // From DerivedCoreProperties.txt (Unicode 10.0.0)
    // # Derived Property: Uppercase
    // #  Generated from: Lu + Other_Uppercase
    if (gc(cp) == Gc::Lu || other_uppercase(cp))
        return true;
    return false;
}

uint32_t simple_lowercase_mapping(uint32_t cp)
{
    auto found = ucd::slc_table.find(cp);
    if (found != ucd::slc_table.end())
        return found->second;
    return cp;
}

uint32_t simple_uppercase_mapping(uint32_t cp)
{
    auto found = ucd::suc_table.find(cp);
    if (found != ucd::suc_table.end())
        return found->second;
    return cp;
}

uint32_t simple_titlecase_mapping(uint32_t cp)
{
    auto found = ucd::stc_table.find(cp);
    if (found != ucd::stc_table.end())
        return found->second;
    return cp;
}

} // namespace ucd
} // namespace unicode
} // namespace seshat
