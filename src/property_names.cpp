/*
//  property_names.cpp
//
//  Author:     Sophia Lee
//  Created:    2018. 04. 06. 16:30
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/property_names.h>

#ifndef SESHAT_ICU_BACKEND
#include "ucd/property_names.h"
#else
#include "icu/property_names.h"
#endif // SESHAT_ICU_BACKEND

namespace seshat {
namespace unicode {

namespace implementation {
#ifndef SESHAT_ICU_BACKEND
    using namespace seshat::unicode::ucd;
#else
    using namespace seshat::unicode::icu;
#endif // SESHAT_ICU_BACKEND
} // namespace implementation

/*
PropertyValueName property_value_name(const Version& val)
{
    return implementation::property_value_name(val);
}
*/

PropertyValueName property_value_name(const Block& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(const Script& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(const Dt& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(const Gc& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(const Gcb& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(const QcValue& val)
{
    return implementation::property_value_name(val);
}

PropertyValueName property_value_name(bool val)
{
    return implementation::property_value_name(val);
}

} // namespace unicode
} // namespace seshat
