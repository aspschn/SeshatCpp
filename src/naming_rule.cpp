/*
//  naming_rule.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 14. 15:38
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicodedata/naming_rule.h>

#include <seshat/unicode/hangul.h>
#include <seshat/utils.h>

namespace seshat {

// Unicode naming rules.
//
UnicodeNamingRule::UnicodeNamingRule(const char *pre, char sep)
    : prefix(pre), separator(sep), unique(nullptr), code(0)
{
}

void UnicodeNamingRule::set(const char *unq, uint32_t code)
{
    this->unique = unq;
    this->code = code;
}

UniqueName::UniqueName(const char *pre)
    : UnicodeNamingRule(pre, '\0')
{
}

std::string UniqueName::name() const
{
    return std::string(unique);
}

PrefixSpaceUniqueName::PrefixSpaceUniqueName(const char *pre)
    : UnicodeNamingRule(pre, ' ')
{
}

std::string PrefixSpaceUniqueName::name() const
{
    std::string n = std::string(prefix) + separator + unique;
    return n;
}

PrefixDashUniqueName::PrefixDashUniqueName(const char *pre)
    : UnicodeNamingRule(pre, '-')
{
}

std::string PrefixDashUniqueName::name() const
{
    std::string n = std::string(prefix) + separator + unique;
    return n;
}

PrefixDashCodePoint::PrefixDashCodePoint(const char *pre)
    : UnicodeNamingRule(pre, '-')
{
}

std::string PrefixDashCodePoint::name() const
{
    std::string n = std::string(prefix) + separator;
    std::string cp_str = code_point_to_string(code);
    cp_str = cp_str.erase(0, 2); // discard "U+"
    n += cp_str;
    return n;
}

PrefixDashSequentialNumber::PrefixDashSequentialNumber(const char *pre,
    int32_t diff)
    : UnicodeNamingRule(pre, '-')
{
    this->diff = diff;
}

std::string PrefixDashSequentialNumber::name() const
{
    std::string n = std::string(prefix) + separator;
    std::string num_str = std::to_string(code - diff);
    while (num_str.length() < 3) {
        num_str.insert(num_str.begin(), '0');
    }
    n += num_str;
    return n;
}

HangulSyllableName::HangulSyllableName()
    : UnicodeNamingRule(PREFIX_HANGUL_SYLLABLE, ' ')
{
}

std::string HangulSyllableName::name() const
{
    std::string n = std::string(prefix) + separator
        + unicode::hangul::syllable_name(code);

    return n;
}

UnicodeNamingRulePtr naming_rule(UnicodeArea area)
{
    switch (area) {
    case UnicodeArea::CanadianSyllabics:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_CANADIAN_SYLLABICS)
        );
    case UnicodeArea::YiSyllable:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_YI_SYLLABLE)
        );
    case UnicodeArea::HangulSyllable:
        return UnicodeNamingRulePtr(
            new HangulSyllableName()
        );
    case UnicodeArea::CjkCompatibilityIdeograph:
        return UnicodeNamingRulePtr(
            new PrefixDashCodePoint(PREFIX_CJK_COMPATIBILITY_IDEOGRAPH)
        );
    case UnicodeArea::CjkUnifiedIdeograph:
        return UnicodeNamingRulePtr(
            new PrefixDashCodePoint(PREFIX_CJK_UNIFIED_IDEOGRAPH)
        );
    case UnicodeArea::EgyptianHieroglyph:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_EGYPTIAN_HIEROGLYPH)
        );
    case UnicodeArea::AnatolianHieroglyph:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_ANATOLIAN_HIEROGLYPH)
        );
    case UnicodeArea::BamumLetterPhaseA:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_A)
        );
    case UnicodeArea::BamumLetterPhaseB:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_B)
        );
    case UnicodeArea::BamumLetterPhaseC:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_C)
        );
    case UnicodeArea::BamumLetterPhaseD:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_D)
        );
    case UnicodeArea::BamumLetterPhaseE:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_E)
        );
    case UnicodeArea::BamumLetterPhaseF:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_BAMUM_LETTER_PHASE_F)
        );
    case UnicodeArea::TangutComponent:
        return UnicodeNamingRulePtr(
            new PrefixDashSequentialNumber(PREFIX_TANGUT_COMPONENT, 100351)
        );
    case UnicodeArea::TangutIdeograph:
        return UnicodeNamingRulePtr(
            new PrefixDashCodePoint(PREFIX_TANGUT_IDEOGRAPH)
        );
    case UnicodeArea::NushuCharacter:
        return UnicodeNamingRulePtr(
            new PrefixDashCodePoint(PREFIX_NUSHU_CHARACTER)
        );
    case UnicodeArea::MusicalSymbol:
        return UnicodeNamingRulePtr(
            new PrefixSpaceUniqueName(PREFIX_MUSICAL_SYMBOL)
        );
    default:
        break;
    }
    return UnicodeNamingRulePtr(new UniqueName());
}

} // namespace seshat
