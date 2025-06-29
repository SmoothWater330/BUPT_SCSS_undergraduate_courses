#include<stdio.h>
#include<windows.h>
#include<string.h>
#define MAX_KEY 256
#define MAX_STR 100

int pos_i = 0;
int pos_j = 0;
int sbox[256];

void init_sbox(unsigned char key[MAX_KEY]);
unsigned char generate_key();
void encryption(unsigned char* plaintext, unsigned char* result, unsigned char key[MAX_KEY]);

int RC4(unsigned char in_key[256], unsigned char cipher[100])
{
    printf("\n[+] Start decrypting.");

    char result[MAX_STR] = { 0 };
    int i;
    int len;

    len = strlen((const char*)cipher);
    encryption((unsigned char*)cipher, (unsigned char*)result, in_key);

    printf("\n[+] The plain text: ");
    printf("%s\n\n", result);

    system("pause");
    return 0;
}

void init_sbox(unsigned char key[MAX_KEY]) {
    int i, j;
    int key_len = strlen((const char*)key);
    unsigned char temp;
    for (i = 0;i < 256;++i)
        sbox[i] = i;
    j = 0;

    for (i = 0;i < 256;++i) {
        j = (j + sbox[i] + key[i % key_len]) % 256;
        temp = sbox[i];
        sbox[i] = sbox[j];
        sbox[j] = temp;
    }
}

unsigned char generate_key() {
    unsigned char temp;
    int t;

    pos_i = (pos_i + 1) % 256;
    pos_j = (pos_j + sbox[pos_i]) % 256;
    temp = sbox[pos_i];
    sbox[pos_i] = sbox[pos_j];
    sbox[pos_j] = temp;
    t = (sbox[pos_i] + sbox[pos_j]) % 256;
    return sbox[t];
}

void encryption(unsigned char* plaintext, unsigned char* result, unsigned char key[MAX_KEY]) {
    pos_i = 0;
    pos_j = 0;
    int len = strlen((const char*)plaintext);
    int i = 0;

    init_sbox(key);
    for (i = 0;i < len;++i) {
        unsigned char xor_key = generate_key();
        //result[i] = plaintext[i] ^ xor_key; // 原流程
        result[i] = plaintext[i] ^ xor_key; // 新流程

    }
}
