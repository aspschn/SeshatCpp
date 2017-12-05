//
//  codepoint.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 14. 13:02
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Fundamental element of Seshat string.
#ifndef _CODEPOINT_H
#define _CODEPOINT_H

#include <cstdint>
#include <exception>
#include <initializer_list>
#include <iterator>
#include <string>
#include <vector>

namespace seshat {

/// \brief  Class to present Unicode code point.
class CodePoint {
private:
    uint32_t _code;
public:
    //==-----------------------
    // Constructor/Destructor
    //==-----------------------

    /// \brief  Constructor from unsigned integer.
    /// \param  code
    ///         Code point as an integer.
    /// \throw  IllegalCodePoint
    ///         If the \p code is greater than 0x10FFFF, this exception will be
    ///         thrown.
    CodePoint(uint32_t code);

    /// \brief  Copy constructor.
    CodePoint(const CodePoint& origin);

    ~CodePoint();

    //==-----------------------
    // Element access
    //==-----------------------

    /// \brief  Get the code point as an integer.
    uint32_t code() const;

    /// \brief  Returns the code point as a string.
    ///
    /// Returns the code point as a string in hexademical number with 'U+'
    /// prefix.
    /// If the code point is in range 0x0 - 0xFFF, additional 0 is filled to
    /// make at least 4 digit number.
    std::string to_string() const;

    //==-----------------------
    // Modify
    //==-----------------------

    /// \brief  Copy assignment operator.
    CodePoint& operator=(const CodePoint& origin);

    /// \brief  Assign a code point from an integer.
    CodePoint& operator=(uint32_t code);

    //==-----------------------
    // Comparison
    //==-----------------------

    /// \brief  Returns true if two `CodePoint`s have the same value.
    bool operator==(const CodePoint& other) const;

    /// \brief  Returns true if two `CodePoint`s have the different value.
    bool operator!=(const CodePoint& other) const;

    //==--------------
    // Others
    //==--------------

    /// \brief  Implicit/Explicit convertible to integer.
    operator uint32_t() const { return _code; }
};

/// \brief  Thrown when trying to assign an integer out of legal Unicode code
///         point range.
///
/// Legal Unicode code point range is U+0000 <= C <= U+10FFFF.
class IllegalCodePoint : public std::exception {
public:
    const char* what() const noexcept
    {
        return "IllegalCodePoint: Code point cannot be over U+10FFFF.";
    }
};

class CodePointSequenceIter;
class CodePointSequenceConstIter;

/// \brief Sequence of code points.
class CodePointSequence {
private:
    std::vector<CodePoint> _codes;
public:
    using size_type = decltype(_codes)::size_type;
    using iterator = CodePointSequenceIter;
    using const_iterator = CodePointSequenceConstIter;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    //==-----------------------
    // Constructor/Destructor
    //==-----------------------

    /// \brief  Default constructor with empty elements.
    CodePointSequence();

    /// \brief  Copy constructor.
    CodePointSequence(const CodePointSequence& origin);

    /// \brief  Move constructor.
    CodePointSequence(CodePointSequence&& origin);

    /// \brief  Construct with the part of other sequence.
    template <typename It>
    CodePointSequence(It first, It last);

    /// \brief  Construct with initializer list.
    CodePointSequence(std::initializer_list<CodePoint> init);

    ~CodePointSequence();

    //==----------------------------------
    // Element access
    //==----------------------------------

    /// \brief  Get the number of code points in the sequence.
    size_type length() const;

    /// \brief  Get the maximum capacity in the current platform.
    size_type max_size() const;

    //==----------------------------------
    // Modify
    //==----------------------------------

    /// \brief  Append a code point to end of sequence.
    void append(const CodePoint& cp);

    /// \brief  Delete all code points.
    void clear() noexcept;

    /// \brief  Insert a code point at the position.
    ///
    /// Insert a code point at before the position.
    iterator insert(const_iterator pos, const CodePoint& cp);

    /// \brief  Insert code points in the other sequence at the position.
    template <typename It>
    iterator insert(const_iterator pos, It first, It last);

    /// \brief  Insert code points with initializer list at the position.
    iterator insert(const_iterator pos,
        std::initializer_list<CodePoint> ilist);

    /// \brief  Delete a code point at the position.
    void erase(const_iterator pos);

    //==-----------------------------
    // Iterator
    //==-----------------------------

    /// \brief  Returns an iterator to the first code point.
    iterator begin();

    /// \brief  Returns an iterator to the first code point.
    const_iterator begin() const;

    /// \brief  Returns an iterator to the past the last code point.
    iterator end();

    /// \brief  Returns an iterator to the past the last code point.
    const_iterator end() const;

    /// \brief  Returns a reverse iterator points past the last code point.
    reverse_iterator rbegin();

    /// \brief  Returns a reverse iterator points past the last code point.
    const_reverse_iterator rbegin() const;

    /// \brief  Returns a reverse iterator points first code point.
    reverse_iterator rend();

    /// \brief  Returns a reverse iterator points first code point.
    const_reverse_iterator rend() const;

    //==-----------------------------
    // Modify
    //==-----------------------------

    /// \brief  Copy assignment operator.
    CodePointSequence& operator=(const CodePointSequence& origin);

    /// \brief  Move assignment operator.
    CodePointSequence& operator=(CodePointSequence&& origin);

    //==----------------------------
    // Comparison
    //==----------------------------

    /// \brief  Returns true if it contains the same values to other.
    bool operator==(const CodePointSequence& other) const;

    /// \brief  Returns true if the values it contains are not same to other.
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
    CodePointSequenceConstIter& operator-=(difference_type n);
    CodePointSequenceConstIter operator+(difference_type n) const;
    CodePointSequenceConstIter operator-(difference_type n) const;
    difference_type operator-(const CodePointSequenceConstIter& other) const;
    reference operator*() const;
private:
    pointer _ptr;
};

} // namespace seshat

#endif /* _CODEPOINT_H */
