/*
//  name.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 22. 17:27
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include "name.h"

#ifdef SESHAT_ICU_BACKEND
#include <unicode/uchar.h>

namespace seshat {
namespace unicode {
namespace icu {

const std::string name(uint32_t cp)
{
    // Currently (Unicode 9), the longest name has length 83
    // (ARABIC LIGATURE UIGHUR KIRGHIZ YEH WITH HAMZA ABOVE WITH ALEF MAKSURA ISOLATED FORM)
    // , but this not specified in ICU API.
    // This unclarify could cause bug in the future.
    char buf[128];
    UErrorCode e;

    u_charName(static_cast<UChar32>(cp),
        U_UNICODE_CHAR_NAME, buf, 128, &e);
    return std::string(buf);
}

} // namespace icu
} // namespace unicode
} // namespace seshat
#endif // SESHAT_ICU_BACKEND
