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

namespace seshat {

// AT_DIGIT_32(uint32_t, int) - select a hexademical digit from given number
// e.g. AT_DIGIT_32(0x1a3f, 3) == 10(0xa)
#define AT_DIGIT_32(code, digit) \
    ((code & (0x0000000F << ((digit - 1) * 4))) >> ((digit - 1) * 4))

// HEX_CHAR[]
static const char HEX_CHAR[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

std::string code_point_to_string(uint32_t cp);

} // namespace seshat

#endif /* _SESHAT_UTILS_H */
