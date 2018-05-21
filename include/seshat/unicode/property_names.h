//
//  unicode/property_names.h
//
//  Author:     Sophia Lee
//  Created:    2018. 04. 06. 14:35
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Functions for optain Unicode properties and values name as string.
#ifndef _SESHAT_UNICODE_PROPERTY_NAMES_H
#define _SESHAT_UNICODE_PROPERTY_NAMES_H

#include <seshat/unicode/properties.h>
#include <seshat/unicode/normalization_props.h>

namespace seshat {
namespace unicode {

struct PropertyName {
    const char *full;
    const char *abbr;
    const char *alt[2]; // Currently maximum alternative aliases is 2.
                        // This may change in future.
};

using PropertyValueName = PropertyName;

// | kAccountingNumeric (cjkAccountingNumeric) | Unimplemented |                       |               |
// | kOtherNumeric (cjkOtherNumeric)   | Unimplemented |                               |               |
// | kPrimaryNumeric (cjkPrimaryNumeric) | Unimplemented |                             |               |
// | Numeric_Value (nv)                | Unimplemented |                               |               |
// | Case_Folding (cf)                 | Unimplemented |                               |               |
// | kCompatibilityVariant (cjkCompatibilityVariant) | Unimplemented |                 |               |
// | Decomposition_Mapping (dm)        | Done          | `dm()`                        | dm.h          |
    // property_value_name(Dm)
// | FC_NFKC_Closure (FC_NFKC)         | Unimplemented |                               |               |
// | Lowercase_Mapping (lc)            | Done          | `lowercase_mapping()`         | casing.h      |
    // property_value_name(lc)
// | NFKC_Casefold (NFKC_CF)           | Unimplemented |                               |               |
// | Simple_Case_Folding (scf)         | Unimplemented |                               |               |
// | Simple_Lowercase_Mapping (slc)    | Done          | `simple_lowercase_mapping()`  | properties.h  |
// | Simple_Titlecase_Mapping (stc)    | Done          | `simple_titlecase_mapping()`  | properties.h  |
// | Simple_Uppercase_Mapping (suc)    | Done          | `simple_uppercase_mapping()`  | properties.h  |
// | Titlecase_Mapping (tc)            | Done          | `titlecase_mapping()`         | casing.h      |
// | Uppercase_Mapping (uc)            | Done          | `uppercase_mapping()`         | casing.h      |
// | Bidi_Mirroring_Glyph (bmg)        | Unimplemented |                               |               |
// | Bidi_Paired_Bracket (bpb)         | Unimplemented |                               |               |
// | kIICore (cjkIICore)               | Unimplemented |                               |               |
// | kIRG_GSource (cjkIRG_GSource)     | Unimplemented |                               |               |
// | kIRG_HSource (cjkIRG_HSource)     | Unimplemented |                               |               |
// | kIRG_JSource (cjkIRG_JSource)     | Unimplemented |                               |               |
// | kIRG_KPSource (cjkIRG_KPSource)   | Unimplemented |                               |               |
// | kIRG_KSource (cjkIRG_KSource)     | Unimplemented |                               |               |
// | kIRG_MSource (cjkIRG_MSource)     | Unimplemented |                               |               |
// | kIRG_TSource (cjkIRG_TSource)     | Unimplemented |                               |               |
// | kIRG_USource (cjkIRG_USource)     | Unimplemented |                               |               |
// | kIRG_VSource (cjkIRG_VSource)     | Unimplemented |                               |               |
// | kRSUnicode (cjkRSUnicode)         | Unimplemented |                               |               |
// | ISO_Comment (isc)                 | Unimplemented |                               |               |
// | Jamo_Short_Name (JSN)             | Unimplemented |                               |               |
// | Name (na)                         | Done          | `name()`                      | name.h        |
// | Unicode_1_Name (na1)              | Unimplemented |                               |               |
// | Name_Alias (Name_Alias)           | Unimplemented |                               |               |
// | Script_Extensions (scx)           | Unimplemented |                               |               |
// | Age (age)                         | Done          | `age()`                       | properties.h  |
// PropertyValueName property_value_name(const Version &val);
// | Block (blk)                       | Done          | `block()`                     | properties.h  |
PropertyValueName property_value_name(const Block& val);
// | Script (sc)                       | Done          | `script()`                    | properties.h  |
PropertyValueName property_value_name(const Script& val);
// | Bidi_Class (bc)                   | Unimplemented |                               |               |
// | Bidi_Paired_Bracket_Type (bpt)    | Unimplemented |                               |               |
// | Canonical_Combining_Class (ccc)   | Done          | `ccc()`                       | properties.h  |
// | Decomposition_Type (dt)           | Done          | `dt()`                        | properties.h  |
PropertyValueName property_value_name(const Dt& val);
// | East_Asian_Width (ea)             | Unimplemented |                               |               |
// | General_Category (gc)             | Done          | `gc()`                        | properties.h  |
PropertyValueName property_value_name(const Gc& val);
// | Grapheme_Cluster_Break (GCB)      | Done          | `gcb()`                       | properties.h  |
PropertyValueName property_value_name(const Gcb& val);
// | Hangul_Syllable_Type (hst)        | Done          | `hangul_syllable_type()`      | hangul.h      |
// | Indic_Positional_Category (InPC)  | Unimplemented |                               |               |
// | Indic_Syllabic_Category (InSC)    | Unimplemented |                               |               |
// | Joining_Group (jg)                | Unimplemented |                               |               |
// | Joining_Type (jt)                 | Unimplemented |                               |               |
// | Line_Break (lb)                   | Unimplemented |                               |               |
// | NFC_Quick_Check (NFC_QC)          | Done          | `nfc_qc()`                    | normalization_props.h |
// | NFD_Quick_Check (NFD_QC)          | Done          | `nfd_qc()`                    | normalization_props.h |
// | NFKC_Quick_Check (NFKC_QC)        | Done          | `nfkc_qc()`                   | normalization_props.h |
// | NFKD_Quick_Check (NFKD_QC)        | Done          | `nfkd_qc()`                   | normalization_props.h |
PropertyValueName property_value_name(const QcValue& val);
// | Numeric_Type (nt)                 | Unimplemented |                               |               |
// | Sentence_Break (SB)               | Unimplemented |                               |               |
// | Vertical_Orientation (vo)         | Unimplemented |                               |               |
// | Word_Break (WB)                   | Done          | `wb()`                        | properties.h  |
// | ASCII_Hex_Digit (AHex)            | Unimplemented |                               |               |
// | Alphabetic (Alpha)                | Unimplemented |                               |               |
// | Bidi_Control (Bidi_C)             | Unimplemented |                               |               |
// | Bidi_Mirrored (Bidi_M)            | Unimplemented |                               |               |
// | Cased (Cased)                     | Done          | `cased()`                     | properties.h  |
// | Composition_Exclusion (CE)        | Unimplemented |                               |               |
// | Case_Ignorable (CI)               | Done          | `case_ignorable()`            | casing.h      |
// | Full_Composition_Exclusion (Comp_Ex) | Done       | `comp_ex()`                   | normalization_props.h |
// | Changes_When_Casefolded (CWCF)       | Unimplemented |                            |               |
// | Changes_When_Casemapped (CWCM)       | Unimplemented |                            |               |
// | Changes_When_NFKC_Casefolded (CWKCF) | Unimplemented |                            |               |
// | Changes_When_Lowercased (CWL)     | Unimplemented |                               |               |
// | Changes_When_Titlecased (CWT)     | Unimplemented |                               |               |
// | Changes_When_Uppercased (CWU)     | Unimplemented |                               |               |
// | Dash (Dash)                       | Unimplemented |                               |               |
// | Deprecated (Dep)                  | Unimplemented |                               |               |
// | Default_Ignorable_Code_Point (DI) | Done          | `default_ignorable_code_point()` | properties.h |
// | Diacritic (Dia)                   | Unimplemented |                               |               |
// | Extender (Ext)                    | Unimplemented |                               |               |
// | Grapheme_Base (Gr_Base)           | Unimplemented |                               |               |
// | Grapheme_Extend (Gr_Ext)          | Done          | `grapheme_extend()`           | properties.h  |
// | Grapheme_Link (Gr_Link)           | Unimplemented |                               |               |
// | Hex_Digit (Hex)                   | Unimplemented |                               |               |
// | Hyphen (Hyphen)                   | Unimplemented |                               |               |
// | ID_Continue (IDC)                 | Unimplemented |                               |               |
// | Ideographic (Ideo)                | Unimplemented |                               |               |
// | ID_Start (IDS)                    | Unimplemented |                               |               |
// | IDS_Binary_Operator (IDSB)        | Unimplemented |                               |               |
// | IDS_Trinary_Operator (IDST)       | Unimplemented |                               |               |
// | Join_Control (Join_C)             | Unimplemented |                               |               |
// | Logical_Order_Exception (LOE)     | Unimplemented |                               |               |
// | Lowercase (Lower)                 | Done          | `lowercase()`                 | properties.h  |
// | Math (Math)                       | Unimplemented |                               |               |
// | Noncharacter_Code_Point (NChar)   | Unimplemented |                               |               |
// | Other_Alphabetic (OAlpha)         | Unimplemented |                               |               |
// | Other_Default_Ignorable_Code_Point (ODI) | Done   | `odi()`                       | properties.h  |
// | Other_Grapheme_Extend (OGr_Ext)   | Done          | `ogr_ext()`                   | properties.h  |
// | Other_ID_Continue (OIDC)          | Unimplemented |                               |               |
// | Other_ID_Start (OIDS)             | Unimplemented |                               |               |
// | Other_Lowercase (OLower)          | Done          | `other_lowercase()`           | properties.h  |
// | Other_Math (OMath)                | Unimplemented |                               |               |
// | Other_Uppercase (OUpper)          | Done          | `other_uppercase()`           | properties.h  |
// | Pattern_Syntax (Pat_Syn)          | Unimplemented |                               |               |
// | Pattern_White_Space (Pat_WS)      | Unimplemented |                               |               |
// | Prepended_Concatenation_Mark (PCM) | Done         | `prepended_concatenation_mark()` | properties.h |
// | Quotation_Mark (QMark)            | Unimplemented |                               |               |
// | Radical (Radical)                 | Unimplemented |                               |               |
// | Regional_Indicator (RI)           | Unimplemented |                               |               |
// | Soft_Dotted (SD)                  | Unimplemented |                               |               |
// | Sentence_Terminal (STerm)         | Unimplemented |                               |               |
// | Terminal_Punctuation (Term)       | Unimplemented |                               |               |
// | Unified_Ideograph (UIdeo)         | Unimplemented |                               |               |
// | Uppercase (Upper)                 | Done          | `uppercase()`                 | properties.h  |
// | Variation_Selector (VS)           | Done          | `variation_selector()`        | properties.h  |
// | White_Space (WSpace)              | Done          | `white_space()`               | properties.h  |
// | XID_Continue (XIDC)               | Unimplemented |                               |               |
// | XID_Start (XIDS)                  | Unimplemented |                               |               |
// | Expands_On_NFC (XO_NFC)           | Unimplemented |                               |               |
// | Expands_On_NFD (XO_NFD)           | Unimplemented |                               |               |
// | Expands_On_NFKC (XO_NFKC)         | Unimplemented |                               |               |
// | Expands_On_NFKD (XO_NFKD)         | Unimplemented |                               |               |
PropertyValueName property_value_name(bool val);

} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UNICODE_PROPERTY_NAMES_H */
