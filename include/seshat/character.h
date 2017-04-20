/*
//  character.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 14. 13:26
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <seshat/codepoint.h>

#include <vector>

namespace seshat {

class Character {
private:
    CodePointSequence _code_points;
public:
    Character(char a_char); // an ascii character
    // Character(uint32_t code_point);
    Character(const CodePoint& code_point);
    // Character(const uint32_t *code_points);
    // Character(const CodePoint *code_points);
    Character(const CodePointSequence& sequence);
    ~Character();

    size_t size() const; // length of code point
    const CodePointSequence& sequence() const;
    std::string to_utf8() const;
};

}

#endif /* _CHARACTER_H */
