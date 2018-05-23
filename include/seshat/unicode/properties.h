//
//  unicode/properties.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 16:30
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Unicode properties enums and functions.
///
/// Currently not fully contains. It may split to or merge with other
/// property types.
#ifndef _UNICODE_PROPERTIES_H
#define _UNICODE_PROPERTIES_H

#include <seshat/codepoint.h>
#include <seshat/unicode/version.h> // struct Version (for age() function)
#include <seshat/utils.h>

#include <cstdint>

/// \enum   Gc
/// \brief  Unicode character property General_Category (gc).
SESHAT_UNICODE_PROPERTY_ENUM(Gc, uint8_t) {
// enum class Gc : uint8_t {
    // C - Other
    Cc, Cf, Cn, Co, Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    Ll, Lm, Lo, Lt, Lu,
    // M - Mark
    Mc, Me, Mn,
    // N - Number
    Nd, Nl, No,
    // P - Punctuation
    Pc, Pd, Pe, Pf, Pi, Po, Ps,
    // S - Symbol
    Sc, Sk, Sm, So,
    // Z - Separator
    Zl, Zp, Zs,
};
SESHAT_UNICODE_PROPERTY_ENUM_END

/// \enum   Dt
/// \brief  Unicode character property Decomposition_Type (dt).
///
/// Aliases from PropertyValueAliases.txt
SESHAT_UNICODE_PROPERTY_ENUM(Dt, uint8_t) {
// enum class Dt : uint8_t {
    Can,    // Canonical
    Com,    // Compat
    Enc,    // Circle
    Fin,    // Final
    Font,   // Font
    Fra,    // Fraction
    Init,   // Initial
    Iso,    // Isolated
    Med,    // Medial
    Nar,    // Narrow
    Nb,     // Nobreak
    None,   // None
    Sml,    // Small
    Sqr,    // Square
    Sub,    // Sub
    Sup,    // Super
    Vert,   // Vertical
    Wide    // Wide
};
SESHAT_UNICODE_PROPERTY_ENUM_END

