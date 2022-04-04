#include<stdio.h>
#include<string.h>
void menu();
void _10to2(int n[], int* a[]);
void _2to10(int* n[], int a[]);
void IP(int M[], int* Lside[], int* Rside[]);
void IP_n(int Lside[], int Rside[], int* MI[64]);
void Ebox(int a[], int* b[]);
void Sbox(int text[], int* bit[]);
void Pbox(int a[], int* b[]);
void key(int key[64], int* KeyC[16][48]);
int S[512] = {
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,

	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	13,8,10,1,3,15,4,2,11,6,7,12,10,5,14,9,

	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,

	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14,

	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
	4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,

	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,

	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,

	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};
int main()
{
	int Mingw[64]; int Miy[64]; int result[64];
	int mwprintf[30] = { 0 }, myprintf[30] = { 0 };
	int Lside[32] = { 0 }, Rside[32] = { 0 }, Lcenter[32] = { 0 };
	int _32ts1[32] = { 0 }, _32ts2[32] = { 0 }, _48ts1[48] = { 0 }, _48ts2[48] = { 0 };
	int n, i = 0, j, t, k = 0, y = 0;
	int KEY[16][48];
	menu();
	scanf("%d", &n);
	getchar();
	while (n != 3) {
		if (n == 1) {
			printf("请输入明文:");
			while (1) {
				k = 0; for (i = 0;; i++) { scanf("%d", &mwprintf[i]); k++; if (getchar() == '\n')break; }
				if (k < 16) { printf("您输入的数小于16位，剩余位补0。\n"); break; }
				else if (k > 16)printf("您输入的数已超标,请重新输入。\n");
				else if (k == 16) { printf("您输入的正正好!\n"); break; }
			}_10to2(mwprintf, Mingw); printf("十进制整数转换为二进制数是:"); for (i = 0; i < 64; i++)printf("%d", Mingw[i]); printf("\n");
			printf("请输入密钥:");
			while (1) {
				k = 0; for (i = 0;; i++) { scanf("%d", &myprintf[i]); k++; if (getchar() == '\n')break; }
				if (k < 16) { printf("您输入的数小于16位，剩余位补0。\n"); break; }
				else if (k > 16)printf("您输入的数已超标,请重新输入。\n");
				else if (k == 16) { printf("您输入的正正好!\n"); break; }
			}_10to2(myprintf, Miy); printf("十进制整数转换为二进制数是:"); for (i = 0; i < 64; i++)printf("%d", Miy[i]); printf("\n");

			IP(Mingw, Lside, Rside);
			printf("IP置换后为：\n");
			printf("Lside:"); for (i = 0; i < 32; i++) printf("%d", Lside[i]); printf("\n");
			printf("Rside:"); for (i = 0; i < 32; i++) printf("%d", Rside[i]); printf("\n");
			key(Miy, KEY); printf("key组为："); for (j = 0; j < 16; j++)
			{
				printf("\n"); for (i = 0; i < 48; i++)printf("%d", KEY[j][i]);
			}printf("\n");
			for (i = 0; i < 16; i++)
			{
				printf("\n"); printf("***第%d轮迭代:***\n", i + 1);
				for (t = 0; t < 32; t++)Lcenter[t] = Lside[t]; for (t = 0; t < 32; t++)Lside[t] = Rside[t];
				Ebox(Rside, _48ts1);
				for (t = 0; t < 48; t++) {//异或
					if (_48ts1[t] == KEY[i][t])_48ts2[t] = 0;
					else _48ts2[t] = 1;
				}
				printf("E盒和Kn异或后得到的数组为："); for (t = 0; t < 48; t++)printf("%d", _48ts2[t]); printf("\n");
				Sbox(_48ts2, _32ts1);
				printf("S盒结果:"); for (t = 0; t < 32; t++)  printf("%d", _32ts1[t]); printf("\n");
				Pbox(_32ts1, _32ts2);
				for (t = 0; t < 32; t++) {//异或
					if (_32ts2[t] == Lcenter[t])Rside[t] = 0;
					else Rside[t] = 1;
				}
				printf("P盒和Ln-1异或后得到的数组为："); for (t = 0; t < 32; t++)printf("%d", Rside[t]); printf("\n");
				printf("L;"); for (t = 0; t < 32; t++)printf("%d", Lside[t]);
				printf("R;"); for (t = 0; t < 32; t++)printf("%d", Rside[t]);
			}
			printf("\n"); printf("\n");
			for (t = 0; t < 32; t++)Lcenter[t] = Lside[t]; for (t = 0; t < 32; t++)Lside[t] = Rside[t]; for (t = 0; t < 32; t++)Rside[t] = Lcenter[t];
			printf("L;"); for (t = 0; t < 32; t++)printf("%d", Lside[t]);
			printf("R;"); for (t = 0; t < 32; t++)printf("%d", Rside[t]);
			IP_n(Lside, Rside, result);
			_2to10(mwprintf, result);
			printf("加密得密文为："); for (i = 0; i < 16; i++)printf("%d ", mwprintf[i]); printf("\n");
		}
		else if (n == 2)
		{
			printf("请输入密文:");
			while (1) {
				k = 0; for (i = 0;; i++)
				{
					scanf("%d", &mwprintf[i]); k++; if (getchar() == '\n')break;
				}
				if (k < 16) { printf("您输入的数小于16位，剩余位补0。\n"); break; }
				else if (k > 16)printf("您输入的数已超标,请重新输入。\n");
				else if (k == 16) { printf("您输入的正正好!\n"); break; }
			}
			_10to2(mwprintf, Mingw); printf("十进制整数转换为二进制数是:"); for (i = 0; i < 64; i++)printf("%d", Mingw[i]); printf("\n");
			printf("请输入密钥:");
			while (1) {
				k = 0; for (i = 0;; i++)
				{
					scanf("%d", &myprintf[i]); k++; if (getchar() == '\n')break;
				}
				if (k < 16) { printf("您输入的数小于16位，剩余位补0。\n"); break; }
				else if (k > 16)printf("您输入的数已超标,请重新输入。\n");
				else if (k == 16) { printf("您输入的正正好!\n"); break; }
			}
			_10to2(myprintf, Miy); printf("十进制整数转换为二进制数是:"); for (i = 0; i < 64; i++)printf("%d", Miy[i]); printf("\n");
			IP(Mingw, Lside, Rside);
			printf("IP置换后为：\n");
			printf("Lside:"); for (i = 0; i < 32; i++) printf("%d", Lside[i]); printf("\n");
			printf("Rside:"); for (i = 0; i < 32; i++) printf("%d", Rside[i]); printf("\n");
			key(Miy, KEY);
			for (i = 15; i >= 0; i--)
			{
				printf("\n"); printf("***第%d轮迭代:***\n", 16 - i);
				for (t = 0; t < 32; t++)Lcenter[t] = Lside[t]; for (t = 0; t < 32; t++)Lside[t] = Rside[t];
				Ebox(Rside, _48ts1);
				for (t = 0; t < 48; t++) {//异或
					if (_48ts1[t] == KEY[i][t])_48ts2[t] = 0;
					else _48ts2[t] = 1;
				}
				printf("E盒和Kn异或后得到的数组为："); for (t = 0; t < 48; t++)printf("%d", _48ts2[t]); printf("\n");
				Sbox(_48ts2, _32ts1);
				printf("S盒结果:"); for (t = 0; t < 32; t++)  printf("%d", _32ts1[t]); printf("\n");
				Pbox(_32ts1, _32ts2);
				for (t = 0; t < 32; t++) {//异或
					if (_32ts2[t] == Lcenter[t])Rside[t] = 0;
					else Rside[t] = 1;
				}
				printf("P盒和Ln-1异或后得到的数组为："); for (t = 0; t < 32; t++)printf("%d", Rside[t]); printf("\n");
			}
			for (t = 0; t < 32; t++)Lcenter[t] = Lside[t]; for (t = 0; t < 32; t++)Lside[t] = Rside[t]; for (t = 0; t < 32; t++)Rside[t] = Lcenter[t];
			IP_n(Lside, Rside, result);
			_2to10(mwprintf, result);
			printf("解密得明文为："); for (i = 0; i < 16; i++)printf("%d ", mwprintf[i]); printf("\n");
		}
		else break;
		printf("--------------\n"); printf("请再次选择\n"); menu(); scanf("%d", &n);
	}
	return 0;
}
void menu()
{
	printf("-------------------------\n");
	printf("请输入您的菜单选择：\n");
	printf("1.加密\n");
	printf("2.解密\n");
	printf("3.退出\n");
	printf("-------------------------\n");
}
void _10to2(int n[], int* a[])
{
	int i, num, j;
	for (i = 0; i < 16; i++) {//10->2
		num = n[i];//赋值表中十进制数
		for (j = 3; j >= 0 && num >= 0; j--) {
			a[j + (i * 4)] = num % 2;
			num = num / 2;
		}
	}
}
void _2to10(int* n[], int a[])
{
	int i = 0, x, num;
	for (x = 0; x < 16; x++)
	{
		num = 0;
		for (i = 0; i < 4; i++)
		{
			if (i == 0)     num = num + (a[i + (x * 4)] * 8);
			else if (i == 1)num = num + (a[i + (x * 4)] * 4);
			else if (i == 2)num = num + (a[i + (x * 4)] * 2);
			else if (i == 3)num = num + (a[i + (x * 4)] * 1);
		}
		n[x] = num;
	}
	printf("\n二进制整数转换为十进制数是:"); for (i = 0; i < 16; i++)printf("%d", n[i]); printf("\n");
}

