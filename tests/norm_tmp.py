#!/usr/bin/env python3
f = open('../tools/data/NormalizationTest.txt', 'r')
d = f.readlines()
f.close()

def add_0x(num):
    i = int(num, base=16)
    return hex(i)

f = open('normalization.h', 'w')
f.write('''#include <cstdint>

const char* test_table[][5] = {
''')
for line in d:
    if line[0] == '#' or line[0].strip() == '':
        continue
    if line[0] == '@':
        s = '// ' + line.strip() + '\n'
        f.write(s)
        continue
    f.write('    { ')
    line = line.split('#')[0].strip().rstrip(';')
    seqs = line.split(';')
    s = ''
    for seq in seqs:
        s += '"' + seq + '"'
        s += ', '
    s = s.rstrip(', ')
    s += ' },\n'
    f.write(s)

f.seek(f.tell() - 2)
f.write('\n};\n')
f.close()
