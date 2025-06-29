a = 3
b = 7
a_ = pow(a, -1, 10)
cipher = "ippio"
flag = ""
for c in cipher:
    flag += chr(((ord(c) - 105 - b) * a_) % 10 + 48)
    
print(flag)
# Output: 10013