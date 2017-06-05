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

#include <cstdint>
#include <exception>
#include <initializer_list>
#include <iterator>
#include <string>
#include <vector>

namespace seshat {

class CodePoint {
private:
    uint32_t _code;
public:
    CodePoint(uint32_t code);
    CodePoint(const CodePoint& origin);
    ~CodePoint();

    uint32_t code() const;
    std::string to_string() const;

    CodePoint& operator=(const CodePoint& origin);
    CodePoint& operator=(uint32_t code);
    bool operator==(const CodePoint& other) const;
    bool operator!=(const CodePoint& other) const;
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
    using size_type = decltype(_codes)::size_type;
    using iterator = CodePointSequenceIter;
    using const_iterator = CodePointSequenceConstIter;

    CodePointSequence();
    CodePointSequence(const CodePointSequence& origin);
    CodePointSequence(CodePointSequence&& origin);
    template <typename It>
    CodePointSequence(It first, It last);
    CodePointSequence(std::initializer_list<CodePoint> init);
    ~CodePointSequence();

    size_type length() const;
    size_type max_size() const;

    void append(const CodePoint& cp);
    void clear() noexcept;
    iterator insert(const_iterator pos, const CodePoint& cp);
    template <typename It>
    iterator insert(const_iterator pos, It first, It last);
    iterator insert(const_iterator pos,
        std::initializer_list<CodePoint> ilist);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    CodePointSequence& operator=(const CodePointSequence& origin);
    CodePointSequence& operator=(CodePointSequence&& origin);
    bool operator==(const CodePointSequence& other) const;
    bool operator!=(const CodePointSequence& other) const;
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
    bool operator<(const CodePointSequenceIter& other) const;
    bool operator>(const CodePointSequenceIter& other) const;
    bool operator<=(const CodePointSequenceIter& other) const;
    bool operator>=(const CodePointSequenceIter& other) const;
    CodePointSequenceIter& operator++(); // ++it
    CodePointSequenceIter operator++(int); // it++
    CodePointSequenceIter& operator--(); // --it
    CodePointSequenceIter operator--(int); // it--
    CodePointSequenceIter& operator+=(difference_type n);
    CodePointSequenceIter& operator-=(difference_type n);
    CodePointSequenceIter operator+(difference_type n) const;
    CodePointSequenceIter operator-(difference_type n) const;
    difference_type operator-(const CodePointSequenceIter& other) const;
    reference operator[](difference_type n);
    reference operator*();

    operator CodePointSequenceConstIter() const;
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
    bool operator<(const CodePointSequenceConstIter& other) const;
    bool operator>(const CodePointSequenceConstIter& other) const;
    bool operator<=(const CodePointSequenceConstIter& other) const;
    bool operator>=(const CodePointSequenceConstIter& other) const;
    CodePointSequenceConstIter& operator++(); // ++it
    CodePointSequenceConstIter operator++(int); // it++
    CodePointSequenceConstIter& operator--(); // --it
    CodePointSequenceConstIter operator--(int); // it--
    CodePointSequenceConstIter& operator+=(difference_type n);
    CodePointSequenceConstIter operator+(difference_type n) const;
    difference_type operator-(const CodePointSequenceConstIter& other) const;
    reference operator*() const;
private:
    pointer _ptr;
};

} // namespace seshat

#endif /* _CODEPOINT_H */
