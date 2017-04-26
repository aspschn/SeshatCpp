/*
//  unicode/name.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 25. 23:25
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Name property of unicode code points.
*/
#ifndef _UNICODE_NAME_H
#define _UNICODE_NAME_H

#include <cstdint>
#include <exception>
#include <string>

namespace seshat {
namespace unicode {

const std::string name(uint32_t cp);

class NoName : public std::exception {
public:
    const char* what() const noexcept
    {
        return "NoName: No such name for the code point.";
    }
};

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NAME_H */
