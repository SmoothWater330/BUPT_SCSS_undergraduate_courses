#include "sha256.h"



unsigned int ROR(unsigned int x, unsigned int n) {
	return ((x >> n) | (x << (32 - n)));
}

unsigned int SHR(unsigned int x, unsigned int n) {
	return (x >> n);
}

unsigned int Ch(unsigned int E, unsigned int F, unsigned int G) {
	return ((E & F) ^ ((~E) & G));
}

unsigned int Maj(unsigned int A, unsigned int B, unsigned int C) {
	return ((A & B) ^ (A & C) ^ (B & C));
}

unsigned int Lsigma_0(unsigned int A) {
	return (ROR(A, 2) ^ ROR(A, 13) ^ ROR(A, 22));
}

unsigned int Lsigma_1(unsigned int E) {
	return (ROR(E, 6) ^ ROR(E, 11) ^ ROR(E, 25));
}

unsigned int Ssigma_0(unsigned int x) {
	return (ROR(x, 7) ^ ROR(x, 18) ^ SHR(x, 3));
}

unsigned int Ssigma_1(unsigned int x) {
	return (ROR(x, 17) ^ ROR(x, 19) ^ SHR(x, 10));
}





void sha_init(unsigned int* A, unsigned int* B, unsigned int* C, unsigned int* D, unsigned int* E, unsigned int* F, unsigned int* G, unsigned int* H) {


	unsigned char data[] = {
		0x67, 0xE6, 0x09, 0x6A,
		0x85, 0xAE, 0x67, 0xBB,
		0x72, 0xF3, 0x6E, 0x3C,
		0x3A, 0xF5, 0x4F, 0xA5,
		0x7F, 0x52, 0x0E, 0x51,
		0x8C, 0x68, 0x05, 0x9B,
		0xAB, 0xD9, 0x83, 0x1F,
		0x19, 0xCD, 0xE0, 0x5B
	};

	memcpy(A, data, 4);
	memcpy(B, data + 4, 4);
	memcpy(C, data + 8, 4);
	memcpy(D, data + 12, 4);
	memcpy(E, data + 16, 4);
	memcpy(F, data + 20, 4);
	memcpy(G, data + 24, 4);
	memcpy(H, data + 28, 4);

	//printf("%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n",*A,*B,*C,*D,*E,*F,*G,*H);

	return;
}


size_t sha_update(unsigned char** out, char const* input, size_t inLen) {
	int i;
	int j;

	size_t bitLen = inLen * 8; // the bit length of input
	//size_t fillLen = 64 - (inLen - 56) % 64;  // the length of padding 
	size_t fillLen = 56 - (inLen % 64);
	size_t filledLen = inLen + fillLen + 8; // the length after padding

	unsigned char* outBuf = (unsigned char*)calloc(filledLen, sizeof(char));
	memset(outBuf, 0, sizeof(outBuf));
	memcpy(outBuf, input, inLen);
	outBuf[inLen] = 0x80;// padding 1
	//printf("outBuf[inLen]:%x\n",outBuf[inLen]);


	j = sizeof(inLen);  // the length of input_lengh

	for (i = 0; i < j; i++) {
		memcpy(outBuf + filledLen - 4 + i, (char*)(&bitLen) + j - 1 - i, 1); // LittleEndian
	}

	*out = outBuf;  // the data after padding
	return filledLen;
}

void sha_transform(unsigned int* out, unsigned char* input) {
	//memcpy(out,input,GROUP_SIZE);
	int i, j;
	unsigned int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for (i = 0;i < 16;i++) {
		for (j = 0;j < 4;j++) {
			if (j == 0)
				t1 = input[4 * i + j];
			if (j == 1)
				t2 = input[4 * i + j];
			if (j == 2)
				t3 = input[4 * i + j];
			if (j == 3)
				t4 = input[4 * i + j];
		}
		out[i] = (t1 << 24) + (t2 << 16) + (t3 << 8) + t4;
	}
	return;
}

void data_round(unsigned int* A, unsigned int* B, unsigned int* C, unsigned int* D, unsigned int* E, unsigned int* F, unsigned int* G, unsigned int* H, unsigned int const* M) {
	unsigned int T1, T2;
	unsigned int W[64] = { 0 };
	unsigned int a = *A;
	unsigned int b = *B;
	unsigned int c = *C;
	unsigned int d = *D;
	unsigned int e = *E;
	unsigned int f = *F;
	unsigned int g = *G;
	unsigned int h = *H;
	int i;
	for (i = 0;i < 16;i++) {
		W[i] = M[i];
	}

	for (i = 16;i < 64;i++) {
		W[i] = Ssigma_1(W[i - 2]) + W[i - 7] + Ssigma_0(W[i - 15]) + W[i - 16];
	}



	for (i = 0;i < 64;i++) {
		T1 = h + Lsigma_1(e) + Ch(e, f, g) + K[i] + W[i];
		T2 = Lsigma_0(a) + Maj(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	}

	*A += a;
	*B += b;
	*C += c;
	*D += d;
	*E += e;
	*F += f;
	*G += g;
	*H += h;

	return;
}



void sha_calc(char* out, char const* input, size_t inLen) {
	int i;
	unsigned int A, B, C, D, E, F, G, H;
	size_t filledLen;
	unsigned char* filledData;
	unsigned int* M = (unsigned int*)malloc(GROUP_SIZE);


	sha_init(&A, &B, &C, &D, &E, &F, &G, &H);

	filledLen = sha_update(&filledData, input, inLen);

	for (i = 0;i < filledLen / GROUP_SIZE;i++) {
		sha_transform(M, filledData + i * 64);  //char to int 
		data_round(&A, &B, &C, &D, &E, &F, &G, &H, M);
	}

	sprintf(out, "%08x%08x%08x%08X%08x%08x%08x%08x", A, B, C, D, E, F, G, H);
	//printf("%d\n",strlen(out));

	free(M);
	M = NULL;
	free(filledData);
	filledData = NULL;




	return;
}

int sha256_cracking(char real_hash[65], int range_left, int range_right){

	printf("\n[+] Start cracking!\n");

	char resultBuf[65] = { 0 };
	char input[MAX_SIZE] = { 0 };
	char tBuf[5] = { 0 };

	int flag = 1;

	for (int i = range_left;i <= range_right; i++) {
		tBuf[0] = i;
		for (int j = range_left;j <= range_right; j++) {
			tBuf[1] = j;
			for (int k = range_left;k <= range_right; k++) {
				tBuf[2] = k;
				for (int m = range_left;m <= range_right; m++) {
					flag = 1;
					tBuf[3] = m;
					sha_calc(resultBuf, tBuf, strlen(tBuf));
					for (int l = 0;l < 64;l++) {
						if (resultBuf[l] >= 'A' && resultBuf[l] <= 'F')resultBuf[l] += 32;
						if (real_hash[l] >= 'A' && real_hash[l] <= 'F')real_hash[l] += 32;
						if (resultBuf[l] != real_hash[l]) {
							flag = 0;
							break;
						}
					}
					if (flag) {
						printf("[+] Succeed in cracking!\n");
						printf("[+] Flag: %s\n", tBuf);
						return 0;
					}
				}
			}
		}
	}
	printf("[!] Fail in cracking!\n\n");

	return 0;
}

