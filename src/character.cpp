/*
//  character.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 19. 12:28
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/character.h>

#include <seshat/codepoint.h>
#include <seshat/unicode/normalize.h>

#include <sstream>

namespace seshat {

Character::Character(char a_char)
    : _code_points(decltype(_code_points)())
{
    CodePoint cp = CodePoint(static_cast<uint32_t>(a_char));
    _code_points.append(cp);
}

/*
Character::Character(uint32_t code_point)
    : _code_points(decltype(_code_points)())
{
    CodePoint cp = CodePoint(code_point);
    _code_points.push_back(cp);
}
*/

Character::Character(const CodePoint& code_point)
    : _code_points(decltype(_code_points)())
{
    _code_points.append(code_point);
}

/*
Character::Character(const uint32_t *code_points)
    : _code_points(decltype(_code_points)())
{
    std::vector<CodePoint> cps;
    for (auto it = code_points; *it != 0; ++it) {
        cps.push_back(CodePoint(*it));
    }
}
*/

Character::Character(const CodePointSequence &sequence)
    : _code_points(decltype(_code_points)(sequence))
{
}

Character::~Character()
{
}

size_t Character::size() const
{
    return _code_points.length();
}

const CodePointSequence& Character::sequence() const
{
    return _code_points;
}

std::string Character::to_utf8() const
{
    std::stringstream stream;

    // For all code points
    for (auto&& cp: _code_points) {
        if (0x0000 <= cp.code() && cp.code() <= 0x007F) {
            stream << static_cast<char>(cp.code());
        } else if (0x0080 <= cp.code() && cp.code() <= 0x07FF) {
            stream << static_cast<char>(0xC0 | (cp.code() >> 6));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code())));
        } else if (0x0800 <= cp.code() && cp.code() <= 0xFFFF) {
            stream << static_cast<char>(0xE0 | (cp.code() >> 12));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code() >> 6)));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code())));
        } else if (0x10000 <= cp.code() && cp.code() <= 0x10FFFF) {
            stream << static_cast<char>(0xF0 | (cp.code() >> 18));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code() >> 12)));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code() >> 6)));
            stream << static_cast<char>(0x80 | (0x3F & (cp.code())));
        }
    }

    return stream.str();
}

bool Character::operator==(const Character& other) const
{
    return (unicode::nfd(_code_points) == unicode::nfd(other._code_points));
}

bool Character::operator!=(const Character& other) const
{
    return *this != other;
}

} // namespace seshat