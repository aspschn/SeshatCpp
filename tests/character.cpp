/*
//  tests/character.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 16. 14:59
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//
//  Test of Character
*/
#include <catch.hpp>

#include <seshat/character.h>

#include <utility>

using seshat::Character;
using seshat::CodePoint;
using seshat::CodePointSequence;
using seshat::SurrogateIncluded;
using seshat::NotASingleCharacter;

using namespace Catch;

TEST_CASE("Character")
{
    Character ch_1 = Character('a');
    Character ch_2 = Character(CodePoint(0xAC01)); // '각'
    Character ch_3 = Character(CodePointSequence {
        0x1100, 0x1161, 0x11A8
    }); // Decomposed Hangul Syllable '각'

    SECTION("constructor")
    {
        SECTION("Copy constructor")
        {
            Character ch_cpy(ch_1);

            REQUIRE(ch_1 == ch_cpy);
        }
        SECTION("Move constructor")
        {
            Character ch = Character(CodePoint(0xAC00));
            Character ch_new(std::move(ch));
            REQUIRE(ch.size() == 0);
            // TODO: Moved source Character should not be copy/movable.
        }
        SECTION("throw SurrogateIncluded")
        {
            REQUIRE_THROWS_AS(Character(CodePoint(0xD800)), SurrogateIncluded);
            REQUIRE_THROWS_WITH(Character(CodePoint(0xD800)),
                    StartsWith("SurrogateIncluded"));
        }
        SECTION("throw NotASingleCharacter")
        {
            // Empty sequence should throws NotASingleCharacter exception.
            REQUIRE_THROWS_AS(Character(CodePointSequence {}),
                    NotASingleCharacter);

            REQUIRE_THROWS_AS(
                    Character(CodePointSequence { 0x1100, 0x1161, 0x1100 }),
                    NotASingleCharacter);
            REQUIRE_THROWS_WITH(
                    Character(CodePointSequence { 0x1100, 0x1161, 0x1100 }),
                    StartsWith("NotASingleCharacter"));
        }
        // TODO: Surrogate with multiple or zero characters, which is prior?
    }
    SECTION("element access")
    {
        SECTION("size")
        {
            REQUIRE(ch_1.size() == 1);
            REQUIRE(ch_2.size() == 1);
            REQUIRE(ch_3.size() == 3);
        }
        SECTION("sequence")
        {
            REQUIRE(
                ch_3.sequence() == CodePointSequence { 0x1100, 0x1161, 0x11A8 }
            );
        }
        SECTION("to_utf8")
        {
            REQUIRE(ch_2.to_utf8() == u8"각");
        }
    }
    SECTION("modify")
    {
        Character ch('Z');
        ch = ch_1;
        REQUIRE(ch == Character('a'));
    }
    SECTION("comparison")
    {
        REQUIRE(ch_1 != ch_2);
    }
}

#if 0
int main()
{


    // size()
    assert(ch1.size() == 1);
    assert(ch2.size() == 1);
    assert(ch3.size() == 3);

    // sequence()
    for (auto cp: ch3.sequence()) {
        std::cout << cp.to_string() << " ";
    }
    std::cout << std::endl;

    // to_utf8()
    std::cout << ch1.to_utf8() << std::endl;
    std::cout << ch2.to_utf8() << std::endl;
    std::cout << ch3.to_utf8() << std::endl;

    // operators
    assert((ch1 == ch2) == false);
    assert((ch2 == ch3) == true);

    // exceptions
    try {
        Character from_surrogate = Character(CodePointSequence {
            'a', 0xD800
        });
    } catch (const SurrogateIncluded& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Character zero_sequence = Character(CodePointSequence {});
    } catch (const NotASingleCharacter& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Character multiple_grapheme = Character(CodePointSequence {
            0x1100, 0x1161, 0x1100
        });
    } catch (const NotASingleCharacter& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
#endif