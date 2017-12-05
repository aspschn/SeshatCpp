/*
//  tests/character.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 16. 14:59
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//  Test of Character
*/
#include <seshat/character.h>

#include <cassert>
#include <iostream>

int main()
{
    using seshat::Character;
    using seshat::CodePoint;
    using seshat::CodePointSequence;
    using seshat::SurrogateIncluded;
    using seshat::NotASingleCharacter;

    Character ch1 = Character('a');
    Character ch2 = Character(CodePoint(0xAC01)); // '각'
    Character ch3 = Character(CodePointSequence {
        0x1100, 0x1161, 0x11A8
    }); // Decomposed Hangul Syllable '각'

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
