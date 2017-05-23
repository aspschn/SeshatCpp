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
#include <seshat/unicode/segmentation.h>

#include <sstream>

namespace seshat {

Character::Character(char a_char)
    : _code_points(decltype(_code_points)())
{
    CodePoint cp = CodePoint(static_cast<uint32_t>(a_char));
    _code_points.append(cp);
}

Character::Character(const CodePoint& code_point)
    : _code_points(decltype(_code_points)())
{
    // if (gc(code_point.code()) == Gc::Cs) {
    // For performance, Surrogate code points compared directly.
    if (0xD800 <= code_point.code() && code_point.code() <= 0xDFFF) {
        throw SurrogateIncluded();
    }
    _code_points.append(code_point);
}

Character::Character(const CodePointSequence &sequence)
    : _code_points(decltype(_code_points)())
{
    for (auto cp: sequence) {
        if (0xD800 <= cp.code() && cp.code() <= 0xDFFF) {
            throw SurrogateIncluded();
        }
    }
    // Check if not a single grapheme cluster (zero or greater than one)
    if ((unicode::grapheme_bound(sequence) + 1) != sequence.length()) {
        throw NotASingleCharacter();
    }
    for (auto cp: sequence) {
        _code_points.append(cp);
    }
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