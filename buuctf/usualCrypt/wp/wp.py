ss = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
s = [c for c in ss]
for i in range(6,14):
    s[i+10], s[i] = s[i], s[i+10]
# print("".join(s))
import base64
secret = "zMXHz3TIgnxLxJhFAdtZn2fFk3lYCrtPC2l9"
secret = [c for c in secret]
for i in range(len(secret)):
    if secret[i].isupper():
        secret[i]=secret[i].lower()
    else:
        secret[i]=secret[i].upper()
secret = "".join(secret)        
secret = secret.translate(str.maketrans("".join(s), ss))
secret = base64.b64decode(secret.encode('utf-8')).decode('utf-8')
print(secret)


    
    
