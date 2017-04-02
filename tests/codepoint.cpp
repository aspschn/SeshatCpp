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

#include <iostream>

int main()
{
    using seshat::CodePoint;
    using seshat::Gc;

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

    std::cout << "CodePoint test end" << std::endl;

    return 0;
}
