/*
//  utils.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 14. 16:03
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _SESHAT_UTILS_H
#define _SESHAT_UTILS_H

#include <string>
#include <utility>

namespace seshat {

template <typename T>
struct Range {
    T lower;
    T upper;

    Range(const T& lower, const T& upper)
        : lower(lower), upper(upper)
    {}
    bool operator==(const Range<T>& other) const
    {
        /*
         * equal if other range is in this range.
         *          ___________  <- other --->  __________________
         *      ___|___________|__             |__________________|
         *     |   |           |  | <- this -> |                  |
         *  ---.---.-----------.--.----     ---.------------------.----
         */
        return (this->lower <= other.lower) && (this->upper >= other.upper);
    }
    bool operator!=(const Range<T>& other) const
    {
        return (this->lower > other.lower) || (this->upper < other.upper);
    }
    bool operator<(const Range<T>& other) const
    {
        return (this->upper < other.lower);
    }
    bool operator>(const Range<T>& other) const
    {
        return (this->lower > other.upper);
    }
};

using CodePointRange = Range<uint32_t>;

// AT_DIGIT_32(uint32_t, int) - select a hexademical digit from given number
// e.g. AT_DIGIT_32(0x1a3f, 3) == 10(0xa)
#define AT_DIGIT_32(code, digit) \
    ((code & (0x0000000F << ((digit - 1) * 4))) >> ((digit - 1) * 4))

// CP_MAX_DIGIT(uint32_t) - Get maximum digit of code point in hexademical.
// Only works with legal Unicode code points.
#define CP_MAX_DIGIT(code) \
    ((code) <= 0xf) ? 1 : \
    (0x00010 <= (code) && (code) <= 0x000ff) ? 2 : \
    (0x00100 <= (code) && (code) <= 0x00fff) ? 3 : \
    (0x01000 <= (code) && (code) <= 0x0ffff) ? 4 : \
    (0x10000 <= (code) && (code) <= 0xfffff) ? 5 : 6

// HEX_CHAR[]
static const char HEX_CHAR[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

std::string code_point_to_string(uint32_t cp);

} // namespace seshat

#endif /* _SESHAT_UTILS_H */
