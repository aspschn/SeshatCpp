/*
//  string.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 24. 13:03
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
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

} // namespace seshat
