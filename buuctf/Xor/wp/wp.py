s = "MSAWB~FXZ:J:`tQJ\"N@ bpdd}8g"
s = [ord(c) for c in s]
for i in range(len(s)):
    s[i] = s[i] ^ i
s = [chr(i) for i in s]    
print("".join(s))    
