//Katarzyna Gliñska
//Kryptografia
//Implementacja szyfru S-DES


#include <iostream>
using namespace std;

void szyfrowanie_kluczem(int t[8], int klucz_rundy[8] , int ostatecznie[8]) {


	int c1[4] = { 0 };
	int c2[4] = { 0 };
	int kopia1_c2[8] = { 0 };
	int kopia2_c2[4] = { 0 };
	int P4w8[] = { 3,0,1,2,1,2,3,0 };
	int P4[] = { 1, 3, 2, 0 };

	for (int i = 0;i < 4;i++) {
		c1[i] = t[i];
		c2[i] = t[i + 4];
		kopia1_c2[i] = c2[i];
		kopia2_c2[i] = c2[i];
	}cout << endl;

	//cout << "Po permutacji P4w8" << endl;
	for (int i = 0;i < 8;i++) {
		kopia1_c2[i] = c2[P4w8[i]];
	}

	int cos[8] = { 0 };

	for (int i = 7;i >= 0;i--) {
		cos[i] = ((klucz_rundy[i] + kopia1_c2[i]));
		if (cos[i] == 2) {
			cos[i] = 0;
		}
		if (cos[i] == 3) {
			cos[i] = 1;
		}
	}
	//cout << "Po dodawaniu" << endl;

	//sbox
	int sbox[4] = { 0 };

	int sbox1[4] = { 0 };
	int sbox2[4] = { 0 };
	int a = 0;
	int b = 0;
	int p = 3;

	for (int i = 0;i < 4;i++) {
		sbox1[i] = cos[i];
		sbox2[i] = cos[i + 4];
	}

	for (int i = 0;i < 4;i++) {
		a = a + (sbox1[i] * (pow(2, p)));
		p = p - 1;
	}
	p = 3;
	for (int i = 0;i < 4;i++) {

		b = b + (sbox2[i] * (pow(2, p)));
		p = p - 1;
	}
	
	if (a == 0 || a == 5 || a == 10 || a == 12 || a == 11) { sbox[0] = 0;sbox[1] = 1; }
	if (a == 4 || a == 1 || a == 14 || a == 9 || a == 13) { sbox[0] = 1;sbox[1] = 1; }
	if (a == 2 || a == 7 || a == 8) { sbox[0] = 0;sbox[1] = 0; }
	if (a == 6 || a == 3 || a == 15) { sbox[0] = 1;sbox[1] = 0; }

	if (b == 2 || b == 5 || b == 11 || b == 12) { sbox[2] = 0;sbox[3] = 1; }
	if (b == 6 || b == 7 || b == 8) { sbox[2] = 1;sbox[3] = 1; }
	if (b == 0 || b == 3 || b == 10 || b == 13 || b == 14) { sbox[2] = 0;sbox[3] = 0; }
	if (b == 1 || b == 4 || b == 9) { sbox[2] = 1;sbox[3] = 0; }
	

	int kopia_sbox[4] = { 0 };
	for (int i = 0;i < 4;i++) {
		kopia_sbox[i] = sbox[i];
	}
	//cout << "Po P4" << endl;
	for (int i = 0;i < 4;i++) {
		sbox[i] = kopia_sbox[P4[i]];
	}

	int cos2[4] = { 0 };
	for (int i = 3;i >= 0;i--) {
		cos2[i] = ((t[i] + sbox[i]));
		if (cos2[i] == 2) {
			cos2[i] = 0;
		}
		if (cos2[i] == 3) {
			cos2[i] = 1;
		}
	}
	//cout << "Po dodawaniu2" << endl;

	for (int i = 0;i < 4;i++) {
		ostatecznie[i] = cos2[i];
		ostatecznie[4+i] = t[4+i];
	}

}




