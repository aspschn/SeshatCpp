/*
//  tests/casing.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 12. 01. 22:36
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//  Test for case conversion functions.
*/
#include <seshat/unicode/casing.h>

#include <cassert>
#include <cstdint>

using namespace seshat;
using namespace seshat::unicode;

uint32_t get_simple_upper_mapping(uint32_t cp)
{
    auto seq = uppercase_mapping(cp);
    return *(seq.begin());
}

uint32_t get_simple_lower_mapping(uint32_t cp)
{
    auto seq = lowercase_mapping(cp);
    return *(seq.begin());
}

uint32_t get_simple_title_mapping(uint32_t cp)
{
    auto seq = titlecase_mapping(cp);
    return *(seq.begin());
}

int main()
{
    // Simple case.
    uint32_t small_letter_a = 'a';
    uint32_t capital_letter_a = get_simple_upper_mapping(small_letter_a);
    assert(capital_letter_a == 'A');

    uint32_t capital_adlam_ya = 0x1E921;
    uint32_t small_adlam_ya = get_simple_lower_mapping(capital_adlam_ya);
    assert(small_adlam_ya == 0x1E943);

    uint32_t small_roman_num_two = 0x2171;
    uint32_t roman_num_two = get_simple_title_mapping(small_roman_num_two);
    assert(roman_num_two == 0x2161);

    uint32_t capital_1fa9 = 0x1FA9; // GREEK CAPITAL LETTER OMEGA WITH DASIA
                                    // AND PROSGEGRAMMENI
    assert(get_simple_title_mapping(capital_1fa9) == capital_1fa9);

    // Special case.
    uint32_t small_lig_ff = 0xFB00;
    auto capital_f_capital_f = uppercase_mapping(small_lig_ff);
    assert(capital_f_capital_f == (CodePointSequence { 'F', 'F' }));

    auto upper_1f69_0399 = uppercase_mapping(capital_1fa9);
    assert(upper_1f69_0399 == (CodePointSequence { 0x1F69, 0x0399 }));

    return 0;
}
