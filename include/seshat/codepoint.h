/*
//  codepoint.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 14. 13:02
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _CODEPOINT_H
#define _CODEPOINT_H

#include <seshat/unicodedata.h>

#include <cstdint>
#include <exception>
#include <string>

namespace seshat {

#define AT_DIGIT_32(code, digit) \
    ((code & (0x0000000F << ((digit - 1) * 4))) >> ((digit - 1) * 4))

class CodePoint {
private:
    uint32_t _code;
public:
    CodePoint(uint32_t code);
    ~CodePoint();

    uint32_t code() const;
    Gc gc() const;
    std::string name() const;
    std::string to_string() const;

    bool operator==(const CodePoint& other);
    bool operator!=(const CodePoint& other);
};

class IllegalCodePoint : public std::exception {
public:
    const char* what() const noexcept
    {
        return "IllegalCodePoint: Code point cannot be over U+10FFFF.";
    }
};

class NoName : public std::exception {
public:
    const char* what() const noexcept
    {
        return "NoName: No such name for the code point.";
    }
};

}

#endif /* _CODEPOINT_H */
