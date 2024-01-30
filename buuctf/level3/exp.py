base64_table = [c for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"]

for i in range(10):
    base64_table[i],base64_table[0x13-i] = base64_table[0x13-i], base64_table[i]

base64_table = "".join(base64_table)
raw_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
secret = "d2G0ZjLwHjS7DmOzZAY0X2lzX3CoZV9zdNOydO9vZl9yZXZlcnGlfD=="
secret = secret.translate(str.maketrans(base64_table, raw_table))

import base64
print(base64.b64decode(secret.encode()).decode())