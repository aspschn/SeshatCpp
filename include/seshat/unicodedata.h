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
#include <memory>
#include <string>
#include <utility>

namespace seshat {

// Gc: General_Category enum
enum class Gc {
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

extern const std::map<uint32_t, Gc> gc_table;
extern const std::map<uint32_t, const char*> name_table;

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

// Unicode name prefix
#define PREFIX_YI_SYLLABLE      "YI SYLLABLE"       // A000-A48C
#define PREFIX_CANADIAN_SYLLABICS "CANADIAN SYLLABICS" // 1400-167F, 18B0-18F5
#define PREFIX_EGYPTIAN_HIEROGLYPH "EGYPTIAN HIEROGLYPH" // 13000-1342E
#define PREFIX_TANGUT_IDEOGRAPH "TANGUT IDEOGRAPH"
#define PREFIX_TANGUT_COMPONENT "TANGUT COMPONENT" // 18800-18AF2
#define PREFIX_CJK_COMPATIBILITY_IDEOGRAPH "CJK COMPATIBILITY IDEOGRAPH"
#define PREFIX_CJK_UNIFIED_IDEOGRAPH "CJK UNIFIED IDEOGRAPH"

// Unicode naming rules
class UnicodeNamingRule {
protected:
    const char *prefix;
    char separator;
    const char *unique;
    uint32_t code;
public:
    UnicodeNamingRule(const char *pre, char sep);
    void set(const char *unq, uint32_t code);
    virtual std::string name() const = 0;
};

class UniqueName : public UnicodeNamingRule {
public:
    UniqueName(const char *pre = nullptr);
    // void set(const char *unq, uint32_t code);
    std::string name() const;
};

class PrefixSpaceUniqueName : public UnicodeNamingRule {
public:
    PrefixSpaceUniqueName(const char *pre);
    // void set(const char *unq, uint32_t code);
    std::string name() const;
};

class PrefixDashUniqueName : public UnicodeNamingRule {
public:
    PrefixDashUniqueName(const char *pre);
    // void set(const char *unq, uint32_t code);
    std::string name() const;
};

class PrefixDashCodePoint : public UnicodeNamingRule {
public:
    PrefixDashCodePoint(const char *pre);
    // void set(const char *unq, uint32_t code);
    std::string name() const;
};

class PrefixDashSequentialNumber : public UnicodeNamingRule {
private:
    int32_t diff;
public:
    PrefixDashSequentialNumber(const char *pre, int32_t diff);
    // void set(const char *unq, uint32_t code);
    std::string name() const;
};

// Unicode Area
enum class UnicodeArea {
    CanadianSyllabics,
    YiSyllable,
    EgyptianHieroglyph,
    TangutIdeograph,
    TangutComponent,
    CjkCompatibilityIdeograph,
    CjkUnifiedIdeograph
};

// Some prefix ranges from <Table 4-13> in 'The Unicode Standard'
// 4.8 Name, but not identical.
using CodePointRange = std::pair<uint32_t, uint32_t>;
const std::map<CodePointRange, UnicodeArea> range_table {
    { std::make_pair(0x3400, 0x4DB5), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x4E00, 0x9FD5), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x20000, 0x2A6D6), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x2A700, 0x2B734), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x2B740, 0x2B81D), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x2B820, 0x2CEA1), UnicodeArea::CjkUnifiedIdeograph },
    { std::make_pair(0x1400, 0x167F), UnicodeArea::CanadianSyllabics },
    { std::make_pair(0x18B0, 0x18F5), UnicodeArea::CanadianSyllabics },
    { std::make_pair(0xA000, 0xA48C), UnicodeArea::YiSyllable },
    { std::make_pair(0xF900, 0xFA6D), UnicodeArea::CjkCompatibilityIdeograph },
    { std::make_pair(0xFA70, 0xFAD9), UnicodeArea::CjkCompatibilityIdeograph },
    { std::make_pair(0x13000, 0x1342E), UnicodeArea::EgyptianHieroglyph },
    { std::make_pair(0x17000, 0x187EC), UnicodeArea::TangutIdeograph },
    { std::make_pair(0x18800, 0x18AF2), UnicodeArea::TangutComponent },
    { std::make_pair(0x2F800, 0x2FA1D), UnicodeArea::CjkCompatibilityIdeograph }
};

using UnicodeNamingRulePtr = std::unique_ptr<UnicodeNamingRule>;
UnicodeNamingRulePtr naming_rule(UnicodeArea area);

} // namespace seshat

#endif /* _UNICODEDATA_H */
