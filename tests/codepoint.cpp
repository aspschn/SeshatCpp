/*
//  tests/codepoint.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 02. 22:17
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Test of CodePoint
*/
#include <seshat/codepoint.h>

#include <cassert>
#include <iostream>

int main()
{
    using seshat::CodePoint;
    using seshat::Gc;
    using seshat::CodePointSequence;

    CodePoint cp_1 = CodePoint('c');
    CodePoint cp_2 = CodePoint(0xAC00);  // '가'
    CodePoint cp_3 = CodePoint(0x10343); // '𐍃'

    std::cout << "--- code() ---" << std::endl;
    std::cout << "cp_1(99):     " << cp_1.code() << std::endl;
    std::cout << "cp_2(44032):  " << cp_2.code() << std::endl;
    std::cout << "cp_3(66371):  " << cp_3.code() << std::endl;
    std::cout << std::endl;

    std::cout << "--- gc() - General_Category ---" << std::endl;
    if (cp_1.gc() != Gc::Ll)
        std::cout << "wrong!" << std::endl;
    if (cp_2.gc() != Gc::Lo)
        std::cout << "wrong!" << std::endl;
    if (cp_3.gc() != Gc::Lo)
        std::cout << "wrong!" << std::endl;
    assert(CodePoint(0xAC10).gc() == Gc::Lo);   // Hangul 감 (Lo)
    assert(CodePoint(0x10FFFA).gc() == Gc::Co); // Plane 16 Private Use (Co)
    std::cout << std::endl;

    std::cout << "--- to_string() ---" << std::endl;
    std::cout << "cp_1(\"U+0063\"):  " << cp_1.to_string() << std::endl;
    std::cout << "cp_2(\"U+AC00\"):  " << cp_2.to_string() << std::endl;
    std::cout << "cp_3(\"U+10343\"): " << cp_3.to_string() << std::endl;
    std::cout << std::endl;

    std::cout << "--- operators ---" << std::endl;
    std::cout << "cp_1('c') != cp_2('가'): " << (cp_1 != cp_2) << std::endl;
    std::cout << "cp_2('가') == CodePoint(0xAC00): "
        << (cp_2 == CodePoint(0xAC00)) << std::endl;
    std::cout << std::endl;

    std::cout << "--- exceptions ---" << std::endl;
    std::cout << "try CodePoint(0x110000) ..." << std::endl;
    try {
        CodePoint cp_except = CodePoint(0x110000);
    } catch (const seshat::IllegalCodePoint& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- sequence ---" << std::endl;
    CodePointSequence seq = CodePointSequence();
    // Test append
    seq.append(cp_1);
    seq.append(cp_2);
    seq.append(cp_3);
    // Test length
    std::cout << "length(3): " << seq.length() << std::endl;
    // Test constructor with iterator
    CodePointSequence seq2 = CodePointSequence(seq.begin(), seq.end());

    std::cout << "CodePoint test end" << std::endl;

    return 0;
}
