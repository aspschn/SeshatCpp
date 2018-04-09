#!/usr/bin/env python3

# Make src/ucd/property_names.h and src/ucd/property_names.cpp files.
import sys

help_message = 'Usage: ./prop-names.py PROPFILE'

comment = '''//  This file generated automatically using 'prop-names.py'.
//  You can find the author and the copyright in file 'tools/prop-names.py'.

// Unicode version: {unicode_version}
'''

header_template = '''
#ifndef _SESHAT_UCD_PROPERTY_NAMES
#define _SESHAT_UCD_PROPERTY_NAMES

#include <seshat/unicode/property_names.h>

#include <unordered_map>

namespace seshat {{
namespace unicode {{
namespace ucd {{

PropertyValueName property_value_name(bool val);
{contents}

}} // namespace ucd
}} // namespace unicode
}} // namespace seshat

#endif // _SESHAT_UCD_PROPERTY_NAMES
'''

cpp_template = '''
#include "property_names.h"

namespace seshat {{
namespace unicode {{
namespace ucd {{


// Tables
{tables}

PropertyValueName property_value_name(bool val)
{{
    PropertyValueName result = {{}};
    if (val == true) {{
        result.full = "Yes";
        result.abbr = "Y";
        result.alt[0] = "T";
        result.alt[1] = "True";
    }} else {{
        result.full = "No";
        result.abbr = "N";
        result.alt[0] = "F";
        result.alt[1] = "False";
    }}
    return result;
}}

{contents}

}} // namespace ucd
}} // namespace unicode
}} // namespace seshat
'''

if __name__ == '__main__':
    if (len(sys.argv) < 2):
        print(help_message)
        exit(1)
    _ = __import__(sys.argv[1])
    properties = _.properties

    header = comment.format(unicode_version=properties['unicode_version'])
    header += header_template
    header_contents = ''

    cpp = comment.format(unicode_version=properties['unicode_version'])
    cpp += cpp_template
    cpp_tables = ''
    cpp_contents = ''
    for prop in properties['properties']:
        # Seshat has function with special enum for the property.
        if prop['seshat_function'] != None and prop['seshat_enum'] != None:
            seshat_enum = prop['seshat_enum']
            # Append function prototype to header.
            if header_contents.find('QcValue') != -1:
                continue # Protect the duplication.
            header_contents += '''PropertyValueName property_value_name(const {}& val);
'''.format(seshat_enum)
            # Append name table to cpp file.
            cpp_tables += 'std::unordered_map<{enum}, PropertyValueName> {func}_name_table = {{'.format(
                enum=seshat_enum, func=prop['seshat_function'])
            for val in prop['property_values']:
                val_full = val['full']
                val_abbr = val['abbr']
                # DEBUG
                if seshat_enum == 'Dt':
                    print(val)
                # DEBUG END
                val_alt = '{{ {alt_1}, {alt_2} }}'.format(
                    alt_1='"' + val['alt'][0] + '"' if len(val['alt']) > 0 else 'nullptr',
                    alt_2='"' + val['alt'][1] + '"' if len(val['alt']) > 1 else 'nullptr'
                )
                cpp_tables += '''
    {{
        {seshat_enum}::{seshat_val}, PropertyValueName {{
            "{val_full}",
            "{val_abbr}",
            {val_alt}
        }}
    }},'''.format(seshat_enum=seshat_enum,
                    seshat_val=val['seshat_enum'],
                    val_full=val_full,
                    val_abbr=val_abbr,
                    val_alt=val_alt)
            cpp_tables += '\n};'
            # Append name function to cpp file.
            cpp_contents += '''
PropertyValueName property_value_name(const {}& val)
{{
    return {}_name_table.at(val);
}}
'''.format(seshat_enum, prop['seshat_function'])
    header = header.format(contents=header_contents)
    cpp = cpp.format(tables=cpp_tables, contents=cpp_contents)

    # Write to file
    f_header = open('../src/ucd/property_names.h', 'w')
    f_header.write(header)
    f_header.close()
    f_cpp = open('../src/ucd/property_names.cpp', 'w')
    f_cpp.write(cpp)
    f_cpp.close()
