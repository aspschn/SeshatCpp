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

#include <seshat/unicode/segmentation.h>

namespace seshat {

String::String()
    : _chars(decltype(_chars)())
{}

/*
String::String(std::initializer_list<Character> init)
    : _chars(decltype(_chars)())
{
}
*/

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

String::~String()
{}

auto String::count() const -> size_type
{
    return _chars.size();
}

} // namespace seshat
