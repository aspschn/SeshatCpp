/*
//  icu/name.h
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 22. 17:04
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode Name property function that using ICU backend.
*/
#ifndef _SESHAT_ICU_NAME_H
#define _SESHAT_ICU_NAME_H

#include <string>

#ifdef SESHAT_ICU_BACKEND
namespace seshat {
namespace unicode {
namespace icu {

const std::string name(uint32_t cp);

} // namespace icu
} // namespace unicode
} // namespace seshat
#endif // SESHAT_ICU_BACKEND

#endif /* _SESHAT_ICU_NAME_H */
