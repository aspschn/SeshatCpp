#!/usr/bin/env python3
# Seshat config tool.
# This is not a part of autotools.
import sys
import os
import platform
import shutil
import xml.etree.ElementTree
import subprocess

ICU_MIN_VERSION = "59.1"
UNICODE_VERSION = "10.0"

options = {
    'SESHAT_ICU_BACKEND': False,
    'SESHAT_IGNORE_ICU_VERSION': False,
    'SESHAT_INFO_FLAGS': '-DSESHAT_BUILD_DATE=\\"`date -u +%Y-%m-%dT%H:%M:%SZ`\\"',
    'CXXFLAGS': '-Wall',
}

makefile_template = '''OBJ = {m_OBJ_LIST}
ifndef CXX
CXX = {m_CXX}
endif
CXXFLAGS = {m_CXXFLAGS}
SESHAT_INFO_FLAGS = {m_SESHAT_INFO_FLAGS}
export CXX
default: $(OBJ)
\tmkdir -p lib
\t$(CXX) -std=c++11 -shared -o lib/libseshat.so $^ -Iinclude
\t$(MAKE) -C tools/

test:
\t$(MAKE) -C tests/

static: $(OBJ)
\tmkdir -p lib
\tar rcs lib/libseshat.a $^

src/info.o: src/info.cpp
\t$(CXX) -std=c++11 $(CXXFLAGS) $(SESHAT_INFO_FLAGS) -c -Iinclude -o $@ $<

src/%.o: src/%.cpp
\t$(CXX) -std=c++11 $(CXXFLAGS) -c -Iinclude -o $@ $<

clean:
\trm -f src/*.o
\trm -f src/ucd/*.o
\trm -f src/emoji/*.o
\trm -f src/icu/*.o
\trm -rf lib
\t$(MAKE) -C tools/ -f Makefile clean
\t$(MAKE) -C tests/ -f Makefile clean
'''
obj_list = []

# Object file append functions
def append_obj(cpp_path):
    for fname in os.listdir(cpp_path):
        (name, ext) = os.path.splitext(fname)
        if ext == '.cpp':
            obj_list.append(os.path.normpath(cpp_path) + '/' + name + '.o')

def append_src():
    append_obj('./src')

def append_ucd():
    append_obj('./src/ucd')
    append_obj('./src/emoji')

def append_icu():
    append_obj('./src/icu')
    obj_list.append('src/ucd/normalization_props.o')
    obj_list.append('src/ucd/dm.o')
    obj_list.append('src/emoji/data.o')

# Detect platform
def detect_platform():
    # Get OS is 32bit or 64bit.
    # Note that platform.architecture() is not about OS but python interpreter.
    arch = platform.architecture()[0]
    os_bit = 0
    if arch == '64bit':
        os_bit = 64
    else:
        os_bit = 32

    if os_bit == 64:
        # Exception for cygwin
        if sys.platform == 'cygwin':
            return
        options['CXXFLAGS'] += ' -fPIC'

# Detect compiler
def detect_compiler():
    if shutil.which('clang++') != None:
        cxx = 'clang++'
    elif shutil.which('g++') != None:
        cxx = 'g++'
    else:
        print('It seems any C++ compiler installed in this system.')
        exit(1)
    options['CXX'] = cxx

# Detect ICU version
def detect_icu():
    icu_info = {}
    if shutil.which('icuinfo') != None:
        icuinfo = subprocess.check_output('icuinfo').decode()
        icuinfo = icuinfo[:icuinfo.rindex('>')+1]
        icuinfo = icuinfo.replace('&', '&amp;')
        tree = xml.etree.ElementTree.fromstring(icuinfo)
        for e in tree:
            icu_info[e.get('name')] = e.text

        icu_version = icu_info['version'].split('.')
        min_version = ICU_MIN_VERSION.split('.')
        uni_version = icu_info['version.unicode'].split('.')
        min_uni_version = UNICODE_VERSION.split('.')
        if icu_version < min_version:
            if options['SESHAT_IGNORE_ICU_VERSION']:
                return
            print('Seshat requires ICU version {} or later, but version installed your system is {}'.format(ICU_MIN_VERSION, icu_info['version']))
            exit(1)
        if uni_version < min_uni_version:
            if options['SESHAT_IGNORE_ICU_VERSION']:
                return
            print('Seshat requires ICU which supports Unicode version {} or later, but ICU installed your system supports until {}'.format(UNICODE_VERSION, icu_info['version.unicode']))
    else:
        print('icuinfo: command not found.')
        exit(1)

# Print options
def print_options():
    for k, v in options.items():
        print('{}={}'.format(k, v))

def print_help():
    print('Usage: ./configure.py [--help] <arguments>')
    print('Arguments')
    print('  --help         print this help')
    print('  --icu-backend  use ICU as backend instead of seshat')
    print('                 implementation')
    print('  --ignore-icu-version')
    print('                 ignore ICU version check')
    exit()

if __name__ == '__main__':
    if len(sys.argv) > 1:
        if sys.argv[1] == '--help':
            print_help()
        if '--icu-backend' in sys.argv:
            options['SESHAT_ICU_BACKEND'] = True
            options['CXXFLAGS'] += ' -DSESHAT_ICU_BACKEND'
        if '--ignore-icu-version' in sys.argv:
            options['SESHAT_IGNORE_ICU_VERSION'] = True
    append_src()
    if options['SESHAT_ICU_BACKEND'] == True:
        detect_icu()
        append_icu()
    else:
        append_ucd()
    detect_platform()
    detect_compiler()
    print_options()
    output = makefile_template.format(m_OBJ_LIST=' '.join(obj_list),
            m_CXXFLAGS=options['CXXFLAGS'],
            m_CXX=options['CXX'],
            m_SESHAT_INFO_FLAGS=options['SESHAT_INFO_FLAGS'])
    f = open('Makefile', 'w')
    f.write(output)
    f.close()
