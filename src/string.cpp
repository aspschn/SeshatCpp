/*
//  string.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 24. 13:03
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/string.h>

#include <seshat/unicode/normalize.h>
#include <seshat/unicode/segmentation.h>

#include <utility>

namespace seshat {

String::String()
    : _chars(decltype(_chars)())
{}

String::String(const CodePointSequence& sequence)
    : _chars(decltype(_chars)())
{
    auto prev = sequence.begin();
    for (auto it = unicode::grapheme_bound(sequence.begin(), sequence.end());
        it != sequence.end();
        it = unicode::grapheme_bound(it + 1, sequence.end())) {
        CodePointSequence tmp(prev, it + 1);
        _chars.push_back(tmp);
        prev = it + 1; // move to next of 'it'
    }
}

String::String(std::initializer_list<CodePoint> init)
    : String(CodePointSequence(init))
{
}

// Convert 1 to 4 length UTF-8 characters to a code point.
// Return value for invalid characters is undefined. Check validity before
// calling this function.
uint32_t _code_point_from_utf8(const char *chrs, size_t len)
{
    uint32_t cp = 0;
    const uint8_t *bytes = reinterpret_cast<const uint8_t*>(chrs);

    if (len == 1) {
        cp = *bytes;
    } else if (len == 2) {
        cp |= ((*bytes & 0x1F) << 6) | (*(bytes + 1) & 0x3F);
    } else if (len == 3) {
        cp |= ((*bytes & 0x0F) << 12) | ((*(bytes + 1) & 0x3F) << 6)
            | (*(bytes + 2) & 0x3F);
    } else if (len == 4) {
        cp |= ((*bytes & 0x07) << 18) | ((*(bytes + 1) & 0x3F) << 12)
            | ((*(bytes + 2) & 0x3F) << 6) | (*(bytes + 3) & 0x3F);
    }

    return cp;
}

String::String(const char *str)
    : _chars(decltype(_chars)())
{
    for (const char *buf = str; *buf != '\0'; ++buf) {
        if ((*buf & 0x80) == 0x00) {
            insert(end(), static_cast<char>(*buf));
        } else if ((*buf & 0xE0) == 0xC0) {
            if ((*(buf + 1) & 0xC0) == 0x80) {
                insert(end(), CodePoint(_code_point_from_utf8(buf, 2)));
                buf += 1;
            } // else throw
        } else if ((*buf & 0xF0) == 0xE0) {
            if ((*(buf + 1) & 0xC0) == 0x80 && (*(buf + 2) & 0xC0) == 0x80) {
                insert(end(), CodePoint(_code_point_from_utf8(buf, 3)));
                buf += 2;
            } // else throw
        } else if ((*buf & 0xF8) == 0xF0) {
            if ((*(buf + 1) & 0xC0) == 0x80 && (*(buf + 2) & 0xC0) == 0x80 &&
                    (*(buf + 3) & 0xC0) == 0x80) {
                insert(end(), CodePoint(_code_point_from_utf8(buf, 4)));
                buf += 3;
            } // else throw
        } // else throw
    }
}

String::String(const String& origin)
    : _chars(origin._chars)
{}

String::String(String&& origin)
    : _chars(std::move(origin._chars))
{}

String::~String()
{}

CodePointSequence String::to_sequence() const
{
    CodePointSequence seq;
    for (auto& ch: _chars) {
        seq.insert(seq.end(), ch.sequence().begin(), ch.sequence().end());
    }
    return seq;
}

std::string String::to_utf8() const
{
    std::string s;
    for (auto& ch: _chars) {
        s += ch.to_utf8();
    }
    return s;
}

auto String::count() const -> size_type
{
    return _chars.size();
}

void String::clear() noexcept
{
    _chars.clear();
}

auto String::insert(const_iterator pos, const Character& chr) -> iterator
{
    if (pos == this->begin())
        return _chars.insert(pos, chr);

    auto before = pos - 1;
    auto seq = before->sequence();
    seq.insert(seq.end(), chr.sequence().begin(), chr.sequence().end());
    if (unicode::grapheme_bound(seq.begin(), seq.end()) != seq.end() - 1) {
        // Just insert if new character can be independent regardless
        // former character.
        return _chars.insert(pos, chr);
    } else {
        // Merge two characters if those can count as a single character
        _chars.at(before - _chars.begin()) = seq;
        return this->begin() + (before - _chars.begin());
    }
}

auto String::begin() -> iterator
{
    return _chars.begin();
}

auto String::begin() const -> const_iterator
{
    return _chars.begin();
}

auto String::end() -> iterator
{
    return _chars.end();
}

auto String::end() const -> const_iterator
{
    return _chars.end();
}

String& String::operator=(const String& origin)
{
    _chars = origin._chars;
    return *this;
}

String& String::operator=(String&& origin)
{
    _chars = std::move(origin._chars);
    return *this;
}

bool String::operator==(const String& other) const
{
    auto this_seq = this->to_sequence();
    auto othr_seq = other.to_sequence();

    return (unicode::nfd(this_seq) == unicode::nfd(othr_seq));
}

bool String::operator!=(const String& other) const
{
    return !(*this == other);
}

String& String::operator+=(const String& other)
{
    for (auto& chr: other._chars)
        this->insert(this->end(), chr);
    return *this;
}

String String::operator+(const String& other)
{
    auto ret = *this;
    for (auto& chr: other._chars)
        ret.insert(ret.end(), chr);
    return ret;
}

} // namespace seshat
