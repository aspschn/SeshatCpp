#!/usr/bin/env python3

# Property generator to get interchangable data from Seshat for other
# softwares, and also can be used for getting string value of properties.
#
# It supports Python object and JSON format.
#
# examples:
#  Property name (Python) -
#   {
#       "unicode_version": "10.0.0",
#       "properties": [{
#           "seshat_enum": "Gc",
#           "seshat_function": "gc",
#           "abbr": "gc",
#           "full": "General_Category",
#           "icu_u_property": "UCHAR_GENERAL_CATEGORY"
#           "icu_enum": "UCharCategory",
#           "property_values": [{
#               "seshat_enum": "Cc",
#               "abbr": "Cc",
#               "full": "Control",
#               "alt": ["cntrl"],
#               "icu_enum": "U_CONTROL_CHAR"
#           }, ... ]
#       }, ... ]
#   }
import pprint

# Unicode abbreviated alias: Seshat enum class mappings.
# Not explicitly here means not in Seshat or not implemented yet.
_alias_seshat_enum_pair = {
    ## ==============================
    ## Numeric Properties
    ## ==============================

    ## ==============================
    ## String Properties
    ## ==============================

    ## ==============================
    ## Miscellaneous Properties
    ## ==============================

    ## ==============================
    ## Catalog Properties
    ## ==============================
    'blk': 'Block',
    'sc': 'Script',
    ## ==============================
    ## Enumerated Properties
    ## ==============================
    'dt': 'Dt',
    'gc': 'Gc',
    'GCB': 'Gcb',
    'NFC_QC': 'QcValue',
    'NFD_QC': 'QcValue',
    'NFKC_QC': 'QcValue',
    'NFKD_QC': 'QcValue',
    'WB': 'Wb',
}

# Seshat function coverage list.
# Seshat uses property function name as snake_cased abbreviated
# Unicode property name, and some functions use full name
# for convenient.
# Below list contains implemented Seshat function for each property.
# Not explicitly here means not implemented yet.
# The key is abbreviated alias and the value is object of status.
# 'full': Boolean. If True, then Seshat using full(long) property name for
#         that function. False for abbreviated property name.
_seshat_function_coverage = {
    ## ==============================
    ## String Properties
    ## ==============================
    'lc': {'full': True, },
    'slc': {'full': True, },
    'stc': {'full': True, },
    'suc': {'full': True, },
    'tc': {'full': True, },
    'uc': {'full': True, },
    ## ==============================
    ## Miscellaneous Properties
    ## ==============================
    'na': {'full': True, },
    ## ==============================
    ## Catalog Properties
    ## ==============================
    'age': {'full': False, },
    'blk': {'full': True, },
    'sc': {'full': True, },
    ## ==============================
    ## Enumerated Properties
    ## ==============================
    'ccc': {'full': False, },
    'dt': {'full': False, },
    'gc': {'full': False, },
    'GCB': {'full': False, },
    'hst': {'full': True, },
    'NFC_QC': {'full': False, },
    'NFD_QC': {'full': False, },
    'NFKC_QC': {'full': False, },
    'NFKD_QC': {'full': False, },
    'WB': {'full': False, },
    ## ==============================
    ## Binary Properties
    ## ==============================
    'Cased': {'full': False, },
    'CI': {'full': True, },
    'Comp_Ex': {'full': False, },
    'DI': {'full': True, },
    'Gr_Ext': {'full': True, },
    'Lower': {'full': True, },
    'ODI': {'full': False, },
    'OGr_Ext': {'full': False, },
    'OLower': {'full': True, },
    'OUpper': {'full': True, },
    'PCM': {'full': True, },
    'Upper': {'full': True, },
    'VS': {'full': True, },
    'WSpace': {'full': True, },
}