/// \enum   Script
/// \brief  Unicode character property Script (sc).
SESHAT_UNICODE_PROPERTY_ENUM(Script, uint8_t) {
// enum class Script : uint8_t {
    Adlm, Aghb, // Adlam // Caucasian_Albanian
    Ahom, Arab, // Ahom // Arabic
    Armi, Armn, // Imperial_Aramaic // Armenian
    Avst, Bali, // Avestan // Balinese
    Bamu, Bass, // Bamum // Bassa_Vah
    Batk, Beng, // Batak // Bengali
    Bhks, Bopo, // Bhaiksuki // Bopomofo
    Brah, Brai, // Brahmi // Braille
    Bugi, Buhd, // Buginese // Buhid
    Cakm, Cans, // Chakma // Canadian_Aboriginal
    Cari, Cham, // Carian // Cham
    Cher, Copt, // Cherokee // Coptic ; Qaac
    Cprt, Cyrl, // Cypriot // Cyrillic
    Deva, Dsrt, // Devanagari // Deseret
    Dupl, Egyp, // Duployan // Egyptian_Hieroglyphs
    Elba, Ethi, // Elbasan // Ethiopic
    Geor, Glag, // Georgian // Glagolitic
    Goth, Gran, // Gothic // Grantha
    Grek, Gujr, // Greek // Gujarati
    Guru, Hang, // Gurmukhi // Hangul
    Hani, Hano, // Han // Hanunoo
    Hatr, Hebr, // Hatran // Hebrew
    Hira, Hluw, // Hiragana // Anatolian_Hieroglyphs
    Hmng, Hrkt, // Pahawh_Hmong // Katakana_Or_Hiragana
    Hung, Ital, // Old_Hungarian // Old_Italic
    Java, Kali, // Javanese // Kayah_Li
    Kana, Khar, // Katakana // Kharoshthi
    Khmr, Khoj, // Khmer // Khojki
    Knda, Kthi, // Kannada // Kaithi
    Lana, Laoo, // Tai_Tham // Lao
    Latn, Lepc, // Latin // Lepcha
    Limb, Lina, // Limbu // Linear_A
    Linb, Lisu, // Linear_B // Lisu
    Lyci, Lydi, // Lycian // Lydian
    Mahj, Mand, // Mahajani // Mandaic
    Mani, Marc, // Manichaean // Marchen
    Mend, Merc, // Mende_Kikakui // Meroitic_Cursive
    Mero, Mlym, // Meroitic_Hieroglyphs // Malayalam
    Modi, Mong, // Modi // Mongolian
    Mroo, Mtei, // Mro // Meetei_Mayek
    Mult, Mymr, // Multani // Myanmar
    Narb, Nbat, // Old_North_Arabian // Nabataean
    Newa, Nkoo, // Newa // Nko
    Ogam, Olck, // Ogham // Ol_Chiki
    Orkh, Orya, // Old_Turkic // Oriya
    Osge, Osma, // Osage // Osmanya
    Palm, Pauc, // Palmyrene // Pau_Cin_Hau
    Perm, Phag, // Old_Permic // Phags_Pa
    Phli, Phlp, // Inscriptional_Pahlavi // Psalter_Pahlavi
    Phnx, Plrd, // Phoenician // Miao
    Prti, Rjng, // Inscriptional_Parthian // Rejang
    Runr, Samr, // Runic // Samaritan
    Sarb, Saur, // Old_South_Arabian // Saurashtra
    Sgnw, Shaw, // SignWriting // Shavian
    Shrd, Sidd, // Sharada // Siddham
    Sind, Sinh, // Khudawadi // Sinhala
    Sora, Sund, // Sora_Sompeng // Sundanese
    Sylo, Syrc, // Syloti_Nagri // Syriac
    Tagb, Takr, // Tagbanwa // Takri
    Tale, Talu, // Tai_Le // New_Tai_Lue
    Taml, Tang, // Tamil // Tangut
    Tavt, Telu, // Tai_Viet // Telugu
    Tfng, Tglg, // Tifinagh // Tagalog
    Thaa, Thai, // Thaana // Thai
    Tibt, Tirh, // Tibetan // Tirhuta
    Ugar, Vaii, // Ugaritic // Vai
    Wara, Xpeo, // Warang_Citi // Old_Persian
    Xsux, Yiii, // Cuneiform // Yi
    // New in Unicode 10.0.0
    Gonm, // Masaram_Gondi
    Nshu, // Nushu
    Soyo, // Soyombo
    Zanb, // Zanabazar_Square
    // Other values
    Zinh, Zyyy, Zzzz // Inherited ; Qaai // Common // Unknown
};
SESHAT_UNICODE_PROPERTY_ENUM_END
namespace seshat {
namespace unicode {
static_assert(
    /* if */ (UnicodeVersion == (Version { 9, 0, 0 })) ?
        (static_cast<int>(Script::Zzzz) + 1 == 139)
    : /* else if */ (UnicodeVersion == (Version { 10, 0, 0 })) ?
        (static_cast<int>(Script::Zzzz) + 1 == 143)
    : /* else */
        false,
    "The number of Script property values do not match.");
}
}

