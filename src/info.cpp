/*
//  info.cpp
//
//  Author:     Sophia Lee
//  Created:    2018. 05. 31. 21:41
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/info.h>

#include <seshat/unicode/version.h>

#include <string>

using namespace seshat;
using namespace seshat::unicode;

static std::string version_to_string(const Version &ver, size_t max=3);

namespace seshat {

std::string get_seshat_version()
{
    return "unknown";
}

std::string get_unicode_version()
{
    return version_to_string(UnicodeVersion, 3);
}

std::string get_emoji_version()
{
    return version_to_string(emoji::EmojiVersion, 2);
}

std::string get_compiler_name()
{
#if defined(__GNUC__) && !defined(__clang__)
    return "gcc";
#elif defined(__clang__)
    return "clang";
#else
    return "unknown";
#endif
}

bool is_icu_backend()
{
#ifdef SESHAT_ICU_BACKEND
    return true;
#else
    return false;
#endif
}

std::string get_build_date()
{
    return SESHAT_BUILD_DATE;
}

} // namespace seshat

std::string version_to_string(const Version &ver, size_t max)
{
    std::string ret = "";
    ret += std::to_string(ver.major);
    if (max >= 2)
        ret += std::string(".") + std::to_string(ver.minor);
    if (max >= 3)
        ret += std::string(".") + std::to_string(ver.update);
    return ret;
}