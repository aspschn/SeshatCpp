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

static const char HEX_CHAR[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

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
    try {
        return gc_table.at(_code);
    } catch (...) {
        // TODO: std::map::at will throw out_of_range exception
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
    try {
        unicode_name = name_table.at(_code);
    } catch (...) {
        throw NoName();
    }
    return unicode_name;
}

std::string CodePoint::to_string() const
{
    std::string code_str = std::string("0000");
    code_str[3] = HEX_CHAR[AT_DIGIT_32(_code, 1)];
    code_str[2] = HEX_CHAR[AT_DIGIT_32(_code, 2)];
    code_str[1] = HEX_CHAR[AT_DIGIT_32(_code, 3)];
    code_str[0] = HEX_CHAR[AT_DIGIT_32(_code, 4)];

    // For code over U+FFFF
    if ((_code >> 16) != 0) {
        // Get maximum digit
        int max_digit = 8;
        while (max_digit > 5) {
            if ((AT_DIGIT_32(_code, max_digit)) == 0) {
                --max_digit;
            } else {
                break;
            }
        }
        // Append to code_str
        for (int digit = 5; digit <= max_digit; ++digit) {
            code_str.insert(0, 1, HEX_CHAR[AT_DIGIT_32(_code, digit)]);
        }
    }

    // Append "U+" to code_str
    code_str.insert(0, "U+");
    return code_str;
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