//
//  string.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 24. 12:52
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//                2019 Gene Ryu. All rights reserved.
//

/// \file
/// \brief  A natural string.
#ifndef _SESHAT_STRING_H
#define _SESHAT_STRING_H

#include <seshat/codepoint.h>
#include <seshat/character.h>

#include <initializer_list>
#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
/*=================*/
/* C               */
/*=================*/
struct sh_string {
    sh_character *characters;
    size_t len;
    size_t capacity;
};
typedef struct sh_string sh_string;

sh_string* sh_string_new();
sh_string* sh_string_from_c_string(const char *c_cst, size_t len);
void sh_string_push(sh_string *str, const sh_character *ch);
void sh_string_copy(sh_string *str, const sh_string *other);
void sh_string_free(sh_string *str);

#ifdef __cplusplus
};
#endif

#ifdef __cplusplus
namespace seshat {

/// \brief  A natural string that consists with zero or more characters.
class String {
private:
    std::vector<Character> _chars;
public:
    using size_type = decltype(_chars)::size_type;
    using iterator = decltype(_chars)::iterator;
    using const_iterator = decltype(_chars)::const_iterator;

    //==-----------------------
    // Constructor/Destructor
    //==-----------------------

    /// \brief  Consturct an empty String.
    String();

    /// \brief  Construct with code point sequence.
    String(const CodePointSequence& sequence);

    /// \brief  Construct with initializer list of CodePoint.
    String(std::initializer_list<CodePoint> init);

    /// \brief  Construct with null-terminated C character string.
    ///
    /// Currently, this constructor works properly only on UTF-8 systems.
    String(const char *str);

    /// \brief  Copy constructor.
    String(const String& origin);

    /// \brief  Move constructor.
    String(String&& origin);

    ~String();

    //==----------------------
    // Element access
    //==----------------------

    /// \brief  Returns a copy of the sequence of code points the String
    ///         contains.
    CodePointSequence to_sequence() const;

    /// \brief  Make the String to UTF-8 encoded std string.
    std::string to_utf8() const;

    /// \brief  Count it's characters.
    ///
    /// Count characters is not same as count code points, encoded bytes, etc.
    /// It only counts graphems, and there is no limit to a grapheme can
    /// contains.
    size_type count() const;

    //==--------------------------------
    // Modify
    //==--------------------------------

    /// \brief  Deletes all characters.
    void clear() noexcept;

    /// \brief  Insert a Character at the position.
    /// \param  pos
    ///         Iterator to the next of the Character will be inserted.
    /// \param  chr
    ///         A Character will be inserted.
    ///
    /// The character will be inserted before of the given position.
    iterator insert(const_iterator pos, const Character& chr);

    //==--------------------------
    // Iterator
    //==--------------------------

    /// \brief  Returns an iterator to the first character.
    iterator begin();

    /// \brief  Returns an iterator to the first character.
    const_iterator begin() const;

    /// \brief  Returns an iterator to the past the last character.
    iterator end();

    /// \brief  Returns an iterator to the past the last character.
    const_iterator end() const;

    //==-------------------------
    // Modify
    //==-------------------------

    /// \brief  Copy assignment operator.
    String& operator=(const String& origin);

    /// \brief  Move assignment operator.
    String& operator=(String&& origin);

    /// \brief  Replaces contents with null-terminated C character string.
    String& operator=(const char *str);

    //==-----------------------------
    // Comparison
    //==-----------------------------

    /// \brief  Returns true if two Strings contain the same values.
    bool operator==(const String& other) const;

    /// \brief  Returns true if two Strings contain the different values.
    bool operator!=(const String& other) const;

    //==----------------------------
    // Modify
    //==----------------------------

    /// \brief  Append other string to the end of string.
    String& operator+=(const String& other);

    /// \brief  Make new String joined two Strings.
    String operator+(const String& other);
};

} // namespace seshat
#endif /* __cplusplus */

#endif /* _SESHAT_STRING_H */
