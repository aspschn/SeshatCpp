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

#include <seshat/gc.h>

#include <cstdint>
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
    std::string to_string() const;

    bool operator==(const CodePoint& other);
    bool operator!=(const CodePoint& other);
};

}

#endif /* _CODEPOINT_H */
