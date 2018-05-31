/*
//  tools/seshatinfo.cpp
//
//  Author:     Sophia Lee
//  Created:    2018. 02. 17. 00:55
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//
//  Prints Seshat library informations.
*/
#include <seshat/info.h>

#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace seshat;
// using namespace seshat::unicode;

#if 0
namespace seshat {
    std::string version_to_string(const Version &ver, size_t max=3)
    {
        std::string ret = "";
        ret += std::to_string(ver.major);
        if (max >= 2)
            ret += std::string(".") + std::to_string(ver.minor);
        if (max >= 3)
            ret += std::string(".") + std::to_string(ver.update);
        return ret;
    }

    // Make build time as ISO 8601 formatted string in UTC.
    // SESHAT_TZ_OFFSET: 5 length string for current system's timezone offset.
    //      e.g. "+0900"
    //      Generally, compile with flag -DSESHAT_TZ_OFFSET=\"`date +%z`\".
    std::string buildtime()
    {
        std::tm t = {};
        std::string s = "";
        s += __DATE__; // Feb 16 2018
        s += " ";
        s += __TIME__; // 00:55:42 (in local time)
        s += " ";
        s += SESHAT_TZ_OFFSET;
        // Parse macro string to struct tm.
        strptime(s.c_str(), "%b %d %Y %H:%M:%S %z", &t);
        // Make local time to UTC.
        std::time_t utime = std::mktime(&t);
        std::tm *utc = gmtime(&utime);
        // Convert struct tm to ISO 8601 string.
        std::ostringstream oss;
        oss << std::put_time(utc, "%Y-%m-%dT%H:%M:%SZ");

        std::string out = oss.str();
        return out;
    }
}
#endif

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, std::string> info;

    info["seshat.version"] = get_seshat_version();
    info["seshat.icubackend"] = is_icu_backend() ? "true" : "false";
#ifdef SESHAT_ICU_BACKEND
    info["icu.version"] = "unknown";
#endif
    info["unicode.version"] = get_unicode_version();
    info["unicode.emoji"] = get_emoji_version();
    info["build.compiler"] = get_compiler_name();
    info["build.date"] = get_build_date();

    // Print informations.
    std::cout << "seshat.version=" << info["seshat.version"] << "\n"
        << "seshat.icubackend=" << info["seshat.icubackend"] << "\n"
        << "unicode.version=" << info["unicode.version"] << "\n"
        << "unicode.emoji=" << info["unicode.emoji"] << "\n"
        << "build.compiler=" << info["build.compiler"] << "\n"
        << "build.date=" << info["build.date"]
        << std::endl;

    return 0;
}
