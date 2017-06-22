/*
//  unicode/version.h
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 22. 16:02
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _SESHAT_UNICODE_VERSION_H
#define _SESHAT_UNICODE_VERSION_H

namespace seshat {
namespace unicode {

constexpr unsigned int UnicodeVersionMajor = 9;
constexpr unsigned int UnicodeVersionMinor = 0;
constexpr unsigned int UnicodeVersionUpdate = 0;

// Do not use the below macro constants since these are not intended
// to use currently.
// It could be deprecated in future version.
#define UNICODE_VERSION_MAJOR 9;
#define UNICODE_VERSION_MINOR 0;
#define UNICODE_VERSION_UPDATE 0;

namespace emoji {
    constexpr unsigned int EmojiVersionMajor = 4;
    constexpr unsigned int EmojiVersionMinor = 0;
} // namespace emoji

} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UNICODE_VERSION_H */
