/*
//  tests/properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2018. 04. 05. 12:01
//  Copyright (c) 2018 Sophia Lee. All rights reserved.
//
// Test for Unicode properties.
*/
#include <catch.hpp>

#include <tinyxml2/tinyxml2.h>

#include <seshat/codepoint.h>
#include <seshat/unicode/name.h>
#include <seshat/unicode/normalization_props.h>
#include <seshat/unicode/properties.h>
#include <seshat/unicode/property_names.h>

#include <iostream>
#include <string>

#define UCD_XML_FILE "ucd.nounihan.flat.xml"

using namespace seshat;
using namespace seshat::unicode;

using namespace tinyxml2;
using namespace Catch;

static void print_error(const CodePoint& cp, const char *seshat_val,
        const char *prop, const char *val);
static bool check_properties(const CodePoint& cp, const XMLElement *elem);

static XMLDocument doc;
static XMLElement *ucd;
static XMLElement *repertoire;

TEST_CASE("properties")
{
    if (doc.NoChildren()) {
        doc.LoadFile(UCD_XML_FILE);
        ucd = doc.FirstChildElement("ucd");
        repertoire = ucd->FirstChildElement("repertoire");
    }

    bool passed = true;
    for (XMLElement *it = repertoire->FirstChildElement();
            it != nullptr;
            it = it->NextSiblingElement()) {
        // Element 'char'
        // Element 'surrogate'
        // Element 'noncharacter'
        // Element 'reserved'
        if (!passed) break;

        if (it->Attribute("cp")) {
            CodePoint cp(code_point_from_string(it->Attribute("cp")));
            passed = check_properties(cp, it);
        } else {
            CodePoint first_cp(
                code_point_from_string(it->Attribute("first-cp")));
            CodePoint last_cp(
                code_point_from_string(it->Attribute("last-cp")));
            for (uint32_t code = first_cp.code();
                    code <= last_cp.code();
                    ++code) {
                if (!passed) break;
                passed = check_properties(CodePoint(code), it);
            }
        }
    }
    REQUIRE(passed == true);
}

void print_error(const CodePoint& cp, const char *cp_val,
        const char *prop, const char *val)
{
    std::cout << "Wrong property for `" << prop << "`: "
        << cp.to_string() << std::endl;
    std::cout
        << "Seshat:  " << cp_val << "\n"
        << "Correct: " << val << std::endl;
}

