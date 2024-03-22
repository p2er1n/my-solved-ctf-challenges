import ctypes

# 01234567 89abcdef ghijklmn
#             |
#             v
# 23456 cdef01 mn89ab ghijkl

def decrypt(cipher):
    """
    cipher is type of string
    so we first divide it into parts of 4 chars and process on every part
    if there is a tail less than 3 chars, we treat it specially in the last
    """
    table = [c for c in "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0987654321/+"]
    l = len(cipher)
    res = []
    for i in range(0,l,4):
        c = []
        for j in range(4):
            c.append(cipher[i+j])
        b = []
        for j in range(4):
            try:
                b.append(ctypes.c_uint8(table.index(c[j])))
            except ValueError:
                if c[j] == "=":
                    b.append(ctypes.c_uint8(0))
                else:
                    raise ValueError(f"Error: c[{j}] = {c[j]}")
        rb1,rb2,rb3 = ctypes.c_uint8((b[0].value<<2)&0b111111 | (b[1].value>>4)&0b111111), ctypes.c_uint8((b[1].value&0xf << 4)&0b111111 | (b[2].value>>2)&0b111111), ctypes.c_uint8(b[3].value&0b111111 | (b[2].value&0b11 << 6)&0b111111)
        # rb1 = ctypes.c_uint8(ctypes.c_uint8(b[0].value<<2).value | ctypes.c_uint8(b[1].value>>4).value)
        # rb2 = ctypes.c_uint8(ctypes.c_uint8(b[1].value&0xf << 4).value | ctypes.c_uint8(b[2].value>>2).value)
        # rb3 = ctypes.c_uint8(ctypes.c_uint8(b[3].value).value | ctypes.c_uint8(b[2].value&0b11<<6).value)
        res += [chr(rb1.value), chr(rb2.value), chr(rb3.value)]
    return "".join(res)

print(decrypt("mTyqm7wjODkrNLcWl0eqO8K8gc1BPk1GNLgUpI=="))
            
        
