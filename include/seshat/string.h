/*
//  string.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 24. 12:52
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _SESHAT_STRING_H
#define _SESHAT_STRING_H

#include <seshat/codepoint.h>
#include <seshat/character.h>

#include <initializer_list>
#include <vector>

namespace seshat {

class String {
private:
    std::vector<Character> _chars;
public:
    using size_type = decltype(_chars)::size_type;
    String();
    // String(std::initializer_list<Character> init);
    String(const CodePointSequence& sequence);
    String(std::initializer_list<CodePoint> init);
    ~String();

    size_type count() const;
};

} // namespace seshat

#endif /* _SESHAT_STRING_H */
