#pragma once

int sha256_cracking(char real_hash[65], int range_left, int range_right);
int md5_cracking(char real_hash[33], int range_left, int range_right);
int AES(unsigned char key[17], unsigned char ct[]);
int DES(unsigned char key[9], unsigned char ciphertext[]);
int RC4(unsigned char key[256], unsigned char cipher[100]);
int SM4(unsigned char key[16], unsigned char ciphertext[16]);