#include <seshat/codepoint.h>
#include <seshat/character.h>

#include <cstdint>
#include <iostream>

int main()
{
    auto c1 = seshat::Character('a');
    auto c2 = seshat::Character(uint32_t(0xAC00));
    auto c3 = seshat::Character(uint32_t(0x10348));

    std::cout << c1.code_points()[0].code() << std::endl;
    std::cout << c1.code_points()[0].to_string() << std::endl;
    std::cout << int(c1.code_points()[0].gc()) << std::endl;
    std::cout << c2.code_points()[0].code() << std::endl;
    std::cout << c2.code_points()[0].to_string() << std::endl;
    std::cout << int(c2.code_points()[0].gc()) << std::endl;
    std::cout << c3.code_points()[0].code() << std::endl;
    std::cout << c3.code_points()[0].to_string() << std::endl;
    std::cout << int(c3.code_points()[0].gc()) << std::endl;

    std::cout << c2.to_utf8() << std::endl;
    std::cout << c3.to_utf8() << std::endl;

    std::cout << "Gc::Cn" << std::endl;
    if (seshat::CodePoint(0xabff).gc() == seshat::Gc::Cn) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << "done" << std::endl;

    return 0;
}
