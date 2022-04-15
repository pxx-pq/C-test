#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int judege_zs(int p, int q);
int gcd(int a, int b);
void menu();
int main()
{
	int i=0,t,j;
	long int M=1,C=1;
	int Un, N;int p, q;int e, d;
	menu();
	printf("请输入您的菜单选项："); scanf("%d",&t);
	while (t != 3) {
		printf("请输入两个质数："); scanf("%d%d", &p, &q);
		while (i == 0)
		{
			i = judege_zs(p, q);
			if (i == 0) 
			{ 
				printf("请重新输入两个质数："); 
				scanf("%d%d", &p, &q); 
			}
		}
		N = p * q; Un = (p - 1) * (q - 1);
		if (t == 1)//加密  C=M^e Mod N
		{
			printf("请输入要加密的明文："); scanf("%d",&M);
			while (1) {
				printf("请输入e："); scanf("%d", &e);
				if (gcd(Un, e) == 1)break;
				else { printf("请重新输入"); scanf("%d", &e);}
			}int YM = M;
			printf("得到公钥KU{%d,%d}\n",e,N);
			M = pow(M,e);
			printf("%d的%d次方为：%d\n",YM,e,M);
			C = M % N;
			printf("加密得到的密文：%d\n",C);
		}
		else if (t == 2)//解密  M=C^d Mod N
		{ 
			printf("请输入要解密的密钥："); scanf("%d", &C);
			while (1) {
				printf("请输入e："); scanf("%d", &e);
				if (gcd(Un, e) == 1)break;
				else { printf("请重新输入"); scanf("%d", &e); }
			} int YC = C;
			printf("得到公钥KU{%d,%d}\n", e, N);
			d=get_d(Un,e);
			printf("得到私钥KU{%d,%d}\n", d, N);
			C = pow(C, d);
			printf("%d的%d次方为：%d\n", YC, d, C);
			M = C % N;
			printf("解密得到的明文：%d\n", M); 
		}
		else { printf("菜单选择错误！请重新输入\n"); }
		menu();  scanf("%d", &t);
	}
	return  0;
}
void menu()
{
	printf("----------------\n");
	printf("1.加密\n");
	printf("2.解密\n");
	printf("3.退出\n");
	printf("----------------\n");
}
int get_d(int Un, int e)
{
	int a[100] = { 0 }; int b[100] = { 0 };
	int d = 0; int i, t, j;
	int YUn = Un;
	for (i = 0;; i++)
	{
		if (Un % e == 0)break;
		a[i] = Un / e;
		t = Un; Un = e; e = t % e;
	}
	b[0] = 1; b[1] = a[i - 1]; 
	printf("b[1]:%d",b[1]);
	for (t = 2; t < i + 1; t++)
	{
		b[t] = b[t - 2] + (a[i - t] * b[t - 1]);
	}
	if ((t + 1) % 2 != 0)d = YUn - b[t - 1];
	else d = b[t - 1];
	return d;
}
int gcd(int a, int b)//a大b小
{
	if (a % b == 0)return b;
	else gcd(b, a % b);
}
int judege_zs(int p,int q)
{
	int n=0; int i,j; int k,l;
	k = (int)sqrt((double)p);
	l = (int)sqrt((double)q);
	for (i = 2; i < k; i++)if (p % i == 0)break;
	for (j = 2; j < l; j++)if (p % j == 0)break;
	if (i < k && j < l) { printf("您输入的两个数都不是素数\n"); return n; }
	else if (i == k && j < l) { printf("您输入的第二个数不是素数\n"); return n;}
	else if (i < k && j == l) { printf("您输入的第一个数不是素数\n"); return n;}
	else { printf("您输入的两个数正好都是素数！\n"); n = 1; return n; }
}
