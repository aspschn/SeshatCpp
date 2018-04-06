/*
//  tests/utils.cpp
//
//  Author:     Sophia Lee
//  Created:    2018. 04. 06. 10:46
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//
//
*/
#include <catch.hpp>

#include <seshat/utils.h>

using seshat::code_point_to_string;
using seshat::code_point_from_string;

using namespace Catch;

#if 0
TEST_CASE("Range")
{}
TEST_CASE("TwoStageTable")
{}
TEST_CASE("AT_DIGIT_32")
{}
TEST_CASE("CP_MAX_DIGIT")
{}
TEST_CASE("code_point_to_string")
{}
#endif
TEST_CASE("code_point_from_string")
{
    REQUIRE(code_point_from_string("0000") == 0);
    REQUIRE(code_point_from_string("0001") == 1);
    REQUIRE(code_point_from_string("002F") == 0x2F);
    REQUIRE(code_point_from_string("AC00") == 0xAC00);
    REQUIRE(code_point_from_string("10FFFF") == 0x10FFFF);
    REQUIRE(code_point_from_string("invalid") == 0);
}
