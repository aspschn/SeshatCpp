#!/usr/bin/env python3
# Seshat config tool.
# This is not a part of autotools.
import sys
import os
import shutil
import xml.etree.ElementTree
import subprocess

ICU_MIN_VERSION = "58.2"

options = {
    'SESHAT_ICU_BACKEND': False,
    'CXXFLAGS': '-Wall -fPIC',
}

makefile_template = '''OBJ = {m_OBJ_LIST}
CXXFLAGS = {m_CXXFLAGS}
default: $(OBJ)
\tmkdir -p lib
\t{m_CXX} -std=c++11 -shared -o lib/libseshat.so $^ -Iinclude

static: $(OBJ)
\tmkdir -p lib
\tar rcs lib/libseshat.a $^

src/%.o: src/%.cpp
\t{m_CXX} -std=c++11 $(CXXFLAGS) -c -Iinclude -o $@ $<

clean:
\trm src/*.o
\trm src/ucd/*.o
\trm src/emoji/*.o
\trm src/icu/*.o
\trm -r lib
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
    print('CXX={}'.format(options['CXX']))

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
        if icu_version < min_version:
            print('Seshat requires ICU version {} or later, but version installed your system is {}'.format(ICU_MIN_VERSION, icu_info['version']))
            exit(1)
    else:
        print('icuinfo: command not found.')
        exit(1)

def print_help():
    print('Usage: ./configure.py [--help] <arguments>')
    print('Arguments')
    print('  --help         print this help')
    print('  --icu-backend  use ICU as backend instead of seshat')
    print('                 implementation')
    exit()

if __name__ == '__main__':
    if len(sys.argv) > 1:
        if sys.argv[1] == '--help':
            print_help()
        if '--icu-backend' in sys.argv:
            options['CXXFLAGS'] += ' -DSESHAT_ICU_BACKEND'
    append_src()
    if options['SESHAT_ICU_BACKEND'] == True:
        append_icu()
    else:
        append_ucd()
    detect_compiler()
    detect_icu()
    output = makefile_template.format(m_OBJ_LIST=' '.join(obj_list),
            m_CXXFLAGS=options['CXXFLAGS'],
            m_CXX=options['CXX'])
    f = open('Makefile', 'w')
    f.write(output)
    f.close()
