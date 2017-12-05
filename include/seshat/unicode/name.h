//
//  unicode/name.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 25. 23:25
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Name property of unicode code points.
#ifndef _UNICODE_NAME_H
#define _UNICODE_NAME_H

#include <seshat/codepoint.h>

#include <cstdint>
#include <exception>
#include <string>

namespace seshat {
namespace unicode {

/// \brief  Get the Unicode property character property Name if exists.
const std::string name(CodePoint cp);

/// \brief  Thrown when there is no Name property for certain code point.
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
