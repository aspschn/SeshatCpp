//
//  character.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 14. 13:26
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Seshat character is a grapheme cluster.
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <seshat/codepoint.h>

#include <exception>
#include <vector>

namespace seshat {

/// \brief  A class can contains one grapheme cluster.
class Character {
private:
    CodePointSequence _code_points;
public:
    //==-----------------------
    // Constructor/Destructor
    //==-----------------------

    /// \brief  Construct with char type.
    /// \param  a_char
    ///         A C character type. Include the null character ('\0').
    Character(char a_char); // an ascii character

    /// \brief  Construct with a code point.
    /// \param  code_point
    ///         A code point that contained the character.
    /// \throw  SurrogateIncluded
    ///         Thrown if \p code_point is a Unicode Surrogate character.
    Character(const CodePoint& code_point);

    /// \brief  Construct with code point sequence.
    /// \param  sequence
    ///         Code point sequence that considered as one grapheme.
    /// \throw  SurrogateIncluded
    ///         Thrown if \p sequence contains one or more Surrogate characters.
    /// \throw  NotASingleCharacter
    ///         Thrown when \p sequence is not considered as one grapheme.
    Character(const CodePointSequence& sequence);

    /// \brief  Copy constructor.
    Character(const Character& origin);

    /// \brief  Move constructor.
    Character(Character&& origin);

    ~Character();

    //==----------------------
    // Element access
    //==----------------------

    /// \brief  Get length of code points.
    size_t size() const; // length of code point

    /// /brief  Get reference of CodePointSequence the character consisted of.
    const CodePointSequence& sequence() const;

    /// \brief  Make the character to UTF-8 encoded string.
    std::string to_utf8() const;

    //==----------------------
    // Modify
    //==----------------------

    /// \brief  Copy assignment operator.
    Character& operator=(const Character& origin);

    /// \brief  Move assignment operator.
    Character& operator=(Character&& origin);

    //==----------------------
    // Comparison
    //==----------------------

    /// \brief  Returns true if the character same as other.
    bool operator==(const Character& other) const;

    /// \brief  Returns true if the character not same as other.
    bool operator!=(const Character& other) const;
};

/// \brief  Thrown if the argument of Character constructor have Surrogates.
///
/// Unicode Surrogate characters are, the code points ranged in
/// U+D800 <= C <= U+DFFF.
class SurrogateIncluded : public std::exception {
public:
    const char* what() const noexcept
    {
        return "SurrogateIncluded: Surrogate code point to Character is not allowed.";
    }
};

/// \brief  Thrown if the argument of Character constructor is not considered as
///         one grapheme.
///
/// The grapheme in Seshat is not breakable code point sequence by Unicode
/// Grapheme cluster break algorithm.
class NotASingleCharacter : public std::exception {
public:
    const char* what() const noexcept
    {
        return "NotASingleCharacter: The sequence cannot be considered a single character.";
    }
};

} // namespace seshat

#endif /* _CHARACTER_H */
