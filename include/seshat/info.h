//
//  info.h
//
//  Author:     Sophia Lee
//  Created:    2018. 05. 31. 21:22
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Built-in informations like library version, etc.
#ifndef _SESHAT_INFO_H
#define _SESHAT_INFO_H

#include <string>

namespace seshat {

std::string get_seshat_version();

std::string get_unicode_version();

std::string get_emoji_version();

std::string get_compiler_name();

bool is_icu_backend();

std::string get_build_date();

} // namespace seshat

#endif /* _SESHAT_INFO_H */
