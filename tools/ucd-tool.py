#!/usr/bin/env python3
# Unicode Character Data tool that download, parse the database files
# from http://www.unicode.org/Public/UNIDATA
import sys
import os

class Gc:
    '''General_Category'''
    C = 'Other'
    Cc = 'Control' # 'cntrl'
    Cf = 'Format'
    Cn = 'Unassigned'
    Co = 'Private_Use'
    Cs = 'Surrogate'

    L = 'Letter'
    LC = 'Cased_Letter' # Ll | Lt | Lu
    Ll = 'Lowercase_Letter'
    Lm = 'Modifier_Letter'
    Lo = 'Other_Letter'
    Lt = 'Titlecase_Letter'
    Lu = 'Uppercase_Letter'

    M = 'Mark' # 'Combining_Mark' # Mc | Me | Mn
    Mc = 'Spacing_Mark'
    Me = 'Enclosing_Mark'
    Mn = 'Nonspacing_Mark'

    N = 'Number' # Nd | Nl | No
    Nd = 'Decimal_Number' # 'digit'
    Nl = 'Letter_Number'
    No = 'Other_Number'

    P = 'Punctuation' # 'punct' # Pc | Pd | Pe | Pf | Pi | Po | Ps
    Pc = 'Connector_Punctuation'
    Pd = 'Dash_Punctuation'
    Pe = 'Close_Punctuation'
    Pf = 'Final_Punctuation'
    Pi = 'Initial_Punctuation'
    Po = 'Other_Punctuation'
    Ps = 'Open_Punctuation'

    S = 'Symbol' # Sc | Sk | Sm | So
    Sc = 'Currency_Symbol'
    Sk = 'Modifier_Symbol'
    Sm = 'Math_Symbol'
    So = 'Other_Symbol'

    Z = 'Separator' # Zl | Zp | Zs
    Zl = 'Line_Separator'
    Zp = 'Paragraph_Separator'
    Zs = 'Space_Separator'

# Table 8. Property Type Key
#
# Property Type | Symbol | Examples
# --------------------------------
# Catalog	| C	| Age, Block
# Enumeration	| E	| Joining_Type, Line_Break
# Binary	| B	| Uppercase, White_Space
# String	| S	| Uppercase_Mapping, Case_Folding
# Numeric	| N	| Numeric_Value
# Miscellaneous	| M	| Name, Jamo_Short_Name
#
# http://www.unicode.org/reports/tr44/tr44-18.html#Type_Key_Table
class UnicodeData:
    '''Contains data single line in UnicodeData.txt'''
    def __init__(self):
        self.code = ''
        self.name = '' # M
        self.general_category = '' # E
        self.canonical_combining_class = '' # N
        self.bidi_class = '' # E
        self.decomposition_type = ''    # E
        self.decomposition_mapping = '' # S
        self.numeric_type = ''  # E
        self.numeric_value = '' # N
        self.bidi_mirrored = '' # B
        self.unicode_1_name = '' # M
        self.iso_comment = '' # M
        self.simple_uppercase_mapping = '' # S
        self.simple_lowercase_mapping = '' # S
        self.simple_titlecase_mapping = '' # S
    def parse(self, line):
        line = line.rstrip('\n')
        li = line.split(';')

        self.code = li[0]
        self.name = li[1]
        self.general_category = li[2]
        self.canonical_combining_class = li[3]
        self.bidi_class = li[4]
        self.decomposition_type = li[5]
        self.decomposition_mapping = li[6]
        self.numeric_type = li[7]
        self.numeric_value = li[8]
        self.bidi_mirrored = li[9]
        self.unicode_1_name = li[10]
        self.iso_comment = li[11]
        self.simple_uppercase_mapping = li[12]
        self.simple_lowercase_mapping = li[13]
        self.simple_titlecase_mapping = li[14]

comment = '''//  This file generated automatically using 'ucd-tool.py'.
//  You can find the author and the copyright in file 'tools/ucd-tool.py'.
'''

boilerplate_gc_cpp_1 = comment + '''//
//  General category(gc) of Unicode code points.
#include <seshat/gc.h>

#include <cstdint>
#include <map>

namespace seshat {

'''

boilerplate_gc_cpp_2 = '''

} // namespace seshat
'''
        

if __name__ == '__main__':
    if len(sys.argv) > 1:
        if sys.argv[1] == 'clean':
            os.system('rm -v data/UnicodeData.txt')
            exit()
        elif sys.argv[1] == '--help':
            print('Usage: ./ucd-tool.py [--help] <command>')
            print('Commands')
            print('  clean    remove all downloaded data')
            print('Arguments')
            print('  --help   print this help')
            exit()

    if 'UnicodeData.txt' not in os.listdir('./data'):
        os.system('wget http://www.unicode.org/Public/UNIDATA/UnicodeData.txt -O data/UnicodeData.txt')

    unicode_data_list = []
    f = open('data/UnicodeData.txt', 'r')
    for l in f.readlines():
        udata = UnicodeData()
        udata.parse(l)
        unicode_data_list.append(udata)

    # Make gc.h
    gc_cpp_table_size = int(unicode_data_list[-1].code, base=16)
    gc_cpp_table = '''
const std::map<uint32_t, Gc> gc_table = {
    '''

    for udata in unicode_data_list:
        cp = '0x' + udata.code
        gc_cpp_table += ('{ ' + cp + ', Gc::' + udata.general_category + ' },')
        gc_cpp_table += '\n    '
    gc_cpp_table = gc_cpp_table.rstrip().rstrip(',')
    gc_cpp_table += '\n};'

    f = open('../src/gc.cpp', 'w')
    f.write(boilerplate_gc_cpp_1 + gc_cpp_table + boilerplate_gc_cpp_2)
    f.close()
