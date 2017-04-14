/*
//  utils.cpp
//
//  Author:     <OWNER>
//  Created:    2017. 04. 14. 16:02
//  Copyright (c) 2016 <OWNER>. All rights reserved.
//
//
*/
#include <seshat/utils.h>

namespace seshat {

std::string code_point_to_string(uint32_t cp)
{
    std::string code_str = std::string("0000");
    code_str[3] = HEX_CHAR[AT_DIGIT_32(cp, 1)];
    code_str[2] = HEX_CHAR[AT_DIGIT_32(cp, 2)];
    code_str[1] = HEX_CHAR[AT_DIGIT_32(cp, 3)];
    code_str[0] = HEX_CHAR[AT_DIGIT_32(cp, 4)];

    // For code over U+FFFF
    if ((cp >> 16) != 0) {
        // Get maximum digit
        int max_digit = 8;
        while (max_digit > 5) {
            if ((AT_DIGIT_32(cp, max_digit)) == 0) {
                --max_digit;
            } else {
                break;
            }
        }
        // Append to code_str
        for (int digit = 5; digit <= max_digit; ++digit) {
            code_str.insert(0, 1, HEX_CHAR[AT_DIGIT_32(cp, digit)]);
        }
    }

    // Append "U+" to code_str
    code_str.insert(0, "U+");
    return code_str;
}

} // namespace seshat
