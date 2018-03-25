/*
//  tests/codepoint.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 02. 22:17
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//
//  Test of CodePoint
*/
#include <catch.hpp>

#include <seshat/codepoint.h>

#include <cassert>
#include <iostream>
#include <utility>

using seshat::CodePoint;
using seshat::IllegalCodePoint;
using seshat::CodePointSequence;
using seshat::CodePointSequenceIter;
using seshat::CodePointSequenceConstIter;

using namespace Catch;

TEST_CASE("CodePoint")
{
    CodePoint cp_1('c');        // 0x63
    CodePoint cp_2(0xAC00);     // '가'
    CodePoint cp_3(0x10343);    // '𐍃'
    SECTION("constructor")
    {
        /*
        SECTION("Constructor from unsigned integer")
        {
        }
        */
        SECTION("Copy constructor")
        {
            CodePoint cp_src = CodePoint(0xAC00);
            CodePoint cp_cpy(cp_src);

            REQUIRE(cp_cpy == cp_src);
        }
        SECTION("throw IllegalCodePoint")
        {
            REQUIRE_THROWS_AS(CodePoint(0x110000), IllegalCodePoint);
            REQUIRE_THROWS_WITH(CodePoint(0x110001),
                    StartsWith("IllegalCodePoint:"));
        }
    }
    SECTION("element access")
    {
        SECTION("code")
        {
            REQUIRE(cp_1.code() == 0x63);
            REQUIRE(cp_2.code() == 0xAC00);
            REQUIRE(cp_3.code() == 0x10343);
        }
        SECTION("to_string")
        {
            REQUIRE_THAT(cp_1.to_string(), Equals("U+0063"));
            REQUIRE_THAT(cp_2.to_string(), Equals("U+AC00"));
            REQUIRE_THAT(cp_3.to_string(), Equals("U+10343"));
        }
    }
    SECTION("modify")
    {
        SECTION("Copy assignment operator")
        {
            cp_1 = cp_2;
            REQUIRE(cp_1 == cp_2);
        }
        SECTION("assignment operator with unsigned integer")
        {
            cp_1 = 0x1234;
            REQUIRE(cp_1.code() == 0x1234);
        }
    }
    SECTION("comparison")
    {
        SECTION("Comparison operators")
        {
            cp_1 = cp_2;
            REQUIRE(cp_1 == cp_2);
            REQUIRE(cp_2 == cp_1);
            REQUIRE(cp_1 != cp_3);
            REQUIRE(cp_2 != cp_3);
        }
    }
    SECTION("others")
    {
        SECTION("Convertable to integer")
        {
            uint32_t uint_1 = cp_1;
            uint32_t uint_2 = static_cast<uint32_t>(cp_2);
            REQUIRE(uint_1 == 0x63);
            REQUIRE(uint_2 == 0xAC00);
        }
    }
}

TEST_CASE("CodePointSequence")
{
    CodePointSequence seq = CodePointSequence();
    seq.append(CodePoint('f'));
    seq.append(CodePoint('o'));
    seq.append(CodePoint('o'));

    SECTION("constructor")
    {
        SECTION("Copy constructor")
        {
            CodePointSequence seq_cpy(seq);
            REQUIRE(seq == seq_cpy);
        }
        SECTION("Move constructor")
        {
            CodePointSequence seq_new(std::move(seq));
            REQUIRE(seq.length() == 0);
        }
        SECTION("Constructor with iterator")
        {
            CodePointSequence seq_1;
            seq_1.append('h');
            seq_1.append('e');
            seq_1.append('l');
            seq_1.append('l');
            seq_1.append('o');
            CodePointSequence seq_2(seq_1.begin(), seq_1.begin() + 4);
            CodePointSequence seq_3 = { 0x68, 0x65, 0x6C, 0x6C }; // "hell"
            REQUIRE(seq_2.length() == 4);
            REQUIRE(seq_2 == seq_3);
        }
        SECTION("Constructor with initializer list")
        {
            CodePointSequence seq_1 = {
                0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20,   // "hello, "
                0x73, 0x65, 0x73, 0x68, 0x61, 0x74, 0x21    // "seshat!"
            };
        }
    }
    SECTION("element access")
    {
        SECTION("length")
        {
            REQUIRE(seq.length() == 3);
        }
        SECTION("max_size")
        {
            REQUIRE(seq.max_size() > 0);
            REQUIRE(seq.max_size() >= seq.length());
        }
    }
    SECTION("modify")
    {
        SECTION("append")
        {
            seq.append(CodePoint(' '));
            seq.append(CodePoint('b'));
            seq.append(CodePoint('a'));
            seq.append(CodePoint('r'));
            REQUIRE(seq.length() == 7);
        }
        SECTION("clear")
        {
            REQUIRE_NOTHROW(seq.clear());
            REQUIRE(seq.length() == 0);
        }
    }
    SECTION("iterator")
    {
        CodePointSequenceIter beg = seq.begin();
        CodePointSequenceIter end = seq.end();
        CodePointSequence::reverse_iterator rbeg = seq.rbegin();
        CodePointSequence::reverse_iterator rend = seq.rend();
        // TODO: Add test cases.
    }
    SECTION("comparison")
    {
        CodePointSequence seq_1 = { 'f', 'o', 'o' };
        CodePointSequence seq_2 = { 'b', 'a', 'r' };
        CodePointSequence seq_3 = { 'f', 'o', 'o' };
        SECTION("comparison operators")
        {
            REQUIRE(seq_1 == seq_1);
            REQUIRE(seq_2 != seq_1);
            REQUIRE(seq_1 == seq_3);
        }
    }
}