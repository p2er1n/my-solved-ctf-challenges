c = 0xad939ff59f6e70bcbfad406f2494993757eee98b91bc244184a377520d06fc35
e = 65537
n = 103461035900816914121390101299049044413950405173712170434161686539878160984549
# c = m^e%n
# n = p*q, p,q均为质数
# e为密钥或者公钥，e*d%t=1，t=(p-1)*(q-1)
# m = c^d%n
# 因此需要求d,也就是需要t,也就是需要p,q,也就是需要质分解n

p = 282164587459512124844245113950593348271
q = 366669102002966856876605669837014229419

t = (p-1)*(q-1)

# 找到e在t下的乘法逆元，即d
import sympy
d = sympy.mod_inverse(e,t)
m = pow(c,d,n)
import binascii
print(binascii.unhexlify(hex(m)[2:]).decode("utf-8"))
