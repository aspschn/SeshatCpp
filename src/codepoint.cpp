/*
//  codepoint.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 19. 12:37
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/codepoint.h>

#include <seshat/utils.h>

#include <algorithm>

namespace seshat {

CodePoint::CodePoint(uint32_t code)
    : _code(code)
{
    if (code > 0x10FFFF) {
        throw IllegalCodePoint();
    }
}

CodePoint::~CodePoint()
{
}

uint32_t CodePoint::code() const
{
    return _code;
}

Gc CodePoint::gc() const
{
    auto category = gc_table.find(_code);
    if (category != gc_table.end()) {
        return category->second;
    } else {
        if (CJK_IDEO_EXT_A_FRST <= _code && _code <= CJK_IDEO_EXT_A_LAST) {
            return Gc::Lo;
        }
        if (CJK_IDEO_FRST <= _code && _code <= CJK_IDEO_LAST) {
            return Gc::Lo;
        }
        if (HANGUL_SYLLAB_FRST <= _code && _code <= HANGUL_SYLLAB_LAST) {
            return Gc::Lo;
        }
        if (NON_PU_HIGH_SRG_FRST <= _code && _code <= NON_PU_HIGH_SRG_LAST) {
            return Gc::Cs;
        }
        if (PU_HIGH_SRG_FRST <= _code && _code <= PU_HIGH_SRG_LAST) {
            return Gc::Cs;
        }
        if (LOW_SRG_FRST <= _code && _code <= LOW_SRG_LAST) {
            return Gc::Cs;
        }
        if (PU_FRST <= _code && _code <= PU_LAST) {
            return Gc::Co;
        }
        if (TANGUT_IDEO_FRST <= _code && _code <= TANGUT_IDEO_LAST) {
            return Gc::Lo;
        }
        if (CJK_IDEO_EXT_B_FRST <= _code && _code <= CJK_IDEO_EXT_B_LAST) {
            return Gc::Lo;
        }
        if (CJK_IDEO_EXT_C_FRST <= _code && _code <= CJK_IDEO_EXT_C_LAST) {
            return Gc::Lo;
        }
        if (CJK_IDEO_EXT_D_FRST <= _code && _code <= CJK_IDEO_EXT_D_LAST) {
            return Gc::Lo;
        }
        if (CJK_IDEO_EXT_E_FRST <= _code && _code <= CJK_IDEO_EXT_E_LAST) {
            return Gc::Lo;
        }
        if (PLANE_15_PU_FRST <= _code && _code <= PLANE_15_PU_LAST) {
            return Gc::Co;
        }
        if (PLANE_16_PU_FRST <= _code && _code <= PLANE_16_PU_LAST) {
            return Gc::Co;
        }
        return Gc::Cn;
    }
}

std::string CodePoint::name() const
{
    std::string unicode_name;

    // Find which area the code point belongs to
    uint32_t code = _code;
    auto range = std::find_if(range_table.begin(), range_table.end(),
        [code](const std::pair<CodePointRange, UnicodeArea>& p)->bool {
            return (p.first.first <= code && code <= p.first.second);
        }
    );

    auto name_pair = name_table.find(_code);
    if (range != range_table.end()) {
        UnicodeNamingRulePtr rule = naming_rule(range->second);
        if (name_pair != name_table.end()) {
            rule->set(name_pair->second, _code);
        } else {
            rule->set(nullptr, _code);
        }
        unicode_name = rule->name();
    } else {
        if (name_pair != name_table.end()) {
            unicode_name = name_pair->second;
        } else {
            throw NoName();
        }
    }

    return unicode_name;
}

std::string CodePoint::to_string() const
{
    return code_point_to_string(_code);
}

bool CodePoint::operator==(const CodePoint& other)
{
    return _code == other._code;
}

bool CodePoint::operator!=(const CodePoint& other)
{
    return _code != other._code;
}

// Misc

} // namespace seshat