/// \enum   Block
/// \brief  Unicode character property Block (blk).
SESHAT_UNICODE_PROPERTY_ENUM(Block, uint16_t) {
// enum class Block : uint16_t {
    // A
    Adlam, Aegean_Numbers, Ahom, Alchemical, Alphabetic_PF,
    Anatolian_Hieroglyphs,
    Ancient_Greek_Music, Ancient_Greek_Numbers, Ancient_Symbols,
    Arabic, Arabic_Ext_A, Arabic_Math, Arabic_PF_A, Arabic_PF_B, Arabic_Sup,
    Armenian, Arrows, ASCII, Avestan,
    // B
    Balinese,
    Bamum, Bamum_Sup,
    Bassa_Vah, Batak, Bengali, Bhaiksuki, Block_Elements,
    Bopomofo, Bopomofo_Ext,
    Box_Drawing, Brahmi, Braille, Buginese, Buhid, Byzantine_Music,
    // C
    Carian, Caucasian_Albanian, Chakma, Cham,
    Cherokee, Cherokee_Sup,
    CJK, CJK_Compat,
    CJK_Compat_Forms, CJK_Compat_Ideographs, CJK_Compat_Ideographs_Sup,
    CJK_Ext_A, CJK_Ext_B, CJK_Ext_C, CJK_Ext_D, CJK_Ext_E,
    CJK_Radicals_Sup, CJK_Strokes, CJK_Symbols,
    Compat_Jamo, Control_Pictures,
    Coptic, Coptic_Epact_Numbers,
    Counting_Rod,
    Cuneiform, Cuneiform_Numbers,
    Currency_Symbols, Cypriot_Syllabary,
    Cyrillic, Cyrillic_Ext_A, Cyrillic_Ext_B, Cyrillic_Ext_C, Cyrillic_Sup,
    // D
    Deseret,
    Devanagari, Devanagari_Ext,
    Diacriticals, Diacriticals_Ext, Diacriticals_For_Symbols, Diacriticals_Sup,
    Dingbats,
    Domino,
    Duployan,
    // E
    Early_Dynastic_Cuneiform,
    Egyptian_Hieroglyphs, Elbasan, Emoticons,
    Enclosed_Alphanum, Enclosed_Alphanum_Sup,
    Enclosed_CJK, Enclosed_Ideographic_Sup,
    Ethiopic, Ethiopic_Ext, Ethiopic_Ext_A, Ethiopic_Sup,
    // F
    // G
    Geometric_Shapes, Geometric_Shapes_Ext,
    Georgian, Georgian_Sup,
    Glagolitic, Glagolitic_Sup,
    Gothic, Grantha,
    Greek, Greek_Ext,
    Gujarati, Gurmukhi,
    // H
    Half_And_Full_Forms, Half_Marks, Hangul, Hanunoo, Hatran, Hebrew,
    High_PU_Surrogates,
    High_Surrogates,
    Hiragana,
    // I
    IDC,
    Ideographic_Symbols,
    Imperial_Aramaic,
    Indic_Number_Forms,
    Inscriptional_Pahlavi,
    Inscriptional_Parthian,
    IPA_Ext,
    // J
    Jamo, Jamo_Ext_A, Jamo_Ext_B,
    Javanese,
    // K
    Kaithi, Kana_Sup, Kanbun, Kangxi, Kannada,
    Katakana, Katakana_Ext,
    Kayah_Li, Kharoshthi,
    Khmer, Khmer_Symbols,
    Khojki, Khudawadi,
    // L
    Lao,
    Latin_1_Sup, Latin_Ext_A, Latin_Ext_Additional, Latin_Ext_B,
    Latin_Ext_C, Latin_Ext_D, Latin_Ext_E,
    Lepcha,
    Letterlike_Symbols,
    Limbu,
    Linear_A,
    Linear_B_Ideograms, Linear_B_Syllabary,
    Lisu,
    Low_Surrogates,
    Lycian, Lydian,
    // M
    Mahajani, Mahjong, Malayalam, Mandaic, Manichaean, Marchen,
    Math_Alphanum, Math_Operators,
    Meetei_Mayek, Meetei_Mayek_Ext,
    Mende_Kikakui,
    Meroitic_Cursive, Meroitic_Hieroglyphs,
    Miao,
    Misc_Arrows, Misc_Math_Symbols_A, Misc_Math_Symbols_B,
    Misc_Pictographs, Misc_Symbols, Misc_Technical,
    Modi,
    Modifier_Letters, Modifier_Tone_Letters,
    Mongolian, Mongolian_Sup,
    Mro, Multani, Music,
    Myanmar, Myanmar_Ext_A, Myanmar_Ext_B,
    // N
    Nabataean, New_Tai_Lue, Newa, NKo, Number_Forms,
    // O
    OCR,
    Ogham,
    Ol_Chiki, Old_Hungarian, Old_Italic, Old_North_Arabian, Old_Permic,
    Old_Persian, Old_South_Arabian, Old_Turkic,
    Oriya, Ornamental_Dingbats, Osage, Osmanya,
    // P
    Pahawh_Hmong, Palmyrene, Pau_Cin_Hau, Phags_Pa, Phaistos, Phoenician,
    Phonetic_Ext, Phonetic_Ext_Sup,
    Playing_Cards, Psalter_Pahlavi,
    PUA,
    Punctuation,
    // Q
    // R
    Rejang, Rumi, Runic,
    // S
    Samaritan, Saurashtra, Sharada, Shavian, Shorthand_Format_Controls,
    Siddham, Sinhala, Sinhala_Archaic_Numbers, Small_Forms, Sora_Sompeng,
    Specials,
    Sundanese, Sundanese_Sup,
    Sup_Arrows_A, Sup_Arrows_B, Sup_Arrows_C,
    Sup_Math_Operators,
    Sup_PUA_A, Sup_PUA_B,
    Sup_Punctuation,
    Sup_Symbols_And_Pictographs,
    Super_And_Sub, Sutton_SignWriting, Syloti_Nagri, Syriac,
    // T
    Tagalog, Tagbanwa, Tags,
    Tai_Le, Tai_Tham, Tai_Viet, Tai_Xuan_Jing,
    Takri, Tamil,
    Tangut, Tangut_Components,
    Telugu, Thaana, Thai, Tibetan, Tifinagh, Tirhuta, Transport_And_Map,
    // U
    UCAS, UCAS_Ext,
    Ugaritic,
    // V
    Vai, Vedic_Ext, Vertical_Forms,
    VS, VS_Sup,
    // W
    Warang_Citi,
    // X, Y, Z
    Yi_Radicals, Yi_Syllables,
    Yijing,
    // New in Unicode 10.0.0
    CJK_Ext_F,
    Kana_Ext_A,
    Masaram_Gondi,
    Nushu,
    Soyombo,
    Syriac_Sup,
    Zanabazar_Square,
    // Default value
    NB // None block
};
SESHAT_UNICODE_PROPERTY_ENUM_END
namespace seshat {
namespace unicode {
static_assert(
    /* if */ (UnicodeVersion == (Version { 9, 0, 0 })) ?
        (static_cast<int>(Block::NB) + 1 == 274)
    : /* else if */ (UnicodeVersion == (Version { 10, 0, 0 })) ?
        (static_cast<int>(Block::NB) + 1 == 281)
    : /* else */
        false,
    "The number of Block property values do not match.");
}
}

