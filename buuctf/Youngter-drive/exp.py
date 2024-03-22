import string
data = [c for c in "TOiZiZtOrYaToUwPnToBsOaOapsyS0"]
table = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0"
for i in range(0x1d, -1, -2):
    if not data[i] in string.ascii_letters:
        continue
    c = data[i]
    idx = table.index(c)
    if chr(idx + 0x26).isupper():
        data[i] = chr(idx+0x26)
    else:
        data[i] = chr(idx+0x60)
print("".join(data))	