int main() {

	int klucz[10] = { 1,1,0,1,1,0,0,1,0,1 };
	int w[] = { 0,1,0,1,0,1,1,1 };

	int P10[] = { 2,4,1,6,3,9,0,8,7,5 };
	int SL1[] = { 1,2,3,4,0 };
	int P10w8[] = { 5,2,6,3,7,4,9,8 };
	int SL2[] = { 2,3,4,0,1 };
	int P4[] = { 1, 3, 2, 0 };
	int PW[] = { 1,5,2,0,3,7,4,6 };
	int PO[] = { 3,0,2,4,6,1,7,5 };

	int cyfra;
	
	int kopia_klucz[10] = { 0 };
	int k0[5] = { 0 };
	int k1[5] = { 0 };
	int klucz1[8] = { 0 };
	int klucz2[8] = { 0 };
	int kopia[8] = { 0 };
	
	cout << "KLUCZ: " << endl;
	for (int i = 0;i < 10;i++) {
		cout << klucz[i];
	}
	for (int i = 0;i < 10;i++) {
		kopia_klucz[i] = klucz[i];
	}
	cout << endl;
	for (int i = 0;i < 10;i++) {
		klucz[i] = kopia_klucz[P10[i]];      
	}

	for (int i = 0;i < 5;i++) {
		k0[i] = klucz[i];
		k1[i] = klucz[i + 5];
	}
	for (int i = 0;i < 5;i++) {
	}
	for (int i = 0;i < 5;i++) {
	}

	int kopia_k0[5];
	int kopia_k1[5];
	for (int i = 0;i < 5;i++) {
		kopia_k0[i] = k0[i];
		kopia_k1[i] = k1[i];
	}

	for (int i = 0;i < 5;i++) {
		k0[i] = kopia_k0[SL1[i]];   
		k1[i] = kopia_k1[SL1[i]];
	}
	for (int i = 0;i < 5;i++) {
		klucz[i] = k0[i];
		klucz[i + 5] = k1[i];
	}

	cout << "Klucz pierwszej rundy" << endl;
	for (int i = 0;i < 8;i++) {
		klucz1[i] = klucz[P10w8[i]];        
		cout << klucz1[i];
	}cout << endl;

	for (int i = 0; i < 5;i++) {
		kopia_k0[i] = k0[SL2[i]];          
		kopia_k1[i] = k1[SL2[i]];
		klucz[i] = kopia_k0[i];
		klucz[i + 5] = kopia_k1[i];
	}
	cout << "Klucz drugiej rundy" << endl;
	for (int i = 0; i <8;i++) {
		klucz2[i] = klucz[P10w8[i]];
		cout << klucz2[i];
	}cout << endl;

	

	//PELEN PROCES SZYFROWANIA WIADOMOSCI W.


	cout <<endl << "TEKST: " << endl;
	for (int i = 0;i < 8;i++) {
		cout << w[i];
	}cout << endl;
	cout << "Po PW: " << endl;
	for (int i = 0;i <8;i++) {
		kopia[i] = w[PW[i]];
		cout << kopia[i];
	}cout << endl;
	
	int po_kluczu1[8] = { 0 };
	int po_kluczu1_kopia[8] = { 0 };

	szyfrowanie_kluczem(kopia, klucz1, po_kluczu1);
	cout << "Po szyfrowaniu kluczem 1: " << endl;
	for (int i = 0;i <8;i++) {
		cout << po_kluczu1[i];
	}cout << endl;


	for (int i = 0;i <8;i++) {
		kopia[i] = po_kluczu1[i];
	}

	for (int i = 0;i <4;i++) {
		kopia[i] = po_kluczu1[4+i];
		kopia[4+i] = po_kluczu1[i];
	}

	int po_kluczu2[8] = { 0 };

	szyfrowanie_kluczem(kopia, klucz2, po_kluczu2);
	
	cout << "Po szyfrowaniu kluczem 2: " << endl;
	for (int i = 0;i <8;i++) {
		cout << po_kluczu2[i];
	}cout << endl;

	int po_zaszyfrowaniu[8] = { 0 };
	
	for (int i = 0;i <8;i++) {
		kopia[i] = po_kluczu2[PO[i]];
	}
	cout << "Tekst zaszyfrowany" << endl;
	for (int i = 0;i <8;i++) {
		cout << kopia[i];
	}cout << endl;


	//ODSZYFROWANIE
	cout <<endl << "ODSZYFROWYWANIE " ;
	
	for (int i = 0;i <8;i++) {
		po_zaszyfrowaniu[i] = kopia[PW[i]];
	}
	szyfrowanie_kluczem(po_zaszyfrowaniu, klucz2, po_kluczu2);
	for (int i = 0;i <4;i++) {
		po_kluczu1_kopia[i] = po_kluczu2[4 + i];
		po_kluczu1_kopia[4 + i] = po_kluczu2[i];
	}
	szyfrowanie_kluczem(po_kluczu1_kopia, klucz1, po_kluczu2);
	for (int i = 0;i < 8;i++) {
		po_zaszyfrowaniu[i] = po_kluczu2[PO[i]];
		cout << po_zaszyfrowaniu[i];
	}cout << endl;



	system("PAUSE");
	return 0;
}

