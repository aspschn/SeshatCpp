/*
//  unicode/properties.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 16:30
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode properties enums and functions.
//  Currently not fully contains. It may split to or merge with other
//  property types.
*/
#ifndef _UNICODE_PROPERTIES_H
#define _UNICODE_PROPERTIES_H

#include <cstdint>

namespace seshat {
namespace unicode {

// Script (sc)
enum class Script {
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
    Zinh, Zyyy, Zzzz // Inherited ; Qaai // Common // Unknown
};

Script script(uint32_t cp);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_PROPERTIES_H */
