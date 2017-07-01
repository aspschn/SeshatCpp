#!/usr/bin/env python3
import shutil
ucd_tool = __import__('ucd-tool')

class PropertyInfo:
    def __init__(self):
        self.alias = ''
        self.long_names = []
        self.values = []

def get_prop_info(alias):
    pair = ucd_tool.PropertyAliases.aliases()
    if alias in pair.keys():
        info = PropertyInfo()
        info.alias = alias
        info.long_names = pair[alias]
        ucd_tool.PropertyValueAliases.init_if_not()
        info.values = ucd_tool.PropertyValueAliases._dict[alias].values()
        return info
    raise Exception(alias + ': Not a valid property alias.')

if __name__ == '__main__':
    import argparse

    argp = argparse.ArgumentParser(
        prog='./prop-viewer.py',
        description='Used for getting Unicode properties information.')
    argp.add_argument('prop', type=str, nargs='?', default=None,
        help='Property name in alias. List valid properties if omitted.')
    argp.add_argument('--unicode-version', type=str)
    argp.add_argument('--emoji-version', type=str)

    args = argp.parse_args()

    # Check version arguments
    if args.unicode_version != None:
        ucd_tool.set_unicode_version(*args.unicode_version.split('.'))
    if args.emoji_version != None:
        ucd_tool.set_emoji_version(*args.emoji_version.split('.'))

    # Get terminal info
    ts = shutil.get_terminal_size()

    # Print version info
    print('Using Unicode version {}.{}.{}'.format(
        ucd_tool.UNICODE_VERSION_MAJOR, ucd_tool.UNICODE_VERSION_MINOR,
        ucd_tool.UNICODE_VERSION_UPDATE))
    print('=' * ts.columns)

    if args.prop != None:
        info = get_prop_info(args.prop)
        title = '{}: {}'.format(info.alias, ', '.join(info.long_names))
        nums = 'Number of values: {}'.format(len(info.values))
        print(title)
        print(nums)
        print('')
        print(info.values)
    else:
        properties = ucd_tool.PropertyAliases.properties()
        max_len = ts.columns // 3
        for idx, alias in enumerate(set(properties.values())):
            sel = str(idx + 1) + ' ' + alias
            sel = sel.ljust(max_len)[:max_len]
            print(sel, end='')
            if (idx + 1) % 3 == 0:
                print('')
