/*
//  ucd/core.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 15. 23:00
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_CORE_H
#define _UCD_CORE_H

#include <seshat/utils.h> // CodePointRange

#include <set>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::set<CodePointRange> wspace_table;
extern const std::set<CodePointRange> ogr_ext_table;
extern const std::set<CodePointRange> odi_table;
extern const std::set<CodePointRange> pcm_table;
extern const std::set<CodePointRange> olower_table;
extern const std::set<CodePointRange> oupper_table;
extern const std::set<CodePointRange> dash_table;
extern const std::set<CodePointRange> hyphen_table;
extern const std::set<CodePointRange> bidi_control_table;
extern const std::set<CodePointRange> join_control_table;
extern const std::set<CodePointRange> qmark_table;
extern const std::set<CodePointRange> term_table;
extern const std::set<CodePointRange> omath_table;
extern const std::set<CodePointRange> hex_table;
extern const std::set<CodePointRange> ahex_table;
extern const std::set<CodePointRange> oalpha_table;
extern const std::set<CodePointRange> ideographic_table;
extern const std::set<CodePointRange> diacritic_table;
extern const std::set<CodePointRange> extender_table;
extern const std::set<CodePointRange> nchar_table;
extern const std::set<CodePointRange> idsb_table;
extern const std::set<CodePointRange> idst_table;
extern const std::set<CodePointRange> radical_table;
extern const std::set<CodePointRange> uideo_table;
extern const std::set<CodePointRange> deprecated_table;
extern const std::set<CodePointRange> soft_dotted_table;
extern const std::set<CodePointRange> loe_table;
extern const std::set<CodePointRange> oids_table;
extern const std::set<CodePointRange> oidc_table;
extern const std::set<CodePointRange> sterm_table;
extern const std::set<CodePointRange> vs_table;
extern const std::set<CodePointRange> pat_ws_table;
extern const std::set<CodePointRange> pat_syn_table;
extern const std::set<CodePointRange> ri_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_CORE_H */
