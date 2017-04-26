/*
//  codepoint.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 14. 13:02
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _CODEPOINT_H
#define _CODEPOINT_H

// #include <seshat/unicodedata.h>

#include <cstdint>
#include <exception>
#include <iterator>
#include <string>
#include <vector>

namespace seshat {

class CodePoint {
private:
    uint32_t _code;
public:
    CodePoint(uint32_t code);
    ~CodePoint();

    uint32_t code() const;
    // Gc gc() const;
    // std::string name() const;
    std::string to_string() const;

    bool operator==(const CodePoint& other);
    bool operator!=(const CodePoint& other);
};

class IllegalCodePoint : public std::exception {
public:
    const char* what() const noexcept
    {
        return "IllegalCodePoint: Code point cannot be over U+10FFFF.";
    }
};

class CodePointSequenceIter;
class CodePointSequenceConstIter;

class CodePointSequence {
private:
    std::vector<CodePoint> _codes;
public:
    using iterator = CodePointSequenceIter;
    using const_iterator = CodePointSequenceConstIter;

    CodePointSequence();
    CodePointSequence(const CodePointSequence& origin);
    CodePointSequence(iterator first, iterator last);
    ~CodePointSequence();

    size_t length() const;

    void append(const CodePoint& cp);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};

class CodePointSequenceIter {
public:
    using difference_type = int;
    using value_type = CodePoint;
    using pointer = CodePoint*;
    using reference = CodePoint&;
    using iterator_category = std::random_access_iterator_tag;

    CodePointSequenceIter(pointer ptr);
    bool operator==(const CodePointSequenceIter& other) const;
    bool operator!=(const CodePointSequenceIter& other) const;
    CodePointSequenceIter& operator++(); // ++it
    CodePointSequenceIter operator++(int); // it++
    reference operator*();
private:
    pointer _ptr;
};

class CodePointSequenceConstIter {
public:
    using difference_type = int;
    using value_type = const CodePoint;
    using pointer = const CodePoint*;
    using reference = const CodePoint&;
    using iterator_category = std::random_access_iterator_tag;

    CodePointSequenceConstIter(pointer ptr);
    bool operator==(const CodePointSequenceConstIter& other) const;
    bool operator!=(const CodePointSequenceConstIter& other) const;
    CodePointSequenceConstIter& operator++(); // ++it
    CodePointSequenceConstIter operator++(int); // it++
    reference operator*() const;
private:
    pointer _ptr;
};

}

#endif /* _CODEPOINT_H */
