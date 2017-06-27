#!/usr/bin/env python3
import sys
ucd_tool = __import__('ucd-tool')

def to_alias(prop, icu_enum, enum_prefix):
    try:
        if icu_enum.index(enum_prefix) == 0:
            val = icu_enum.replace(enum_prefix, '', 1)
            return ucd_tool.property_value_aliases.alias(prop, val)
        else:
            return None
    except:
        return None

def get_prefix(prop):
    return {
        'blk': 'UBLOCK_',
        'gc': 'U_',
    }[prop]

# Usage: ucd-alias.py --property=PROPERTY input
# input example)
#  UBLOCK_ABC
#  UBLOCK_DEF
if __name__ == '__main__':
    prop = sys.argv[1].replace('--property=', '')
    prefix = get_prefix(prop)
    fname = sys.argv[2]
    f = open(fname, 'r')
    readdata = f.readlines()
    f.close()
    newdata = []
    for l in readdata:
        if l.strip() == '':
            newdata.append(l)
            continue
        l = l.strip()
        alias = to_alias(prop, l, prefix)
        if alias == None:
            alias = ''
        newl = l + ' = ' + alias + '\n'
        newdata.append(newl)
    f = open(fname, 'w')
    f.write(''.join(newdata))
    f.close()
