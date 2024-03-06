key = [
    0x00000002,  
    0x00000002,  
    0x00000003,  
    0x00000004
]

# in python, bit shifting is signed, which means it fills up new space with 1 or 0 depending on the variable's sign.
def decrypt(input1, input2):
    sum_ = (0x458bcd42 * 64)&0xffffffff
    for i in range(63,-1,-1):
        # input2 -- (key[3] + (input1 >> 9) ^ input1 * 0x40 + key[2] ^ sum_ + input1 + 0x14 ^ 0x10)
        # input1 -= (key[1] + (input2 >> 9) ^ input2 * 0x40 + key[0] ^ sum_ + input2 + 0xb ^ 0x20)
        input2 = (input2 - (key[3] + ((input1 & 0xffffffff) >> 9)&0xffffffff ^ (input1 * 0x40) & 0xffffffff + (key[2] ^ sum_ + input1 + 0x14 ^ 0x10)&0xffffffff)&0xffffffff)&0xffffffff
        input1 = (input2 - (key[1] + ((input2 & 0xffffffff) >> 9)&0xffffffff ^ (input2 * 0x40) & 0xffffffff + (key[0] ^ sum_ + input2 + 0xb  ^ 0x20)&0xffffffff)&0xffffffff)&0xffffffff
        sum_ = (sum_ - 0x458bcd42) & 0xffffffff
    return input1, input2

enc = [
    -0x20b71082,
    0x20caacf4,
    -520941611,
    1548802262,
    -1642340819,
    -0x7b0cfbe0,
]
flag = [0] * 6
for i in range(0,6,2):
    flag[i], flag[i+1] = decrypt(enc[i], enc[i+1])

for bs in flag:
    b1 = chr(bs & 0x000000ff)
    b2 = chr((bs & 0x0000ff00) >> 8)
    b3 = chr((bs & 0x00ff0000) >> 16)
    b4 = chr((bs & 0xff000000) >> 24)
    print("{}{}{}{}".format(b4,b3,b2,b1))

    
