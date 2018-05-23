Building documentation
----------------------
Add later.

Unicode coverage
----------------

### Properties

| Property                          | Status        | Function                      | Header        |
| --------------------------------- | ------------- | ----------------------------- | ------------- |
| kAccountingNumeric (cjkAccountingNumeric) | Unimplemented |                       |               |
| kOtherNumeric (cjkOtherNumeric)   | Unimplemented |                               |               |
| kPrimaryNumeric (cjkPrimaryNumeric) | Unimplemented |                             |               |
| Numeric_Value (nv)                | Unimplemented |                               |               |
| Case_Folding (cf)                 | Unimplemented |                               |               |
| kCompatibilityVariant (cjkCompatibilityVariant) | Unimplemented |                 |               |
| Decomposition_Mapping (dm)        | Done          | `dm()`                        | dm.h          |
| FC_NFKC_Closure (FC_NFKC)         | Unimplemented |                               |               |
| Lowercase_Mapping (lc)            | Done          | `lowercase_mapping()`         | casing.h      |
| NFKC_Casefold (NFKC_CF)           | Unimplemented |                               |               |
| Simple_Case_Folding (scf)         | Unimplemented |                               |               |
| Simple_Lowercase_Mapping (slc)    | Done          | `simple_lowercase_mapping()`  | properties.h  |
| Simple_Titlecase_Mapping (stc)    | Done          | `simple_titlecase_mapping()`  | properties.h  |
| Simple_Uppercase_Mapping (suc)    | Done          | `simple_uppercase_mapping()`  | properties.h  |
| Titlecase_Mapping (tc)            | Done          | `titlecase_mapping()`         | casing.h      |
| Uppercase_Mapping (uc)            | Done          | `uppercase_mapping()`         | casing.h      |
| Bidi_Mirroring_Glyph (bmg)        | Unimplemented |                               |               |
| Bidi_Paired_Bracket (bpb)         | Unimplemented |                               |               |
| kIICore (cjkIICore)               | Unimplemented |                               |               |
| kIRG_GSource (cjkIRG_GSource)     | Unimplemented |                               |               |
| kIRG_HSource (cjkIRG_HSource)     | Unimplemented |                               |               |
| kIRG_JSource (cjkIRG_JSource)     | Unimplemented |                               |               |
| kIRG_KPSource (cjkIRG_KPSource)   | Unimplemented |                               |               |
| kIRG_KSource (cjkIRG_KSource)     | Unimplemented |                               |               |
| kIRG_MSource (cjkIRG_MSource)     | Unimplemented |                               |               |
| kIRG_TSource (cjkIRG_TSource)     | Unimplemented |                               |               |
| kIRG_USource (cjkIRG_USource)     | Unimplemented |                               |               |
| kIRG_VSource (cjkIRG_VSource)     | Unimplemented |                               |               |
| kRSUnicode (cjkRSUnicode)         | Unimplemented |                               |               |
| ISO_Comment (isc)                 | Unimplemented |                               |               |
| Jamo_Short_Name (JSN)             | Unimplemented |                               |               |
| Name (na)                         | Done          | `name()`                      | name.h        |
| Unicode_1_Name (na1)              | Unimplemented |                               |               |
| Name_Alias (Name_Alias)           | Unimplemented |                               |               |
| Script_Extensions (scx)           | Unimplemented |                               |               |
| Age (age)                         | Done          | `age()`                       | properties.h  |
| Block (blk)                       | Done          | `block()`                     | properties.h  |
| Script (sc)                       | Done          | `script()`                    | properties.h  |
| Bidi_Class (bc)                   | Unimplemented |                               |               |
| Bidi_Paired_Bracket_Type (bpt)    | Unimplemented |                               |               |
| Canonical_Combining_Class (ccc)   | Done          | `ccc()`                       | properties.h  |
| Decomposition_Type (dt)           | Done          | `dt()`                        | properties.h  |
| East_Asian_Width (ea)             | Unimplemented |                               |               |
| General_Category (gc)             | Done          | `gc()`                        | properties.h  |
| Grapheme_Cluster_Break (GCB)      | Done          | `gcb()`                       | properties.h  |
| Hangul_Syllable_Type (hst)        | Done          | `hangul_syllable_type()`      | hangul.h      |
| Indic_Positional_Category (InPC)  | Unimplemented |                               |               |
| Indic_Syllabic_Category (InSC)    | Unimplemented |                               |               |
| Joining_Group (jg)                | Unimplemented |                               |               |
| Joining_Type (jt)                 | Unimplemented |                               |               |
| Line_Break (lb)                   | Unimplemented |                               |               |
| NFC_Quick_Check (NFC_QC)          | Done          | `nfc_qc()`                    | normalization_props.h |
| NFD_Quick_Check (NFD_QC)          | Done          | `nfd_qc()`                    | normalization_props.h |
| NFKC_Quick_Check (NFKC_QC)        | Done          | `nfkc_qc()`                   | normalization_props.h |
| NFKD_Quick_Check (NFKD_QC)        | Done          | `nfkd_qc()`                   | normalization_props.h |
| Numeric_Type (nt)                 | Unimplemented |                               |               |
| Sentence_Break (SB)               | Unimplemented |                               |               |
| Vertical_Orientation (vo)         | Unimplemented |                               |               |
| Word_Break (WB)                   | Done          | `wb()`                        | properties.h  |
| ASCII_Hex_Digit (AHex)            | Done          | `ascii_hex_digit()`           | properties.h  |
| Alphabetic (Alpha)                | Done          | `alphabetic()`                | properties.h  |
| Bidi_Control (Bidi_C)             | Done          | `bidi_control()`              | properties.h  |
| Bidi_Mirrored (Bidi_M)            | Unimplemented |                               |               |
| Cased (Cased)                     | Done          | `cased()`                     | properties.h  |
| Composition_Exclusion (CE)        | Unimplemented |                               |               |
| Case_Ignorable (CI)               | Done          | `case_ignorable()`            | casing.h      |
| Full_Composition_Exclusion (Comp_Ex) | Done       | `comp_ex()`                   | normalization_props.h |
| Changes_When_Casefolded (CWCF)       | Unimplemented |                            |               |
| Changes_When_Casemapped (CWCM)       | Unimplemented |                            |               |
| Changes_When_NFKC_Casefolded (CWKCF) | Unimplemented |                            |               |
| Changes_When_Lowercased (CWL)     | Unimplemented |                               |               |
| Changes_When_Titlecased (CWT)     | Unimplemented |                               |               |
| Changes_When_Uppercased (CWU)     | Unimplemented |                               |               |
| Dash (Dash)                       | Done          | `dash()`                      | properties.h  |
| Deprecated (Dep)                  | Done          | `deprecated()`                | properties.h  |
| Default_Ignorable_Code_Point (DI) | Done          | `default_ignorable_code_point()` | properties.h |
| Diacritic (Dia)                   | Done          | `diacritic()`                 |               |
| Extender (Ext)                    | Done          | `extender()`                  | properties.h  |
| Grapheme_Base (Gr_Base)           | Unimplemented |                               |               |
| Grapheme_Extend (Gr_Ext)          | Done          | `grapheme_extend()`           | properties.h  |
| Grapheme_Link (Gr_Link)           | Unimplemented |                               |               |
| Hex_Digit (Hex)                   | Done          | `hex_digit()`                 | properties.h  |
| Hyphen (Hyphen)                   | Done          | `hyphen()`                    | properties.h  |
| ID_Continue (IDC)                 | Done          | `id_continue()`               | properties.h  |
| Ideographic (Ideo)                | Done          | `ideographic()`               | properties.h  |
| ID_Start (IDS)                    | Done          | `id_start()`                  | properties.h  |
| IDS_Binary_Operator (IDSB)        | Done          | `ids_binary_operator()`       | properties.h  |
| IDS_Trinary_Operator (IDST)       | Done          | `ids_trinary_operator()`      | properties.h  |
| Join_Control (Join_C)             | Done          | `join_control()`              | properties.h  |
| Logical_Order_Exception (LOE)     | Done          | `logical_order_exception()`   | properties.h  |
| Lowercase (Lower)                 | Done          | `lowercase()`                 | properties.h  |
| Math (Math)                       | Done          | `math()`                      | properties.h  |
| Noncharacter_Code_Point (NChar)   | Done          | `nchar()`                     | properties.h  |
| Other_Alphabetic (OAlpha)         | Done          | `oalpha()`                    | properties.h  |
| Other_Default_Ignorable_Code_Point (ODI) | Done   | `odi()`                       | properties.h  |
| Other_Grapheme_Extend (OGr_Ext)   | Done          | `ogr_ext()`                   | properties.h  |
| Other_ID_Continue (OIDC)          | Done          | `oidc()`                      | properties.h  |
| Other_ID_Start (OIDS)             | Done          | `oids()`                      | properties.h  |
| Other_Lowercase (OLower)          | Done          | `other_lowercase()`           | properties.h  |
| Other_Math (OMath)                | Done          | `other_math()`                | properties.h  |
| Other_Uppercase (OUpper)          | Done          | `other_uppercase()`           | properties.h  |
| Pattern_Syntax (Pat_Syn)          | Done          | `pattern_syntax()`            | properties.h  |
| Pattern_White_Space (Pat_WS)      | Done          | `pattern_white_space()`       | properties.h  |
| Prepended_Concatenation_Mark (PCM) | Done         | `prepended_concatenation_mark()` | properties.h |
| Quotation_Mark (QMark)            | Done          | `quotation_mark()`            | properties.h  |
| Radical (Radical)                 | Done          | `radical()`                   | properties.h  |
| Regional_Indicator (RI)           | Done          | `regional_indicator()`        | properties.h  |
| Soft_Dotted (SD)                  | Done          | `soft_dotted()`               | properties.h  |
| Sentence_Terminal (STerm)         | Done          | `sentence_terminal()`         | properties.h  |
| Terminal_Punctuation (Term)       | Done          | `terminal_punctuation()`      | properties.h  |
| Unified_Ideograph (UIdeo)         | Done          | `unified_ideograph()`         | properties.h  |
| Uppercase (Upper)                 | Done          | `uppercase()`                 | properties.h  |
| Variation_Selector (VS)           | Done          | `variation_selector()`        | properties.h  |
| White_Space (WSpace)              | Done          | `white_space()`               | properties.h  |
| XID_Continue (XIDC)               | Unimplemented |                               |               |
| XID_Start (XIDS)                  | Unimplemented |                               |               |
| Expands_On_NFC (XO_NFC)           | Unimplemented |                               |               |
| Expands_On_NFD (XO_NFD)           | Unimplemented |                               |               |
| Expands_On_NFKC (XO_NFKC)         | Unimplemented |                               |               |
| Expands_On_NFKD (XO_NFKD)         | Unimplemented |                               |               |