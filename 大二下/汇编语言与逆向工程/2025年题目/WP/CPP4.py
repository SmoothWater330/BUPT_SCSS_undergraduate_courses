# MD5爆破结果
flag2 = "Fbtz"
flag1 = "".join([chr(ord(i)-1) for i in flag2])
print(flag1 + flag1)
