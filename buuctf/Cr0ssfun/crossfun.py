"""
10 = p
0xd = @
3 = f
0x1a = r
0x14 = e
7 = 0
0x10 = _
0xb = p
0x17 = e
0x1e = u
0 = w
6 = 2
0x16 = s
0x1f = n
0xc = _
0xf = d
8 = {
0x12 = 3
0x1c = _
0x15 = r
2 = t
9 = c
0x20 = }
0x13 = v
4 = 0
0xe = n
4 = 2
0x11 = r
0x1d = f
0x11 = r
0x18 = _
1 = c
0x19 = @
0x1b = e
"""
flag = [0] * 0x21
flag[10] = 'p'
flag[0xd] = '@'
flag[3] = 'f'
flag[0x1a] = 'r'
flag[0x14] = 'e'
flag[7] = '0'
flag[0x10] = '_'
flag[0xb] = 'p'
flag[0x17] = 'e'
flag[0x1e] = 'u'
flag[0] = 'w'
flag[6] = '2'
flag[0x16] = 's'
flag[0x1f] = 'n'
flag[0xc] = '_'
flag[0xf] = 'd'
flag[8] = '{'
flag[0x12] = '3'
flag[0x1c] = '_'
flag[0x15] = 'r'
flag[2] = 't'
flag[9] = 'c'
flag[0x20] = '}'
flag[0x13] = 'v'
flag[4] = "0"
flag[0xe] = 'n'
flag[4] = '2'
flag[0x11] = 'r'
flag[0x1d] = 'f'
flag[0x11] = 'r'
flag[0x18] = '_'
flag[1] = 'c'
flag[0x19] = '@'
flag[0x1b] = 'e'
for c in flag:
    print(c,end='')