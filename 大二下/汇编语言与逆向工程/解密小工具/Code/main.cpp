#include"main.h"
#include<iostream>
using namespace std;

int main()
{
	while (1) {
		cout << "[*] Input the type of encryption." << endl;
		cout << "[!] NOTE: Flag length of hash encryption defaults to 4." << endl << endl;
		cout << "[*] You can choose it in:" << endl;
		cout << "[*] 1. SHA256" << endl;
		cout << "[*] 2. MD5" << endl;
		cout << "[*] 3. AES" << endl;
		cout << "[*] 4. DES" << endl;
		cout << "[*] 5. RC4" << endl;
		cout << "[*] 6. SM4" << endl;
		cout << "[?] Your encrytion method is ";
		int de_type;
		cin >> de_type;
		if (de_type == 1) {
			// SHA256
			cout << "\n[*] OK! Show me your hash:" << endl;
			string h;
			cin >> h;
			char hash[65] = { 0 };
			for (int i = 0;i < 64;i++) {
				hash[i] = h[i];
			}
			cout << "\n[*] The range of the char set is between \"begin\" and \"end\"." << endl;
			cout << "[?] The begin is ";
			int begin = 0;
			cin >> begin;
			cout << "[?] The end is ";
			int end = 0;
			cin >> end;
			int r = sha256_cracking(hash, begin, end);
		}
		else if (de_type == 2) {
			// MD5
			cout << endl << "[*] OK! Show me your hash:" << endl;
			string h;
			cin >> h;
			char hash[33] = { 0 };
			for (int i = 0;i < h.length();i++) {
				hash[i] = h[i];
			}
			cout << "\n[*] The range of the char set is between \"begin\" and \"end\"." << endl;
			cout << "[?] The begin is ";
			int begin = 0;
			cin >> begin;
			cout << "[?] The end is ";
			int end = 0;
			cin >> end;
			int r = md5_cracking(hash, begin, end);
		}
		else if (de_type == 3) {
			// AES
			unsigned char key[17] = { 0 };
			unsigned char ct[100] = { 0 };
			cout << endl << "[*] OK! Show me your key:" << endl;
			string k;
			cin >> k;
			for (int i = 0;i < 16;i++) {
				key[i] = k[i];
			}
			cout << endl << "[*] OK! Show me the length of your cipher:" << endl;
			int length_of_c = 0;
			cin >> length_of_c;
			cout << endl << "[*] OK! Show me your cipher:" << endl;
			for (int i = 0;i < length_of_c;i++) {
				cout << "[*] Byte " << i + 1 << ": ";
				int tmp = 0;
				cin >> hex >> tmp;
				ct[i] = tmp;
			}
			int r = AES(key, ct);
		}
		else if (de_type == 4) {
			// DES
			unsigned char key[9] = { 0 };
			unsigned char ct[32] = { 0 };
			cout << endl << "[*] OK! Show me your key:" << endl;
			string k;
			cin >> k;
			for (int i = 0;i < 8;i++) {
				key[i] = k[i];
			}
			cout << endl << "[*] OK! Show me the length of your cipher:" << endl;
			int length_of_c = 0;
			cin >> length_of_c;
			cout << endl << "[*] OK! Show me your cipher:" << endl;
			for (int i = 0;i < length_of_c;i++) {
				cout << "[*] Byte " << i + 1 << ": ";
				int tmp = 0;
				cin >> hex >> tmp;
				ct[i] = tmp;
			}
			int r = DES(key, ct);
		}
		else if (de_type == 5) {
			// RC4
			unsigned char key[256] = { 0 };
			unsigned char ct[100] = { 0 };
			cout << endl << "[*] OK! Show me your key:" << endl;
			string k;
			cin >> k;
			for (int i = 0;i < k.length();i++) {
				key[i] = k[i];
			}
			cout << endl << "[*] OK! Show me the length of your cipher:" << endl;
			int length_of_c = 0;
			cin >> length_of_c;
			cout << endl << "[*] OK! Show me your cipher:" << endl;
			for (int i = 0;i < length_of_c;i++) {
				cout << "[*] Byte " << i + 1 << ": ";
				int tmp = 0;
				cin >> hex >> tmp;
				ct[i] = tmp;
			}
			int r = RC4(key, ct);
		}
		else if (de_type == 6) {
			// SM4
			unsigned char key[16] = { 0 };
			unsigned char ct[16] = { 0 };
			cout << endl << "[*] OK! Show me your key:" << endl;
			string k;
			cin >> k;
			for (int i = 0;i < 16;i++) {
				key[i] = k[i];
			}
			cout << endl << "[*] OK! Show me the length of your cipher:" << endl;
			int length_of_c = 0;
			cin >> length_of_c;
			cout << endl << "[*] OK! Show me your cipher:" << endl;
			for (int i = 0;i < length_of_c;i++) {
				cout << "[*] Byte " << i + 1 << ": ";
				int tmp = 0;
				cin >> hex >> tmp;
				ct[i] = tmp;
			}
			int r = SM4(key, ct);
			}

		system("pause");
		system("cls");
	}

	return 0;
}