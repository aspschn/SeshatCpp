//
//  unicode/version.h
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 22. 16:02
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Version information of Unicode.
#ifndef _SESHAT_UNICODE_VERSION_H
#define _SESHAT_UNICODE_VERSION_H

#include <cstdint>

namespace seshat {
namespace unicode {

/// \brief  Struct for containing version information.
///
/// Lexicographical comparison is used for comparing operations.
struct Version {
    uint8_t major;
    uint8_t minor;
    uint8_t update;
};

/// \brief  Unicode major version.
constexpr uint8_t UnicodeVersionMajor = 10;
/// \brief  Unicode minor version.
constexpr uint8_t UnicodeVersionMinor = 0;
/// \brief  Unicode update version.
constexpr uint8_t UnicodeVersionUpdate = 0;

/// \brief  Unicode version that Seshat currently using.
constexpr Version UnicodeVersion = {
    UnicodeVersionMajor,
    UnicodeVersionMinor,
    UnicodeVersionUpdate
};

// Do not use the below macro constants since these are not intended
// to use currently.
// It could be deprecated in future version.
#define UNICODE_VERSION_MAJOR 10
#define UNICODE_VERSION_MINOR 0
#define UNICODE_VERSION_UPDATE 0
namespace emoji {
    /// \brief  Emoji major version.
    constexpr uint8_t EmojiVersionMajor = 5;
    /// \brief  Emoji minor version.
    constexpr uint8_t EmojiVersionMinor = 0;

    /// \brief  Emoji version that Seshat currently using.
    ///
    /// The update version is always 0 since there is no update version in
    /// Emoji specification.
    constexpr Version EmojiVersion = {
        EmojiVersionMajor,
        EmojiVersionMinor,
        0 // Not used
    };
} // namespace emoji

// Comparison operators for struct Version.
// Operations are defined as constexpr so can be used compile time assertion.
constexpr bool operator==(const Version& lhs, const Version& rhs)
{
    return (lhs.major == rhs.major &&
        lhs.minor == rhs.minor && lhs.update == rhs.update);
}

constexpr bool operator!=(const Version& lhs, const Version& rhs)
{
    return !(lhs == rhs);
}

constexpr bool operator<(const Version& lhs, const Version& rhs)
{
    return (lhs.major < rhs.major) ? true :
        ((lhs.major == rhs.major && lhs.minor < rhs.minor) ? true :
        ((lhs.minor == rhs.minor && lhs.update < rhs.update) ? true : false));
}

constexpr bool operator>(const Version& lhs, const Version& rhs)
{
    return ((lhs != rhs) && !(lhs < rhs));
}

constexpr bool operator<=(const Version& lhs, const Version& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

constexpr bool operator>=(const Version& lhs, const Version& rhs)
{
    return (lhs > rhs || lhs == rhs);
}

} // namespace unicode

using unicode::Version;

} // namespace seshat

#endif /* _SESHAT_UNICODE_VERSION_H */
