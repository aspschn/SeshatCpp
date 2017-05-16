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
    Character(const CodePoint& code_point);
    Character(const CodePointSequence& sequence);
    ~Character();

    size_t size() const; // length of code point
    const CodePointSequence& sequence() const;
    std::string to_utf8() const;

    bool operator==(const Character& other) const;
    bool operator!=(const Character& other) const;
};

}

#endif /* _CHARACTER_H */
