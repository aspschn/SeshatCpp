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
        return Gc::Cn;
    }
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