def read_files():
    try:
        f_alias = open('data/10.0.0/PropertyAliases.txt', 'r')
        f_val_alias = open('data/10.0.0/PropertyValueAliases.txt', 'r')
        data_alias = f_alias.readlines()
        data_val_alias = f_val_alias.readlines()
        f_alias.close()
        f_val_alias.close()

        return {
            'property_aliases': data_alias,
            'property_value_aliases': data_val_alias
        }
    except:
        print('File open failed.')

class Aliases:
    def __init__(self):
        self._data = []
    def append(self, abbr, full, others):
        self._data.append({'abbr': abbr, 'full': full, 'alt': others})

    @property
    def data(self):
        return self._data

def parse_aliases(data):
    aliases = Aliases()
    for line in data:
        text = line.strip()
        if text.startswith('#') or text == '':
            continue
        else:
            text = text.split('#')[0] # strip comment
            names = tuple(map(lambda x: x.strip(), text.split(';')))
            aliases.append(names[0], names[1], names[2:])
    return aliases

def parse_value_aliases(data):
    properties = {}
    for line in data:
        text = line.strip()
        if text.startswith('#') or text == '':
            continue
        else:
            text = text.split('#')[0]
            names = tuple(map(lambda x: x.strip(), text.split(';')))
            prop = names[0]
            if prop not in properties.keys():
                properties[prop] = Aliases()
            properties[prop].append(names[1], names[2], names[3:])
    return properties

properties = {
    'unicode_version': '10.0.0',
    'properties': []
}

data = read_files()
aliases = parse_aliases(data['property_aliases'])
value_aliases = parse_value_aliases(data['property_value_aliases'])
for prop in aliases.data:
    abbr = prop['abbr']
    seshat_function = None
    # Get Seshat function name.
    naming = _seshat_function_coverage.get(abbr, None)
    if naming != None:
        seshat_function = prop['abbr'].lower() if naming['full'] == False else prop['full'].lower()
    # Get property values.
    property_values = []
    values = value_aliases[abbr] if (abbr in value_aliases.keys()) else Aliases()
    for val in values.data:
        # There are not used properties in 'gc'.
        if prop['abbr'] == 'gc' and val['abbr'] in ('C', 'L', 'LC', 'M', 'N', 'P', 'S', 'Z'):
            continue
        seshat_enum = val['abbr'] if _alias_seshat_enum_pair.get(abbr, None) != None else None
        # QcValue exceptionally using full name for enum members.
        if prop['abbr'] in ('NFC_QC', 'NFD_QC', 'NFKC_QC', 'NFKD_QC'):
            seshat_enum = val['full']
        property_values.append({
            'seshat_enum': seshat_enum,
            'abbr': val['abbr'],
            'full': val['full'],
            'alt': val['alt'],
            'icu_enum': None,
        })
    properties['properties'].append({
        'seshat_enum': _alias_seshat_enum_pair.get(abbr, None),
        'seshat_function': seshat_function,
        'abbr': prop['abbr'],
        'full': prop['full'],
        'icu_u_property': None,
        'icu_enum': None,
        'property_values': property_values
    })

if __name__ == '__main__':
    import sys

    if '--help' in sys.argv:
        print('Usage: ./prop-gen.py [-F format] [-o output]')
        print()
        print('Property generator to get interchangable data from Seshat for')
        print('other softwares.')
        print()
        print('Arguments:')
        print('  -F format      Data format. "py" or "json". default is "py".')
        print('  -o output      Output file. If not set, print to stdout.')
        exit()

    form = 'py' # format
    mode = 'stdout' # stdout/file
    file = ''
    if '-F' in sys.argv:
        form = sys.argv[sys.argv.index('-F') + 1]
    if '-o' in sys.argv:
        mode = 'file'
        file = sys.argv[sys.argv.index('-o') + 1]

    if form == 'json':
        print('JSON format currently not supported.')
        exit()
    if mode == 'stdout':
        pprint.pprint(properties)
        exit()
    elif mode == 'file':
        f = open(file, 'w')
        if form == 'py':
            f.write('properties = ')
            f.write(pprint.pformat(properties))
        f.close()
        exit()