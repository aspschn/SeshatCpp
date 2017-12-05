/*
//  icu/properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 23. 19:35
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include "properties.h"

#ifdef SESHAT_ICU_BACKEND
#include "unicode/uchar.h"
namespace seshat {
namespace unicode {
namespace icu {

Version age(uint32_t cp)
{
    UVersionInfo ver;
    u_charAge(static_cast<UChar32>(cp), ver);
    return Version { ver[0], ver[1], ver[2] };
}

Block block(uint32_t cp)
{
    switch (ublock_getCode(static_cast<UChar32>(cp))) {
    case UBLOCK_BASIC_LATIN: return Block::ASCII;
    case UBLOCK_LATIN_1_SUPPLEMENT: return Block::Latin_1_Sup;
    case UBLOCK_LATIN_EXTENDED_A: return Block::Latin_Ext_A;
    case UBLOCK_LATIN_EXTENDED_B: return Block::Latin_Ext_B;
    case UBLOCK_IPA_EXTENSIONS: return Block::IPA_Ext;
    case UBLOCK_SPACING_MODIFIER_LETTERS: return Block::Modifier_Letters;
    case UBLOCK_COMBINING_DIACRITICAL_MARKS: return Block::Diacriticals;
    case UBLOCK_GREEK: return Block::Greek;
    case UBLOCK_CYRILLIC: return Block::Cyrillic;
    case UBLOCK_ARMENIAN: return Block::Armenian;
    case UBLOCK_HEBREW: return Block::Hebrew;
    case UBLOCK_ARABIC: return Block::Arabic;
    case UBLOCK_SYRIAC: return Block::Syriac;
    case UBLOCK_THAANA: return Block::Thaana;
    case UBLOCK_DEVANAGARI: return Block::Devanagari;
    case UBLOCK_BENGALI: return Block::Bengali;
    case UBLOCK_GURMUKHI: return Block::Gurmukhi;
    case UBLOCK_GUJARATI: return Block::Gujarati;
    case UBLOCK_ORIYA: return Block::Oriya;
    case UBLOCK_TAMIL: return Block::Tamil;
    case UBLOCK_TELUGU: return Block::Telugu;
    case UBLOCK_KANNADA: return Block::Kannada;
    case UBLOCK_MALAYALAM: return Block::Malayalam;
    case UBLOCK_SINHALA: return Block::Sinhala;
    case UBLOCK_THAI: return Block::Thai;
    case UBLOCK_LAO: return Block::Lao;
    case UBLOCK_TIBETAN: return Block::Tibetan;
    case UBLOCK_MYANMAR: return Block::Myanmar;
    case UBLOCK_GEORGIAN: return Block::Georgian;
    case UBLOCK_HANGUL_JAMO: return Block::Jamo;
    case UBLOCK_ETHIOPIC: return Block::Ethiopic;
    case UBLOCK_CHEROKEE: return Block::Cherokee;
    case UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS: return Block::UCAS;
    case UBLOCK_OGHAM: return Block::Ogham;
    case UBLOCK_RUNIC: return Block::Runic;
    case UBLOCK_KHMER: return Block::Khmer;
    case UBLOCK_MONGOLIAN: return Block::Mongolian;
    case UBLOCK_LATIN_EXTENDED_ADDITIONAL: return Block::Latin_Ext_Additional;
    case UBLOCK_GREEK_EXTENDED: return Block::Greek_Ext;
    case UBLOCK_GENERAL_PUNCTUATION: return Block::Punctuation;
    case UBLOCK_SUPERSCRIPTS_AND_SUBSCRIPTS: return Block::Super_And_Sub;
    case UBLOCK_CURRENCY_SYMBOLS: return Block::Currency_Symbols;
    case UBLOCK_COMBINING_MARKS_FOR_SYMBOLS: return Block::Diacriticals_For_Symbols;
    case UBLOCK_LETTERLIKE_SYMBOLS: return Block::Letterlike_Symbols;
    case UBLOCK_NUMBER_FORMS: return Block::Number_Forms;
    case UBLOCK_ARROWS: return Block::Arrows;
    case UBLOCK_MATHEMATICAL_OPERATORS: return Block::Math_Operators;
    case UBLOCK_MISCELLANEOUS_TECHNICAL: return Block::Misc_Technical;
    case UBLOCK_CONTROL_PICTURES: return Block::Control_Pictures;
    case UBLOCK_OPTICAL_CHARACTER_RECOGNITION: return Block::OCR;
    case UBLOCK_ENCLOSED_ALPHANUMERICS: return Block::Enclosed_Alphanum;
    case UBLOCK_BOX_DRAWING: return Block::Box_Drawing;
    case UBLOCK_BLOCK_ELEMENTS: return Block::Block_Elements;
    case UBLOCK_GEOMETRIC_SHAPES: return Block::Geometric_Shapes;
    case UBLOCK_MISCELLANEOUS_SYMBOLS: return Block::Misc_Symbols;
    case UBLOCK_DINGBATS: return Block::Dingbats;
    case UBLOCK_BRAILLE_PATTERNS: return Block::Braille;
    case UBLOCK_CJK_RADICALS_SUPPLEMENT: return Block::CJK_Radicals_Sup;
    case UBLOCK_KANGXI_RADICALS: return Block::Kangxi;
    case UBLOCK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS: return Block::IDC;
    case UBLOCK_CJK_SYMBOLS_AND_PUNCTUATION: return Block::CJK_Symbols;
    case UBLOCK_HIRAGANA: return Block::Hiragana;
    case UBLOCK_KATAKANA: return Block::Katakana;
    case UBLOCK_BOPOMOFO: return Block::Bopomofo;
    case UBLOCK_HANGUL_COMPATIBILITY_JAMO: return Block::Compat_Jamo;
    case UBLOCK_KANBUN: return Block::Kanbun;
    case UBLOCK_BOPOMOFO_EXTENDED: return Block::Bopomofo_Ext;
    case UBLOCK_ENCLOSED_CJK_LETTERS_AND_MONTHS: return Block::Enclosed_CJK;
    case UBLOCK_CJK_COMPATIBILITY: return Block::CJK_Compat;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A: return Block::CJK_Ext_A;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS: return Block::CJK;
    case UBLOCK_YI_SYLLABLES: return Block::Yi_Syllables;
    case UBLOCK_YI_RADICALS: return Block::Yi_Radicals;
    case UBLOCK_HANGUL_SYLLABLES: return Block::Hangul;
    case UBLOCK_HIGH_SURROGATES: return Block::High_Surrogates;
    case UBLOCK_HIGH_PRIVATE_USE_SURROGATES: return Block::High_PU_Surrogates;
    case UBLOCK_LOW_SURROGATES: return Block::Low_Surrogates;
    case UBLOCK_PRIVATE_USE_AREA: return Block::PUA;
    // case UBLOCK_PRIVATE_USE: return Block::PUA;
    case UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS: return Block::CJK_Compat_Ideographs;
    case UBLOCK_ALPHABETIC_PRESENTATION_FORMS: return Block::Alphabetic_PF;
    case UBLOCK_ARABIC_PRESENTATION_FORMS_A: return Block::Arabic_PF_A;
    case UBLOCK_COMBINING_HALF_MARKS: return Block::Half_Marks;
    case UBLOCK_CJK_COMPATIBILITY_FORMS: return Block::CJK_Compat_Forms;
    case UBLOCK_SMALL_FORM_VARIANTS: return Block::Small_Forms;
    case UBLOCK_ARABIC_PRESENTATION_FORMS_B: return Block::Arabic_PF_B;
    case UBLOCK_SPECIALS: return Block::Specials;
    case UBLOCK_HALFWIDTH_AND_FULLWIDTH_FORMS: return Block::Half_And_Full_Forms;
    case UBLOCK_OLD_ITALIC: return Block::Old_Italic;
    case UBLOCK_GOTHIC: return Block::Gothic;
    case UBLOCK_DESERET: return Block::Deseret;
    case UBLOCK_BYZANTINE_MUSICAL_SYMBOLS: return Block::Byzantine_Music;
    case UBLOCK_MUSICAL_SYMBOLS: return Block::Music;
    case UBLOCK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS: return Block::Math_Alphanum;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B: return Block::CJK_Ext_B;
    case UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT: return Block::CJK_Compat_Ideographs_Sup;
    case UBLOCK_TAGS: return Block::Tags;
    case UBLOCK_CYRILLIC_SUPPLEMENT: return Block::Cyrillic_Sup;
    // case UBLOCK_CYRILLIC_SUPPLEMENTARY: return Block::Cyrillic_Sup;
    case UBLOCK_TAGALOG: return Block::Tagalog;
    case UBLOCK_HANUNOO: return Block::Hanunoo;
    case UBLOCK_BUHID: return Block::Buhid;
    case UBLOCK_TAGBANWA: return Block::Tagbanwa;
    case UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A: return Block::Misc_Math_Symbols_A;
    case UBLOCK_SUPPLEMENTAL_ARROWS_A: return Block::Sup_Arrows_A;
    case UBLOCK_SUPPLEMENTAL_ARROWS_B: return Block::Sup_Arrows_B;
    case UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B: return Block::Misc_Math_Symbols_B;
    case UBLOCK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS: return Block::Sup_Math_Operators;
    case UBLOCK_KATAKANA_PHONETIC_EXTENSIONS: return Block::Katakana_Ext;
    case UBLOCK_VARIATION_SELECTORS: return Block::VS;
    case UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_A: return Block::Sup_PUA_A;
    case UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_B: return Block::Sup_PUA_B;
    case UBLOCK_LIMBU: return Block::Limbu;
    case UBLOCK_TAI_LE: return Block::Tai_Le;
    case UBLOCK_KHMER_SYMBOLS: return Block::Khmer_Symbols;
    case UBLOCK_PHONETIC_EXTENSIONS: return Block::Phonetic_Ext;
    case UBLOCK_MISCELLANEOUS_SYMBOLS_AND_ARROWS: return Block::Misc_Arrows;
    case UBLOCK_YIJING_HEXAGRAM_SYMBOLS: return Block::Yijing;
    case UBLOCK_LINEAR_B_SYLLABARY: return Block::Linear_B_Syllabary;
    case UBLOCK_LINEAR_B_IDEOGRAMS: return Block::Linear_B_Ideograms;
    case UBLOCK_AEGEAN_NUMBERS: return Block::Aegean_Numbers;
    case UBLOCK_UGARITIC: return Block::Ugaritic;
    case UBLOCK_SHAVIAN: return Block::Shavian;
    case UBLOCK_OSMANYA: return Block::Osmanya;
    case UBLOCK_CYPRIOT_SYLLABARY: return Block::Cypriot_Syllabary;
    case UBLOCK_TAI_XUAN_JING_SYMBOLS: return Block::Tai_Xuan_Jing;
    case UBLOCK_VARIATION_SELECTORS_SUPPLEMENT: return Block::VS_Sup;
    case UBLOCK_ANCIENT_GREEK_MUSICAL_NOTATION: return Block::Ancient_Greek_Music;
    case UBLOCK_ANCIENT_GREEK_NUMBERS: return Block::Ancient_Greek_Numbers;
    case UBLOCK_ARABIC_SUPPLEMENT: return Block::Arabic_Sup;
    case UBLOCK_BUGINESE: return Block::Buginese;
    case UBLOCK_CJK_STROKES: return Block::CJK_Strokes;
    case UBLOCK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT: return Block::Diacriticals_Sup;
    case UBLOCK_COPTIC: return Block::Coptic;
    case UBLOCK_ETHIOPIC_EXTENDED: return Block::Ethiopic_Ext;
    case UBLOCK_ETHIOPIC_SUPPLEMENT: return Block::Ethiopic_Sup;
    case UBLOCK_GEORGIAN_SUPPLEMENT: return Block::Georgian_Sup;
    case UBLOCK_GLAGOLITIC: return Block::Glagolitic;
    case UBLOCK_KHAROSHTHI: return Block::Kharoshthi;
    case UBLOCK_MODIFIER_TONE_LETTERS: return Block::Modifier_Tone_Letters;
    case UBLOCK_NEW_TAI_LUE: return Block::New_Tai_Lue;
    case UBLOCK_OLD_PERSIAN: return Block::Old_Persian;
    case UBLOCK_PHONETIC_EXTENSIONS_SUPPLEMENT: return Block::Phonetic_Ext_Sup;
    case UBLOCK_SUPPLEMENTAL_PUNCTUATION: return Block::Sup_Punctuation;
    case UBLOCK_SYLOTI_NAGRI: return Block::Syloti_Nagri;
    case UBLOCK_TIFINAGH: return Block::Tifinagh;
    case UBLOCK_VERTICAL_FORMS: return Block::Vertical_Forms;
    case UBLOCK_NKO: return Block::NKo;
    case UBLOCK_BALINESE: return Block::Balinese;
    case UBLOCK_LATIN_EXTENDED_C: return Block::Latin_Ext_C;
    case UBLOCK_LATIN_EXTENDED_D: return Block::Latin_Ext_D;
    case UBLOCK_PHAGS_PA: return Block::Phags_Pa;
    case UBLOCK_PHOENICIAN: return Block::Phoenician;
    case UBLOCK_CUNEIFORM: return Block::Cuneiform;
    case UBLOCK_CUNEIFORM_NUMBERS_AND_PUNCTUATION: return Block::Cuneiform_Numbers;
    case UBLOCK_COUNTING_ROD_NUMERALS: return Block::Counting_Rod;
    case UBLOCK_SUNDANESE: return Block::Sundanese;
    case UBLOCK_LEPCHA: return Block::Lepcha;
    case UBLOCK_OL_CHIKI: return Block::Ol_Chiki;
    case UBLOCK_CYRILLIC_EXTENDED_A: return Block::Cyrillic_Ext_A;
    case UBLOCK_VAI: return Block::Vai;
    case UBLOCK_CYRILLIC_EXTENDED_B: return Block::Cyrillic_Ext_B;
    case UBLOCK_SAURASHTRA: return Block::Saurashtra;
    case UBLOCK_KAYAH_LI: return Block::Kayah_Li;
    case UBLOCK_REJANG: return Block::Rejang;
    case UBLOCK_CHAM: return Block::Cham;
    case UBLOCK_ANCIENT_SYMBOLS: return Block::Ancient_Symbols;
    case UBLOCK_PHAISTOS_DISC: return Block::Phaistos;
    case UBLOCK_LYCIAN: return Block::Lycian;
    case UBLOCK_CARIAN: return Block::Carian;
    case UBLOCK_LYDIAN: return Block::Lydian;
    case UBLOCK_MAHJONG_TILES: return Block::Mahjong;
    case UBLOCK_DOMINO_TILES: return Block::Domino;
    case UBLOCK_SAMARITAN: return Block::Samaritan;
    case UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED: return Block::UCAS_Ext;
    case UBLOCK_TAI_THAM: return Block::Tai_Tham;
    case UBLOCK_VEDIC_EXTENSIONS: return Block::Vedic_Ext;
    case UBLOCK_LISU: return Block::Lisu;
    case UBLOCK_BAMUM: return Block::Bamum;
    case UBLOCK_COMMON_INDIC_NUMBER_FORMS: return Block::Indic_Number_Forms;
    case UBLOCK_DEVANAGARI_EXTENDED: return Block::Devanagari_Ext;
    case UBLOCK_HANGUL_JAMO_EXTENDED_A: return Block::Jamo_Ext_A;
    case UBLOCK_JAVANESE: return Block::Javanese;
    case UBLOCK_MYANMAR_EXTENDED_A: return Block::Myanmar_Ext_A;
    case UBLOCK_TAI_VIET: return Block::Tai_Viet;
    case UBLOCK_MEETEI_MAYEK: return Block::Meetei_Mayek;
    case UBLOCK_HANGUL_JAMO_EXTENDED_B: return Block::Jamo_Ext_B;
    case UBLOCK_IMPERIAL_ARAMAIC: return Block::Imperial_Aramaic;
    case UBLOCK_OLD_SOUTH_ARABIAN: return Block::Old_South_Arabian;
    case UBLOCK_AVESTAN: return Block::Avestan;
    case UBLOCK_INSCRIPTIONAL_PARTHIAN: return Block::Inscriptional_Parthian;
    case UBLOCK_INSCRIPTIONAL_PAHLAVI: return Block::Inscriptional_Pahlavi;
    case UBLOCK_OLD_TURKIC: return Block::Old_Turkic;
    case UBLOCK_RUMI_NUMERAL_SYMBOLS: return Block::Rumi;
    case UBLOCK_KAITHI: return Block::Kaithi;
    case UBLOCK_EGYPTIAN_HIEROGLYPHS: return Block::Egyptian_Hieroglyphs;
    case UBLOCK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT: return Block::Enclosed_Alphanum_Sup;
    case UBLOCK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT: return Block::Enclosed_Ideographic_Sup;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C: return Block::CJK_Ext_C;
    case UBLOCK_MANDAIC: return Block::Mandaic;
    case UBLOCK_BATAK: return Block::Batak;
    case UBLOCK_ETHIOPIC_EXTENDED_A: return Block::Ethiopic_Ext_A;
    case UBLOCK_BRAHMI: return Block::Brahmi;
    case UBLOCK_BAMUM_SUPPLEMENT: return Block::Bamum_Sup;
    case UBLOCK_KANA_SUPPLEMENT: return Block::Kana_Sup;
    case UBLOCK_PLAYING_CARDS: return Block::Playing_Cards;
    case UBLOCK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS: return Block::Misc_Pictographs;
    case UBLOCK_EMOTICONS: return Block::Emoticons;
    case UBLOCK_TRANSPORT_AND_MAP_SYMBOLS: return Block::Transport_And_Map;
    case UBLOCK_ALCHEMICAL_SYMBOLS: return Block::Alchemical;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D: return Block::CJK_Ext_D;
    case UBLOCK_ARABIC_EXTENDED_A: return Block::Arabic_Ext_A;
    case UBLOCK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS: return Block::Arabic_Math;
    case UBLOCK_CHAKMA: return Block::Chakma;
    case UBLOCK_MEETEI_MAYEK_EXTENSIONS: return Block::Meetei_Mayek_Ext;
    case UBLOCK_MEROITIC_CURSIVE: return Block::Meroitic_Cursive;
    case UBLOCK_MEROITIC_HIEROGLYPHS: return Block::Meroitic_Hieroglyphs;
    case UBLOCK_MIAO: return Block::Miao;
    case UBLOCK_SHARADA: return Block::Sharada;
    case UBLOCK_SORA_SOMPENG: return Block::Sora_Sompeng;
    case UBLOCK_SUNDANESE_SUPPLEMENT: return Block::Sundanese_Sup;
    case UBLOCK_TAKRI: return Block::Takri;
    case UBLOCK_BASSA_VAH: return Block::Bassa_Vah;
    case UBLOCK_CAUCASIAN_ALBANIAN: return Block::Caucasian_Albanian;
    case UBLOCK_COPTIC_EPACT_NUMBERS: return Block::Coptic_Epact_Numbers;
    case UBLOCK_COMBINING_DIACRITICAL_MARKS_EXTENDED: return Block::Diacriticals_Ext;
    case UBLOCK_DUPLOYAN: return Block::Duployan;
    case UBLOCK_ELBASAN: return Block::Elbasan;
    case UBLOCK_GEOMETRIC_SHAPES_EXTENDED: return Block::Geometric_Shapes_Ext;
    case UBLOCK_GRANTHA: return Block::Grantha;
    case UBLOCK_KHOJKI: return Block::Khojki;
    case UBLOCK_KHUDAWADI: return Block::Khudawadi;
    case UBLOCK_LATIN_EXTENDED_E: return Block::Latin_Ext_E;
    case UBLOCK_LINEAR_A: return Block::Linear_A;
    case UBLOCK_MAHAJANI: return Block::Mahajani;
    case UBLOCK_MANICHAEAN: return Block::Manichaean;
    case UBLOCK_MENDE_KIKAKUI: return Block::Mende_Kikakui;
    case UBLOCK_MODI: return Block::Modi;
    case UBLOCK_MRO: return Block::Mro;
    case UBLOCK_MYANMAR_EXTENDED_B: return Block::Myanmar_Ext_B;
    case UBLOCK_NABATAEAN: return Block::Nabataean;
    case UBLOCK_OLD_NORTH_ARABIAN: return Block::Old_North_Arabian;
    case UBLOCK_OLD_PERMIC: return Block::Old_Permic;
    case UBLOCK_ORNAMENTAL_DINGBATS: return Block::Ornamental_Dingbats;
    case UBLOCK_PAHAWH_HMONG: return Block::Pahawh_Hmong;
    case UBLOCK_PALMYRENE: return Block::Palmyrene;
    case UBLOCK_PAU_CIN_HAU: return Block::Pau_Cin_Hau;
    case UBLOCK_PSALTER_PAHLAVI: return Block::Psalter_Pahlavi;
    case UBLOCK_SHORTHAND_FORMAT_CONTROLS: return Block::Shorthand_Format_Controls;
    case UBLOCK_SIDDHAM: return Block::Siddham;
    case UBLOCK_SINHALA_ARCHAIC_NUMBERS: return Block::Sinhala_Archaic_Numbers;
    case UBLOCK_SUPPLEMENTAL_ARROWS_C: return Block::Sup_Arrows_C;
    case UBLOCK_TIRHUTA: return Block::Tirhuta;
    case UBLOCK_WARANG_CITI: return Block::Warang_Citi;
    case UBLOCK_AHOM: return Block::Ahom;
    case UBLOCK_ANATOLIAN_HIEROGLYPHS: return Block::Anatolian_Hieroglyphs;
    case UBLOCK_CHEROKEE_SUPPLEMENT: return Block::Cherokee_Sup;
    case UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E: return Block::CJK_Ext_E;
    case UBLOCK_EARLY_DYNASTIC_CUNEIFORM: return Block::Early_Dynastic_Cuneiform;
    case UBLOCK_HATRAN: return Block::Hatran;
    case UBLOCK_MULTANI: return Block::Multani;
    case UBLOCK_OLD_HUNGARIAN: return Block::Old_Hungarian;
    case UBLOCK_SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS: return Block::Sup_Symbols_And_Pictographs;
    case UBLOCK_SUTTON_SIGNWRITING: return Block::Sutton_SignWriting;
    case UBLOCK_ADLAM: return Block::Adlam;
    case UBLOCK_BHAIKSUKI: return Block::Bhaiksuki;
    case UBLOCK_CYRILLIC_EXTENDED_C: return Block::Cyrillic_Ext_C;
    case UBLOCK_GLAGOLITIC_SUPPLEMENT: return Block::Glagolitic_Sup;
    case UBLOCK_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION: return Block::Ideographic_Symbols;
    case UBLOCK_MARCHEN: return Block::Marchen;
    case UBLOCK_MONGOLIAN_SUPPLEMENT: return Block::Mongolian_Sup;
    case UBLOCK_NEWA: return Block::Newa;
    case UBLOCK_OSAGE: return Block::Osage;
    case UBLOCK_TANGUT: return Block::Tangut;
    case UBLOCK_TANGUT_COMPONENTS: return Block::Tangut_Components;
    case UBLOCK_NO_BLOCK:
    default:
        return Block::NB;
    }
}

uint8_t ccc(uint32_t cp)
{
    return u_getCombiningClass(static_cast<UChar32>(cp));
}

Dt dt(uint32_t cp)
{
    int32_t icu_int_value = u_getIntPropertyValue(static_cast<UChar32>(cp),
        UCHAR_DECOMPOSITION_TYPE);
    switch (icu_int_value) {
    case U_DT_CANONICAL: return Dt::Can;
    case U_DT_COMPAT: return Dt::Com;
    case U_DT_CIRCLE: return Dt::Enc;
    case U_DT_FINAL: return Dt::Fin;
    case U_DT_FONT: return Dt::Font;
    case U_DT_FRACTION: return Dt::Fra;
    case U_DT_INITIAL: return Dt::Init;
    case U_DT_ISOLATED: return Dt::Iso;
    case U_DT_MEDIAL: return Dt::Med;
    case U_DT_NARROW: return Dt::Nar;
    case U_DT_NOBREAK: return Dt::Nb;
    case U_DT_SMALL: return Dt::Sml;
    case U_DT_SQUARE: return Dt::Sqr;
    case U_DT_SUB: return Dt::Sub;
    case U_DT_SUPER: return Dt::Sup;
    case U_DT_VERTICAL: return Dt::Vert;
    case U_DT_WIDE: return Dt::Wide;
    case U_DT_NONE:
    default:
        return Dt::None;
    }
}

Gc gc(uint32_t cp)
{
    switch (static_cast<UChar32>(cp)) {
    case U_UPPERCASE_LETTER: return Gc::Lu;
    case U_LOWERCASE_LETTER: return Gc::Ll;
    case U_TITLECASE_LETTER: return Gc::Lt;
    case U_MODIFIER_LETTER: return Gc::Lm;
    case U_OTHER_LETTER: return Gc::Lo;
    case U_NON_SPACING_MARK: return Gc::Mn;
    case U_ENCLOSING_MARK: return Gc::Me;
    case U_COMBINING_SPACING_MARK: return Gc::Mc;
    case U_DECIMAL_DIGIT_NUMBER: return Gc::Nd;
    case U_LETTER_NUMBER: return Gc::Nl;
    case U_OTHER_NUMBER: return Gc::No;
    case U_SPACE_SEPARATOR: return Gc::Zs;
    case U_LINE_SEPARATOR: return Gc::Zl;
    case U_PARAGRAPH_SEPARATOR: return Gc::Zp;
    case U_CONTROL_CHAR: return Gc::Cc;
    case U_FORMAT_CHAR: return Gc::Cf;
    case U_PRIVATE_USE_CHAR: return Gc::Co;
    case U_SURROGATE: return Gc::Cs;
    case U_DASH_PUNCTUATION: return Gc::Pd;
    case U_START_PUNCTUATION: return Gc::Ps;
    case U_END_PUNCTUATION: return Gc::Pe;
    case U_CONNECTOR_PUNCTUATION: return Gc::Pc;
    case U_OTHER_PUNCTUATION: return Gc::Po;
    case U_MATH_SYMBOL: return Gc::Sm;
    case U_CURRENCY_SYMBOL: return Gc::Sc;
    case U_MODIFIER_SYMBOL: return Gc::Sk;
    case U_OTHER_SYMBOL: return Gc::So;
    case U_INITIAL_PUNCTUATION: return Gc::Pi;
    case U_FINAL_PUNCTUATION: return Gc::Pf;
    case U_UNASSIGNED:
    // case U_GENERAL_OTHER_TYPES:
    default:
        return Gc::Cn;
    }
}

Gcb gcb(uint32_t cp)
{
    int32_t icu_int_value = u_getIntPropertyValue(static_cast<UChar32>(cp),
        UCHAR_GRAPHEME_CLUSTER_BREAK);
    switch (icu_int_value) {
    case U_GCB_CONTROL: return Gcb::CN;
    case U_GCB_CR: return Gcb::CR;
    case U_GCB_EXTEND: return Gcb::EX;
    case U_GCB_L: return Gcb::L;
    case U_GCB_LF: return Gcb::LF;
    case U_GCB_LV: return Gcb::LV;
    case U_GCB_LVT: return Gcb::LVT;
    case U_GCB_T: return Gcb::T;
    case U_GCB_V: return Gcb::V;
    case U_GCB_SPACING_MARK: return Gcb::SM;
    case U_GCB_PREPEND: return Gcb::PP;
    case U_GCB_REGIONAL_INDICATOR: return Gcb::RI;
    case U_GCB_E_BASE: return Gcb::EB;
    case U_GCB_E_BASE_GAZ: return Gcb::EBG;
    case U_GCB_E_MODIFIER: return Gcb::EM;
    case U_GCB_GLUE_AFTER_ZWJ: return Gcb::GAZ;
    case U_GCB_ZWJ: return Gcb::ZWJ;
    case U_GCB_OTHER:
    default:
        return Gcb::XX;
    }
}

bool grapheme_extend(uint32_t cp)
{
    return (u_hasBinaryProperty(static_cast<UChar32>(cp),
        UCHAR_GRAPHEME_EXTEND) == TRUE) ? true : false;
}

bool default_ignorable_code_point(uint32_t cp)
{
    return (u_hasBinaryProperty(static_cast<UChar32>(cp),
        UCHAR_DEFAULT_IGNORABLE_CODE_POINT) == TRUE) ? true : false;
}

bool variation_selector(uint32_t cp)
{
    return (u_hasBinaryProperty(static_cast<UChar32>(cp),
        UCHAR_VARIATION_SELECTOR) == TRUE) ? true : false;
}

// bool odi(uint32_t cp)
// NO API FOR THIS PROPERTY IN ICU LIBRARY

// bool ogr_ext(uint32_t cp)
// NO API FOR THIS PROPERTY IN ICU LIBRARY

// bool prepended_concatenation_mark(uint32_t cp)
// NO API FOR THIS PROPERTY IN ICU LIBRARY

bool white_space(uint32_t cp)
{
    return u_isUWhiteSpace(static_cast<UChar32>(cp));
}

} // namespace icu;
} // namespace unicode
} // namespace seshat
#endif // SESHAT_ICU_BACKEND