bool check_properties(const CodePoint& cp, const XMLElement *elem)
{
    // kAccountingNumeric (cjkAccountingNumeric)   Unimplemented       
    // kOtherNumeric (cjkOtherNumeric)     Unimplemented       
    // kPrimaryNumeric (cjkPrimaryNumeric)     Unimplemented       
    // Numeric_Value (nv)  Unimplemented       
    // Case_Folding (cf)   Unimplemented       
    // kCompatibilityVariant (cjkCompatibilityVariant)     Unimplemented       
    // Decomposition_Mapping (dm)  Done    dm()    dm.h
    // FC_NFKC_Closure (FC_NFKC)   Unimplemented       
    // Lowercase_Mapping (lc)  Done    lowercase_mapping()     casing.h
    // NFKC_Casefold (NFKC_CF)     Unimplemented       
    // Simple_Case_Folding (scf)   Unimplemented       
    // Simple_Lowercase_Mapping (slc)  Done    simple_lowercase_mapping()  properties.h
    // Simple_Titlecase_Mapping (stc)  Done    simple_titlecase_mapping()  properties.h
    // Simple_Uppercase_Mapping (suc)  Done    simple_uppercase_mapping()  properties.h
    // Titlecase_Mapping (tc)  Done    titlecase_mapping()     casing.h
    // Uppercase_Mapping (uc)  Done    uppercase_mapping()     casing.h
    // Bidi_Mirroring_Glyph (bmg)  Unimplemented       
    // Bidi_Paired_Bracket (bpb)   Unimplemented       
    // kIICore (cjkIICore)     Unimplemented       
    // kIRG_GSource (cjkIRG_GSource)   Unimplemented       
    // kIRG_HSource (cjkIRG_HSource)   Unimplemented       
    // kIRG_JSource (cjkIRG_JSource)   Unimplemented       
    // kIRG_KPSource (cjkIRG_KPSource)     Unimplemented       
    // kIRG_KSource (cjkIRG_KSource)   Unimplemented       
    // kIRG_MSource (cjkIRG_MSource)   Unimplemented       
    // kIRG_TSource (cjkIRG_TSource)   Unimplemented       
    // kIRG_USource (cjkIRG_USource)   Unimplemented       
    // kIRG_VSource (cjkIRG_VSource)   Unimplemented       
    // kRSUnicode (cjkRSUnicode)   Unimplemented       
    // ISO_Comment (isc)   Unimplemented       
    // Jamo_Short_Name (JSN)   Unimplemented       
    // Name (na)   Done    name()  name.h
    #if 0
    std::string cp_name;
    try {
        cp_name = name(cp);
    } catch (const NoName& e) {
        cp_name = "";
    }
    std::string ucd_name = elem->Attribute("na");
    if (ucd_name.back() == '#') {
        ucd_name.pop_back();
        ucd_name += cp.to_string().substr(2);
    }
    if (cp_name != ucd_name) {
        print_error(cp, cp_name.c_str(), "na", elem->Attribute("na"));
        return false;
    }
    #endif
    // Unicode_1_Name (na1)    Unimplemented       
    // Name_Alias (Name_Alias)     Unimplemented       
    // Script_Extensions (scx)     Unimplemented       
    // Age (age)   Done    age()   properties.h
    // Block (blk)     Done    block()     properties.h
    std::string cp_blk = property_value_name(block(cp)).abbr;
    if (cp_blk != elem->Attribute("blk")) {
        print_error(cp, cp_blk.c_str(), "blk", elem->Attribute("blk"));
        return false;
    }
    // Script (sc)     Done    script()    properties.h
    std::string cp_sc = property_value_name(script(cp)).abbr;
    // std::cout << "Long: " << property_value_name(script(cp)).full << std::endl;
    // std::cout << "Abbr: " << property_value_name(script(cp)).abbr << std::endl;
    if (cp_sc != elem->Attribute("sc")) {
        print_error(cp, cp_sc.c_str(), "sc", elem->Attribute("sc"));
        return false;
    }
    // Bidi_Class (bc)     Unimplemented       
    // Bidi_Paired_Bracket_Type (bpt)  Unimplemented       
    // Canonical_Combining_Class (ccc)     Done    ccc()   properties.h
    // Decomposition_Type (dt)     Done    dt()    properties.h
    std::string cp_dt = property_value_name(dt(cp)).alt[0];
    if (cp_dt != elem->Attribute("dt")) {
        print_error(cp, cp_dt.c_str(), "dt", elem->Attribute("dt"));
        return false;
    }
    // East_Asian_Width (ea)   Unimplemented       
    // General_Category (gc)   Done    gc()    properties.h
    std::string cp_gc = property_value_name(gc(cp)).abbr;
    if (cp_gc != elem->Attribute("gc")) {
        print_error(cp, cp_gc.c_str(), "gc", elem->Attribute("gc"));
        return false;
    }
    // Grapheme_Cluster_Break (GCB)    Done    gcb()   properties.h
    std::string cp_gcb = property_value_name(gcb(cp)).abbr;
    if (cp_gcb != elem->Attribute("GCB")) {
        int get = static_cast<int>(gcb(cp));
        std::cout << "gcb(): " << get << std::endl;
        print_error(cp, cp_gcb.c_str(), "GCB", elem->Attribute("GCB"));
        return false;
    }
    // Hangul_Syllable_Type (hst)  Done    hangul_syllable_type()  hangul.h
    // Indic_Positional_Category (InPC)    Unimplemented       
    // Indic_Syllabic_Category (InSC)  Unimplemented       
    // Joining_Group (jg)  Unimplemented       
    // Joining_Type (jt)   Unimplemented       
    // Line_Break (lb)     Unimplemented       
    // NFC_Quick_Check (NFC_QC)    Done    nfc_qc()    normalization_props.h
    std::string cp_nfc_qc = property_value_name(nfc_qc(cp)).abbr;
    if (cp_nfc_qc != elem->Attribute("NFC_QC")) {
        print_error(cp, cp_nfc_qc.c_str(), "NFC_QC", elem->Attribute("NFC_QC"));
        return false;
    }
    // NFD_Quick_Check (NFD_QC)    Done    nfd_qc()    normalization_props.h
    std::string cp_nfd_qc = property_value_name(nfd_qc(cp)).abbr;
    if (cp_nfd_qc != elem->Attribute("NFD_QC")) {
        print_error(cp, cp_nfd_qc.c_str(), "NFD_QC", elem->Attribute("NFD_QC"));
        return false;
    }
    // NFKC_Quick_Check (NFKC_QC)  Done    nfkc_qc()   normalization_props.h
    std::string cp_nfkc_qc = property_value_name(nfkc_qc(cp)).abbr;
    if (cp_nfkc_qc != elem->Attribute("NFKC_QC")) {
        print_error(cp, cp_nfkc_qc.c_str(), "NFKC_QC", elem->Attribute("NFKC_QC"));
        return false;
    }
    // NFKD_Quick_Check (NFKD_QC)  Done    nfkd_qc()   normalization_props.h
    std::string cp_nfkd_qc = property_value_name(nfkd_qc(cp)).abbr;
    if (cp_nfkd_qc != elem->Attribute("NFKD_QC")) {
        print_error(cp, cp_nfkd_qc.c_str(), "NFKD_QC", elem->Attribute("NFKD_QC"));
        return false;
    }
    // Numeric_Type (nt)   Unimplemented       
    // Sentence_Break (SB)     Unimplemented       
    // Vertical_Orientation (vo)   Unimplemented       
    // Word_Break (WB)     Done    wb()    properties.h
    // ASCII_Hex_Digit (AHex)  Unimplemented       
    // Alphabetic (Alpha)  Unimplemented       
    // Bidi_Control (Bidi_C)   Unimplemented       
    // Bidi_Mirrored (Bidi_M)  Unimplemented       
    // Cased (Cased)   Done    cased()     properties.h
    // Composition_Exclusion (CE)  Unimplemented       
    // Case_Ignorable (CI)     Done    case_ignorable()    casing.h
    // Full_Composition_Exclusion (Comp_Ex)    Done    comp_ex()   normalization_props.h
    // Changes_When_Casefolded (CWCF)  Unimplemented       
    // Changes_When_Casemapped (CWCM)  Unimplemented       
    // Changes_When_NFKC_Casefolded (CWKCF)    Unimplemented       
    // Changes_When_Lowercased (CWL)   Unimplemented       
    // Changes_When_Titlecased (CWT)   Unimplemented       
    // Changes_When_Uppercased (CWU)   Unimplemented       
    // Dash (Dash)     Unimplemented       
    // Deprecated (Dep)    Unimplemented       
    // Default_Ignorable_Code_Point (DI)   Done    default_ignorable_code_point()  properties.h
    // Diacritic (Dia)     Unimplemented       
    // Extender (Ext)  Unimplemented       
    // Grapheme_Base (Gr_Base)     Unimplemented       
    // Grapheme_Extend (Gr_Ext)    Done    grapheme_extend()   properties.h
    // Grapheme_Link (Gr_Link)     Unimplemented       
    // Hex_Digit (Hex)     Unimplemented       
    // Hyphen (Hyphen)     Unimplemented       
    // ID_Continue (IDC)   Unimplemented       
    // Ideographic (Ideo)  Unimplemented       
    // ID_Start (IDS)  Unimplemented       
    // IDS_Binary_Operator (IDSB)  Unimplemented       
    // IDS_Trinary_Operator (IDST)     Unimplemented       
    // Join_Control (Join_C)   Unimplemented       
    // Logical_Order_Exception (LOE)   Unimplemented       
    // Lowercase (Lower)   Done    lowercase()     properties.h
    // Math (Math)     Unimplemented       
    // Noncharacter_Code_Point (NChar)     Unimplemented       
    // Other_Alphabetic (OAlpha)   Unimplemented       
    // Other_Default_Ignorable_Code_Point (ODI)    Done    odi()   properties.h
    // Other_Grapheme_Extend (OGr_Ext)     Done    ogr_ext()   properties.h
    // Other_ID_Continue (OIDC)    Unimplemented       
    // Other_ID_Start (OIDS)   Unimplemented       
    // Other_Lowercase (OLower)    Done    other_lowercase()   properties.h
    // Other_Math (OMath)  Unimplemented       
    // Other_Uppercase (OUpper)    Done    other_uppercase()   properties.h
    // Pattern_Syntax (Pat_Syn)    Unimplemented       
    // Pattern_White_Space (Pat_WS)    Unimplemented       
    // Prepended_Concatenation_Mark (PCM)  Done    prepended_concatenation_mark()  properties.h
    // Quotation_Mark (QMark)  Unimplemented       
    // Radical (Radical)   Unimplemented       
    // Regional_Indicator (RI)     Unimplemented       
    // Soft_Dotted (SD)    Unimplemented       
    // Sentence_Terminal (STerm)   Unimplemented       
    // Terminal_Punctuation (Term)     Unimplemented       
    // Unified_Ideograph (UIdeo)   Unimplemented       
    // Uppercase (Upper)   Done    uppercase()     properties.h
    // Variation_Selector (VS)     Done    variation_selector()    properties.h
    // White_Space (WSpace)    Done    white_space()   properties.h
    // XID_Continue (XIDC)     Unimplemented       
    // XID_Start (XIDS)    Unimplemented       
    // Expands_On_NFC (XO_NFC)     Unimplemented       
    // Expands_On_NFD (XO_NFD)     Unimplemented       
    // Expands_On_NFKC (XO_NFKC)   Unimplemented       
    // Expands_On_NFKD (XO_NFKD)   Unimplemented 
    return true;
}