/// \enum   Gcb
/// \brief  Unicode character property Grapheme_Cluster_Break (GCB).
SESHAT_UNICODE_PROPERTY_ENUM(Gcb, uint8_t) {
// enum class Gcb : uint8_t {
    CN,     // Control
    CR,     // CR
    EB,     // E_Base
    EBG,    // E_Base_GAZ
    EM,     // E_Modifier
    EX,     // Extend
    GAZ,    // Glue_After_Zwj
    L,      // L
    LF,     // LF
    LV,     // LV
    LVT,    // LVT
    PP,     // Prepend
    RI,     // Regional_Indicator
    SM,     // SpacingMark
    T,      // T
    V,      // V
    XX,     // Other
    ZWJ     // ZWJ
};
SESHAT_UNICODE_PROPERTY_ENUM_END

/// \enum   Wb
/// \brief  Unicode character property Word_Break (WB).
SESHAT_UNICODE_PROPERTY_ENUM(Wb, uint8_t) {
// enum class Wb : uint8_t {
    CR,     // CR
    DQ,     // Double_Quote
    EB,     // E_Base
    EBG,    // E_Base_GAZ
    EM,     // E_Modifier
    EX,     // ExtendNumLet
    Extend, // Extend
    FO,     // Format
    GAZ,    // Glue_After_Zwj
    HL,     // Hebrew_Letter
    KA,     // Katakana
    LE,     // ALetter
    LF,     // LF
    MB,     // MidNumLet
    ML,     // MidLetter
    MN,     // MidNum
    NL,     // Newline
    NU,     // Numeric
    RI,     // Regional_Indicator
    SQ,     // Single_Quote
    XX,     // Other
    ZWJ     // ZWJ
};
SESHAT_UNICODE_PROPERTY_ENUM_END

