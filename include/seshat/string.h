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
#include <string>
#include <vector>

namespace seshat {

class String {
private:
    std::vector<Character> _chars;
public:
    using size_type = decltype(_chars)::size_type;
    using iterator = decltype(_chars)::iterator;
    using const_iterator = decltype(_chars)::const_iterator;

    String();
    String(const CodePointSequence& sequence);
    String(std::initializer_list<CodePoint> init);
    String(const String& origin);
    String(String&& origin);
    ~String();

    CodePointSequence to_sequence() const;
    std::string to_utf8() const;

    size_type count() const;

    void clear() noexcept;
    iterator insert(const_iterator pos, const Character& chr);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    String& operator=(const String& origin);
    String& operator=(String&& origin);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;

    String& operator+=(const String& other);
    String operator+(const String& other);
};

} // namespace seshat

#endif /* _SESHAT_STRING_H */
