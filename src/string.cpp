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

auto String::count() const -> size_type
{
    return _chars.size();
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
    CodePointSequence this_seq;
    CodePointSequence othr_seq;

    for (auto ch: this->_chars) {
        this_seq.insert(this_seq.end(),
            ch.sequence().begin(), ch.sequence().end());
    }
    for (auto ch: other._chars) {
        othr_seq.insert(othr_seq.end(),
            ch.sequence().begin(), ch.sequence().end());
    }

    return (unicode::nfd(this_seq) == unicode::nfd(othr_seq));
}

bool String::operator!=(const String& other) const
{
    return !(*this == other);
}

} // namespace seshat