namespace seshat {
namespace unicode {

/*
 * Property determining functions
 */

// ==============================
// Numeric Properties
// ==============================
//
// kAccountingNumeric (cjkAccountingNumeric)
// kOtherNumeric (cjkOtherNumeric)
// kPrimaryNumeric (cjkPrimaryNumeric)
// Numeric_Value (nv)

// ==============================
// String Properties
// ==============================
//
// Case_Folding (cf)
// kCompatibilityVariant (cjkCompatibilityVariant)
// ! Decomposition_Mapping (dm) - @dm.h
// FC_NFKC_Closure (FC_NFKC)
// ! Lowercase_Mapping (lc) - @casing.h
// NFKC_Casefold (NFKC_CF)
// Simple_Case_Folding  (scf) ; sfc
// Simple_Lowercase_Mapping (slc)
/// \brief  Get the Simple_Lowercase_Mapping property value.
///
/// If there is no mapping for the code point, it returns code point it self.
CodePoint simple_lowercase_mapping(CodePoint cp);
// Simple_Titlecase_Mapping (stc)
/// \brief  Get the Simple_Titlecase_Mapping property value.
///
/// If there is no mapping for the code point, it returns code point it self.
CodePoint simple_titlecase_mapping(CodePoint cp);
// Simple_Uppercase_Mapping (suc)
/// \brief  Get the Simple_Uppercase_Mapping property value.
///
/// If there is no mapping for the code point, it returns code point it self.
CodePoint simple_uppercase_mapping(CodePoint cp);
// ! Titlecase_Mapping (tc) - @casing.h
// ! Uppercase_Mapping (uc) - @casing.h

// ==============================
// Miscellaneous Properties
// ==============================
//
// Bidi_Mirroring_Glyph (bmg)
// Bidi_Paired_Bracket (bpb)
// kIICore (cjkIICore)
// kIRG_GSource (cjkIRG_GSource)
// kIRG_HSource (cjkIRG_HSource)
// kIRG_JSource (cjkIRG_JSource)
// kIRG_KPSource (cjkIRG_KPSource)
// kIRG_KSource (cjkIRG_KSource)
// kIRG_MSource (cjkIRG_MSource)
// kIRG_TSource (cjkIRG_TSource)
// kIRG_USource (cjkIRG_USource)
// kIRG_VSource (cjkIRG_VSource)
// kRSUnicode (cjkRSUnicode) ; Unicode_Radical_Stroke; URS
// ISO_Comment (isc)
// Jamo_Short_Name (JSN)
// ! Name (na) - @name.h
// Unicode_1_Name (na1)
// Name_Alias (Name_Alias)
// Script_Extensions (scx)

// ==============================
// Catalog Properties
// ==============================
//
// Age (age)
/// \brief  Get first assigned Unicode version.
///
/// Notes:
/// Version.update always 0.\n
/// Given code point for value Unassigned(NA) will returns
/// all 0 members. (== Version { 0, 0, 0 })
Version age(CodePoint cp);
// Block (blk)
/// \brief  Get the Block property value.
Block block(CodePoint cp);
// Script (sc)
/// \brief  Get the Script property value.
Script script(CodePoint cp);

// ==============================
// Enumerated Properties
// ==============================
//
// Bidi_Class (bc)
// Bidi_Paired_Bracket_Type (bpt)
// Canonical_Combining_Class (ccc)
/// \brief  Get the Canonical_Combining_Class (ccc) property value.
uint8_t ccc(CodePoint cp);
// Decomposition_Type (dt)
/// \brief  Get the Decomposition_Type (dt) property value.
Dt dt(CodePoint cp);
// East_Asian_Width (ea)
// General_Category (gc)
/// \brief  Get the General_Category (gc) property value.
Gc gc(CodePoint cp);
// Grapheme_Cluster_Break (GCB)
/// \brief  Get the Grapheme_Cluster_Break property value.
Gcb gcb(CodePoint cp);
// ! Hangul_Syllable_Type (hst) - @hangul.h
// Indic_Positional_Category (InPC)
// Indic_Syllabic_Category (InSC)
// Joining_Group (jg)
// Joining_Type (jt)
// Line_Break (lb)
// ! NFC_Quick_Check (NFC_QC) - @normalization_props.h
// ! NFD_Quick_Check (NFD_QC) - @normalization_props.h
// ! NFKC_Quick_Check (NFKC_QC) - @normalization_props.h
// ! NFKD_Quick_Check (NFKD_QC) - @normalization_props.h
// Numeric_Type (nt)
// Sentence_Break (SB)
// Word_Break (WB)
/// \brief  Get the Word_Break property value.
Wb wb(CodePoint cp);

// ==============================
// Binary Properties
// ==============================
//
// ASCII_Hex_Digit (AHex)
/// \brief  Get the ASCII_Hex_Digit (AHex) property value.
bool ascii_hex_digit(CodePoint cp);
// Alphabetic (Alpha)
/// \brief  Get the Alphabetic (Alpha) property value.
bool alphabetic(CodePoint cp);
// Bidi_Control (Bidi_C)
/// \brief  Get the Bidi_Control property value.
bool bidi_control(CodePoint cp);
// Bidi_Mirrored (Bidi_M)
// Cased (Cased)
/// \brief  Get the Cased property value.
bool cased(CodePoint cp);
// Composition_Exclusion (CE)
// ! Case_Ignorable (CI) - @casing.h
// ! Full_Composition_Exclusion (Comp_Ex) - @normalization_props.h
// Changes_When_Casefolded (CWCF)
// Changes_When_Casemapped (CWCM)
// Changes_When_NFKC_Casefolded (CWKCF)
// Changes_When_Lowercased (CWL)
// Changes_When_Titlecased (CWT)
// Changes_When_Uppercased (CWU)
// Dash (Dash)
/// \brief  Get the Dash property value.
bool dash(CodePoint cp);
// Deprecated (Dep)
/// \brief  Get the Deprecated (Dep) property value.
bool deprecated(CodePoint cp);
// Default_Ignorable_Code_Point (DI)
/// \brief  Get the Default_Ignorable_Code_Point property value.
bool default_ignorable_code_point(CodePoint cp);
// Diacritic (Dia)
/// \brief  Get the Diacritic (Dia) property value.
bool diacritic(CodePoint cp);
// Extender (Ext)
/// \brief  Get the Extender (Ext) property value.
bool extender(CodePoint cp);
// Grapheme_Base (Gr_Base)
// Grapheme_Extend (Gr_Ext)
/// \brief  Get the Grapheme_Extend property value.
bool grapheme_extend(CodePoint cp);
// Grapheme_Link (Gr_Link)
// Hex_Digit (Hex)
/// \brief  Get the Hex_Digit (Hex) property value.
bool hex_digit(CodePoint cp);
// Hyphen (Hyphen)
/// \brief  Get the Hyphen property value.
bool hyphen(CodePoint cp);
// ID_Continue (IDC)
/// \brief  Get the ID_Continue (IDC) property value.
bool id_continue(CodePoint cp);
// Ideographic (Ideo)
/// \brief  Get the Ideographic (Ideo) property value.
bool ideographic(CodePoint cp);
// ID_Start (IDS)
/// \brief  Get the ID_Start (IDS) property value.
bool id_start(CodePoint cp);
// IDS_Binary_Operator (IDSB)
/// \brief  Get the IDS_Binary_Operator (IDSB) property value.
bool ids_binary_operator(CodePoint cp);
// IDS_Trinary_Operator (IDST)
/// \brief  Get the IDS_Trinary_Operator (IDST) property value.
bool ids_trinary_operator(CodePoint cp);
// Join_Control (Join_C)
/// \brief  Get the Join_Control (Join_C) property value.
bool join_control(CodePoint cp);
// Logical_Order_Exception (LOE)
/// \brief  Get the Logical_Order_Exception (LOE) property value.
bool logical_order_exception(CodePoint cp);
// Lowercase (Lower)
/// \brief  Get the Lowercase (Lower) property value.
bool lowercase(CodePoint cp);
// Math (Math)
/// \brief  Get the Math property value.
bool math(CodePoint cp);
// Noncharacter_Code_Point (NChar)
/// \brief  Get the Noncharacter_Code_Point (NChar) property value.
bool nchar(CodePoint cp);
// Other_Alphabetic (OAlpha)
/// \brief  Get the Other_Alphabetic (OAlpha) property value.
bool oalpha(CodePoint cp);
// Other_Default_Ignorable_Code_Point (ODI)
/// \brief  Get the Other_Default_Ignorable_Code_Point property value.
bool odi(CodePoint cp);
// Other_Grapheme_Extend (OGr_Ext)
/// \brief  Get the Other_Grapheme_Extend property value.
bool ogr_ext(CodePoint cp);
// Other_ID_Continue (OIDC)
/// \brief  Get the Other_ID_Continue (OIDC) property value.
bool oidc(CodePoint cp);
// Other_ID_Start (OIDS)
/// \brief  Get the Other_ID_Start (OIDS) property value.
bool oids(CodePoint cp);
// Other_Lowercase (OLower)
/// \brief  Get the Other_Lowercase (OLower) property value.
bool other_lowercase(CodePoint cp);
// Other_Math (OMath)
/// \brief  Get the Other_Math (OMath) property value.
bool other_math(CodePoint cp);
// Other_Uppercase (OUpper)
/// \brief  Get the Other_Uppercase (OUpper) property value.
bool other_uppercase(CodePoint cp);
// Pattern_Syntax (Pat_Syn)
/// \brief  Get the Pattern_Syntax (Pat_Syn) property value.
bool pattern_syntax(CodePoint cp);
// Pattern_White_Space (Pat_WS)
/// \brief  Get the Pattern_White_Space (Pat_WS) property value.
bool pattern_white_space(CodePoint cp);
// Prepended_Concatenation_Mark (PCM)
/// \brief  Get the Prepended_Concatenation_Mark property value.
bool prepended_concatenation_mark(CodePoint cp);
// Quotation_Mark (QMark)
/// \brief  Get the Quotation_Mark (QMark) property value.
bool quotation_mark(CodePoint cp);
// Regional_Indicator (RI)
/// \brief  Get the Regional_Indicator (RI) property value.
bool regional_indicator(CodePoint cp);
// Radical (Radical)
/// \brief  Get the Radical property value.
bool radical(CodePoint cp);
// Soft_Dotted (SD)
/// \brief  Get the Soft_Dotted (SD) property value.
bool soft_dotted(CodePoint cp);
// Sentence_Terminal (STerm)
/// \brief  Get the Sentence_Terminal (STerm) property value.
bool sentence_terminal(CodePoint cp);
// Terminal_Punctuation (Term)
/// \brief  Get the Terminal_Punctuation (Term) property value.
bool terminal_punctuation(CodePoint cp);
// Unified_Ideograph (UIdeo)
/// \brief  Get the Unified_Ideograph (UIdeo) property value.
bool unified_ideograph(CodePoint cp);
// Uppercase (Upper)
/// \brief  Get the Uppercase (Upper) property value.
bool uppercase(CodePoint cp);
// Variation_Selector (VS)
/// \brief  Get the Variation_Selector (VS) property value.
bool variation_selector(CodePoint cp);
// White_Space (WSpace) ; space
/// \brief  Get the White_Space (WSpace) property value.
bool white_space(CodePoint cp);
// XID_Continue (XIDC)
// XID_Start (XIDS)
// Expands_On_NFC (XO_NFC)
// Expands_On_NFD (XO_NFD)
// Expands_On_NFKC (XO_NFKC)
// Expands_On_NFKD (XO_NFKD)

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_PROPERTIES_H */