void IP(int M[], int* Lside[], int* Rside[])
{
	int IP1[64] = {
					  58,50,42,34,26,18,10,2,
					  60,52,44,36,28,20,12,4,
					  62,54,46,38,30,22,14,6,
					  64,56,48,40,32,24,16,8,
					  57,49,41,33,25,17,9,1,
					  50,51,43,35,27,19,11,3,
					  61,53,45,37,29,21,13,5,
					  63,55,47,39,31,23,15,7
	};
	int i;
	int MIP[64];
	for (i = 0; i < 64; i++)  MIP[i] = M[IP1[i] - 1];      //下标从0开始
	printf("\nIP置换后为："); for (i = 0; i < 64; i++)  printf("%d", MIP[i]); printf("\n");
	for (i = 0; i < 32; i++)         //将64bit明文分为左右两部份
	{
		Lside[i] = MIP[i];
		Rside[i] = MIP[32 + i];
	}
}
void IP_n(int Lside[], int Rside[], int* MI[64])
{
	int m[64] = { 0 };
	int i;
	for (i = 0; i < 32; i++) {
		m[i] = Lside[i];
		m[i + 32] = Rside[i];
	}
	printf("左右结合的64位数组"); for (i = 0; i < 64; i++) printf("%d", m[i]); printf("\n");
	int IP2[64] = {
			   40,8,48,16,56,24,64,32,
			   39,7,47,15,55,23,63,31,
			   38,6,46,14,54,22,62,30,
			   37,5,45,13,53,21,61,29,
			   36,4,44,12,52,20,60,28,
			   35,3,43,11,51,19,59,27,
			   34,2,42,10,50,18,58,26,
			   33,1,41,9,49,17,57,25
	};
	for (i = 0; i < 64; i++) MI[i] = m[IP2[i] - 1];
	printf("IP逆置换后为："); for (i = 0; i < 64; i++) printf("%d", MI[i]); printf("\n");
}
void Ebox(int a[], int* b[])//32变48
{
	int etable[48] = {                                    //扩展矩阵  
	   32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
	   8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
	   16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
	   24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1 };
	int m, i;
	for (m = 0; m < 48; m++)  b[m] = a[etable[m] - 1];
	printf("E盒扩展后的48位数组："); for (i = 0; i < 48; i++)printf("%d", b[i]); printf("\n");
}
void Sbox(int text[], int* bit[])
{
	int i, j = 0, r, c; int z = 0; int num = 0; int a[32] = { 0 };
	for (i = 0; i < 48; i = i + 6) {
		r = (text[i] * 2) + (text[i + 5]);//表中的行数
		c = (text[i + 1] * 8) + (text[i + 2] * 4) + (text[i + 3] * 2) + (text[i + 4]);//列数
		text[j] = S[16 * r + c + 64 * j];//由S表得到相应input的值
		j++;
	};
	//_10to2(text,bit)
	for (i = 0; i < 8; i++) {//10->2
		num = text[i];//赋值表中十进制数
		for (j = 3; j >= 0 && num >= 0; j--) {
			a[j] = num % 2;
			num = num / 2;
		}
		for (j++; j >= 0 && j < 4; j++) {
			bit[z] = a[j];
			z++;
		}
	}
}
void Pbox(int a[], int* b[])
{
	int ptable[32] = {                                             //  P 盒  
	   16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23, 26, 5,  18, 31, 10,
	   2,  8, 24, 14, 32, 27, 3,  9,  19, 13, 30, 6,  22, 11, 4,  25 };
	int c[32] = { 0 };
	int n, i;
	for (n = 0; n < 32; n++)  b[n] = a[ptable[n] - 1];
	printf("P盒数组："); for (i = 0; i < 32; i++)printf("%d", b[i]); printf("\n");
}
void key(int k[64], int* key[16][48]) {
	int PC_1[56] =
	{
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,2,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4,
	};
	int PC_2[48] =
	{
		14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32,
	};
	int i, j, m, t, n = 0;
	int  pc_1[56] = { 0 }, pc_2[16][56] = { 0 }, C[28], m_C[16][28] = { 0 }, D[28], m_D[16][28] = { 0 };
	for (t = 0; t < 56; t++) pc_1[t] = k[PC_1[t] - 1];
	//分组
	for (i = 0; i < 28; i++) {
		C[i] = pc_1[i];
		D[i] = pc_1[i + 28];
	}
	//循环左移
	for (i = 1; i < 17; i++) {
		if (i == 1 || i == 2 || i == 9 || i == 16) {
			m = 1;
			n += m;
			for (t = 0; t < 28; t++) m_C[i - 1][t] = C[(t + n) % 28];
			for (t = 0; t < 28; t++) m_D[i - 1][t] = D[(t + n) % 28];
		}
		else {
			m = 2;
			n += m;
			for (t = 0; t < 28; t++) m_C[i - 1][t] = C[(t + n) % 28];
			for (t = 0; t < 28; t++) m_D[i - 1][t] = D[(t + n) % 28];
		}
	}
	for (i = 0; i < 16; i++) {//整合
		for (j = 0; j < 28; j++) {
			pc_2[i][j] = m_C[i][j];
			pc_2[i][j + 28] = m_D[i][j];
		}
	}
	for (i = 0; i < 16; i++)
		for (t = 0; t < 48; t++) {
			key[i][t] = pc_2[i][PC_2[t] - 1];
		}
}