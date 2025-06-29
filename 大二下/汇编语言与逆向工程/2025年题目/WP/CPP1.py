cipher = [0x52, 0x7c, 0x6e, 0x4c, 0x5d, 0x56, 0x7f, 0x63, 0x4c, 0x54, 0x46, 0x56]
key = [1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1]
flag = ""
for i in range(len(cipher)):
    tmp = ((cipher[i] & 7) << 3) | ((cipher[i] & 0x38) >> 3) | (cipher[i] & 0xc0)
    tmp ^= key[i]
    flag += chr(tmp)

print(flag)

# Output: SeventyYears
