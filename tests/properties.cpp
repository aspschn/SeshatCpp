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
    // Bidi_Class (bc) - bidi_class() @properties.h
    /*
    std::string cp_bc = property_value_name(bidi_class(cp)).alt[0];
    if (cp_bc != elem->Attribute("bc")) {
        print_error(cp, cp_bc.c_str(), "bc", elem->Attribute("bc"));
        return false;
    }
    */
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
    #if 0
    std::string cp_wb = property_value_name(wb(cp)).abbr;
    if (cp_wb != elem->Attribute("WB")) {
        print_error(cp, cp_wb.c_str(), "WB", elem->Attribute("WB"));
        return false;
    }
    #endif
    // ASCII_Hex_Digit (AHex) - ascii_hex_digit() @properties.h
    std::string cp_ahex = property_value_name(ascii_hex_digit(cp)).abbr;
    if (cp_ahex != elem->Attribute("AHex")) {
        print_error(cp, cp_ahex.c_str(), "AHex", elem->Attribute("AHex"));
        return false;
    }
    // Alphabetic (Alpha) - alphabetic() @properties.h
    /*
    std::string cp_alpha = property_value_name(alphabetic(cp)).abbr;
    if (cp_alpha != elem->Attribute("Alpha")) {
        print_error(cp, cp_alpha.c_str(), "Alpha", elem->Attribute("Alpha"));
        return false;
    }
    */
    // Bidi_Control (Bidi_C)   Unimplemented       
    std::string cp_bidi_c = property_value_name(bidi_control(cp)).abbr;
    if (cp_bidi_c != elem->Attribute("Bidi_C")) {
        print_error(cp, cp_bidi_c.c_str(), "Bidi_C", elem->Attribute("Bidi_C"));
        return false;
    }
    // Bidi_Mirrored (Bidi_M)
    /*
    std::string cp_bidi_m = property_value_name(bidi_mirrored(cp)).abbr;
    if (cp_bidi_m != elem->Attribute("Bidi_M")) {
        print_error(cp, cp_bidi_m.c_str(), "Bidi_M", elem->Attribute("Bidi_M"));
        return false;
    }
    */
    // Cased (Cased) - cased() @properties.h
    std::string cp_cased = property_value_name(cased(cp)).abbr;
    if (cp_cased != elem->Attribute("Cased")) {
        print_error(cp, cp_cased.c_str(), "Cased", elem->Attribute("Cased"));
        return false;
    }
    // Composition_Exclusion (CE)  Unimplemented       
    // Case_Ignorable (CI)     Done    case_ignorable()    casing.h
    // Full_Composition_Exclusion (Comp_Ex)    Done    comp_ex()   normalization_props.h
    // Changes_When_Casefolded (CWCF)  Unimplemented       
    // Changes_When_Casemapped (CWCM)  Unimplemented       
    // Changes_When_NFKC_Casefolded (CWKCF)    Unimplemented       
    // Changes_When_Lowercased (CWL)   Unimplemented       
    // Changes_When_Titlecased (CWT)   Unimplemented       
    // Changes_When_Uppercased (CWU)   Unimplemented       
    // Dash (Dash) - dash() @properties.h
    std::string cp_dash = property_value_name(dash(cp)).abbr;
    if (cp_dash != elem->Attribute("Dash")) {
        print_error(cp, cp_dash.c_str(), "Dash", elem->Attribute("Dash"));
        return false;
    }
    // Deprecated (Dep) - deprecated @properties.h
    std::string cp_dep = property_value_name(deprecated(cp)).abbr;
    if (cp_dep != elem->Attribute("Dep")) {
        print_error(cp, cp_dep.c_str(), "Dep", elem->Attribute("Dep"));
        return false;
    }
    // Default_Ignorable_Code_Point (DI) - default_ignorable_code_point() @properties.h
    std::string cp_di = property_value_name(default_ignorable_code_point(cp)).abbr;
    if (cp_di != elem->Attribute("DI")) {
        print_error(cp, cp_di.c_str(), "DI", elem->Attribute("DI"));
        return false;
    }
    // Diacritic (Dia) - diacritic() @properties.h
    std::string cp_dia = property_value_name(diacritic(cp)).abbr;
    if (cp_dia != elem->Attribute("Dia")) {
        print_error(cp, cp_dia.c_str(), "Dia", elem->Attribute("Dia"));
        return false;
    }
    // Extender (Ext) - extender() @properties.h
    std::string cp_ext = property_value_name(extender(cp)).abbr;
    if (cp_ext != elem->Attribute("Ext")) {
        print_error(cp, cp_ext.c_str(), "Ext", elem->Attribute("Ext"));
        return false;
    }
    // Grapheme_Base (Gr_Base)     Unimplemented       
    // Grapheme_Extend (Gr_Ext)    Done    grapheme_extend()   properties.h
    // Grapheme_Link (Gr_Link)     Unimplemented       
    // Hex_Digit (Hex) - hex_digit() @properties.h
    std::string cp_hex = property_value_name(hex_digit(cp)).abbr;
    if (cp_hex != elem->Attribute("Hex")) {
        print_error(cp, cp_hex.c_str(), "Hex", elem->Attribute("Hex"));
        return false;
    }
    // Hyphen (Hyphen) - hyphen() @properties.h
    std::string cp_hyphen = property_value_name(hyphen(cp)).abbr;
    if (cp_hyphen != elem->Attribute("Hyphen")) {
        print_error(cp, cp_hyphen.c_str(), "Hyphen", elem->Attribute("Hyphen"));
        return false;
    }
    // ID_Continue (IDC)   Unimplemented       
    // Ideographic (Ideo)  Unimplemented       
    std::string cp_ideo = property_value_name(ideographic(cp)).abbr;
    if (cp_ideo != elem->Attribute("Ideo")) {
        print_error(cp, cp_ideo.c_str(), "Ideo", elem->Attribute("Ideo"));
        return false;
    }
    // ID_Start (IDS)  Unimplemented       
    // IDS_Binary_Operator (IDSB) - idsb() @properties.h
    std::string cp_idsb = property_value_name(ids_binary_operator(cp)).abbr;
    if (cp_idsb != elem->Attribute("IDSB")) {
        print_error(cp, cp_idsb.c_str(), "IDSB", elem->Attribute("IDSB"));
        return false;
    }
    // IDS_Trinary_Operator (IDST) - idst() @properties.h
    std::string cp_idst = property_value_name(ids_trinary_operator(cp)).abbr;
    if (cp_idst != elem->Attribute("IDST")) {
        print_error(cp, cp_idst.c_str(), "IDST", elem->Attribute("IDST"));
        return false;
    }
    // Join_Control (Join_C) - join_control() @properties.h
    std::string cp_join_c = property_value_name(join_control(cp)).abbr;
    if (cp_join_c != elem->Attribute("Join_C")) {
        print_error(cp, cp_join_c.c_str(), "Join_C", elem->Attribute("Join_C"));
        return false;
    }
    // Logical_Order_Exception (LOE) - loe() @properties.h
    std::string cp_loe = property_value_name(logical_order_exception(cp)).abbr;
    if (cp_loe != elem->Attribute("LOE")) {
        print_error(cp, cp_loe.c_str(), "LOE", elem->Attribute("LOE"));
        return false;
    }
    // Lowercase (Lower)   Done    lowercase()     properties.h
    // Math (Math) - math() @properties.h
    std::string cp_math = property_value_name(math(cp)).abbr;
    if (cp_math != elem->Attribute("Math")) {
        print_error(cp, cp_math.c_str(), "Math", elem->Attribute("Math"));
        return false;
    }
    // Noncharacter_Code_Point (NChar) - nchar() @properties.h
    std::string cp_nchar = property_value_name(nchar(cp)).abbr;
    if (cp_nchar != elem->Attribute("NChar")) {
        print_error(cp, cp_nchar.c_str(), "NChar", elem->Attribute("NChar"));
        return false;
    }
    // Other_Alphabetic (OAlpha)   Unimplemented       
    std::string cp_oalpha = property_value_name(oalpha(cp)).abbr;
    if (cp_oalpha != elem->Attribute("OAlpha")) {
        print_error(cp, cp_oalpha.c_str(), "OAlpha", elem->Attribute("OAlpha"));
        return false;
    }
    // Other_Default_Ignorable_Code_Point (ODI)    Done    odi()   properties.h
    // Other_Grapheme_Extend (OGr_Ext)     Done    ogr_ext()   properties.h
    // Other_ID_Continue (OIDC)    Unimplemented       
    std::string cp_oidc = property_value_name(oidc(cp)).abbr;
    if (cp_oidc != elem->Attribute("OIDC")) {
        print_error(cp, cp_oidc.c_str(), "OIDC", elem->Attribute("OIDC"));
        return false;
    }
    // Other_ID_Start (OIDS) - oids() @properties.h
    std::string cp_oids = property_value_name(oids(cp)).abbr;
    if (cp_oids != elem->Attribute("OIDS")) {
        print_error(cp, cp_oids.c_str(), "OIDS", elem->Attribute("OIDS"));
        return false;
    }
    // Other_Lowercase (OLower)    Done    other_lowercase()   properties.h
    // Other_Math (OMath)  Unimplemented       
    std::string cp_omath = property_value_name(other_math(cp)).abbr;
    if (cp_omath != elem->Attribute("OMath")) {
        print_error(cp, cp_omath.c_str(), "OMath", elem->Attribute("OMath"));
        return false;
    }
    // Other_Uppercase (OUpper)    Done    other_uppercase()   properties.h
    // Pattern_Syntax (Pat_Syn)    Unimplemented       
    std::string cp_pat_syn = property_value_name(pattern_syntax(cp)).abbr;
    if (cp_pat_syn != elem->Attribute("Pat_Syn")) {
        print_error(cp, cp_pat_syn.c_str(), "Pat_Syn", elem->Attribute("Pat_Syn"));
        return false;
    }
    // Pattern_White_Space (Pat_WS)    Unimplemented       
    std::string cp_pat_ws = property_value_name(pattern_white_space(cp)).abbr;
    if (cp_pat_ws != elem->Attribute("Pat_WS")) {
        print_error(cp, cp_pat_ws.c_str(), "Pat_WS", elem->Attribute("Pat_WS"));
        return false;
    }
    // Prepended_Concatenation_Mark (PCM)  Done    prepended_concatenation_mark()  properties.h
    std::string cp_pcm = property_value_name(prepended_concatenation_mark(cp)).abbr;
    if (cp_pcm != elem->Attribute("PCM")) {
        print_error(cp, cp_pcm.c_str(), "PCM", elem->Attribute("PCM"));
        return false;
    }
    // Quotation_Mark (QMark)  Unimplemented       
    std::string cp_qmark = property_value_name(quotation_mark(cp)).abbr;
    if (cp_qmark != elem->Attribute("QMark")) {
        print_error(cp, cp_qmark.c_str(), "QMark", elem->Attribute("QMark"));
        return false;
    }
    // Radical (Radical)   Unimplemented       
    std::string cp_radical = property_value_name(radical(cp)).abbr;
    if (cp_radical != elem->Attribute("Radical")) {
        print_error(cp, cp_radical.c_str(), "Radical", elem->Attribute("Radical"));
        return false;
    }
    // Regional_Indicator (RI)     Unimplemented       
    std::string cp_ri = property_value_name(regional_indicator(cp)).abbr;
    if (cp_ri != elem->Attribute("RI")) {
        print_error(cp, cp_ri.c_str(), "RI", elem->Attribute("RI"));
        return false;
    }
    // Soft_Dotted (SD)    Unimplemented       
    std::string cp_sd = property_value_name(soft_dotted(cp)).abbr;
    if (cp_sd != elem->Attribute("SD")) {
        print_error(cp, cp_sd.c_str(), "SD", elem->Attribute("SD"));
        return false;
    }
    // Sentence_Terminal (STerm)   Unimplemented       
    std::string cp_sterm = property_value_name(sentence_terminal(cp)).abbr;
    if (cp_sterm != elem->Attribute("STerm")) {
        print_error(cp, cp_sterm.c_str(), "STerm", elem->Attribute("STerm"));
        return false;
    }
    // Terminal_Punctuation (Term)     Unimplemented       
    std::string cp_term = property_value_name(terminal_punctuation(cp)).abbr;
    if (cp_term != elem->Attribute("Term")) {
        print_error(cp, cp_term.c_str(), "Term", elem->Attribute("Term"));
        return false;
    }
    // Unified_Ideograph (UIdeo)   Unimplemented       
    std::string cp_uideo = property_value_name(unified_ideograph(cp)).abbr;
    if (cp_uideo != elem->Attribute("UIdeo")) {
        print_error(cp, cp_uideo.c_str(), "UIdeo", elem->Attribute("UIdeo"));
        return false;
    }
    // Uppercase (Upper)   Done    uppercase()     properties.h
    // Variation_Selector (VS)     Done    variation_selector()    properties.h
    std::string cp_vs = property_value_name(variation_selector(cp)).abbr;
    if (cp_vs != elem->Attribute("VS")) {
        print_error(cp, cp_vs.c_str(), "VS", elem->Attribute("VS"));
        return false;
    }
    // White_Space (WSpace)    Done    white_space()   properties.h
    std::string cp_wspace = property_value_name(white_space(cp)).abbr;
    if (cp_wspace != elem->Attribute("WSpace")) {
        print_error(cp, cp_wspace.c_str(), "WSpace", elem->Attribute("WSpace"));
        return false;
    }
    // XID_Continue (XIDC)     Unimplemented       
    // XID_Start (XIDS)    Unimplemented       
    // Expands_On_NFC (XO_NFC)     Unimplemented       
    // Expands_On_NFD (XO_NFD)     Unimplemented       
    // Expands_On_NFKC (XO_NFKC)   Unimplemented       
    // Expands_On_NFKD (XO_NFKD)   Unimplemented 
    return true;
}