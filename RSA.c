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
	printf("���������Ĳ˵�ѡ�"); scanf("%d",&t);
	while (t != 3) {
		printf("����������������"); scanf("%d%d", &p, &q);
		while (i == 0)
		{
			i = judege_zs(p, q);
			if (i == 0) 
			{ 
				printf("��������������������"); 
				scanf("%d%d", &p, &q); 
			}
		}
		N = p * q; Un = (p - 1) * (q - 1);
		if (t == 1)//����  C=M^e Mod N
		{
			printf("������Ҫ���ܵ����ģ�"); scanf("%d",&M);
			while (1) {
				printf("������e��"); scanf("%d", &e);
				if (gcd(Un, e) == 1)break;
				else { printf("����������"); scanf("%d", &e);}
			}int YM = M;
			printf("�õ���ԿKU{%d,%d}\n",e,N);
			M = pow(M,e);
			printf("%d��%d�η�Ϊ��%d\n",YM,e,M);
			C = M % N;
			printf("���ܵõ������ģ�%d\n",C);
		}
		else if (t == 2)//����  M=C^d Mod N
		{ 
			printf("������Ҫ���ܵ���Կ��"); scanf("%d", &C);
			while (1) {
				printf("������e��"); scanf("%d", &e);
				if (gcd(Un, e) == 1)break;
				else { printf("����������"); scanf("%d", &e); }
			} int YC = C;
			printf("�õ���ԿKU{%d,%d}\n", e, N);
			d=get_d(Un,e);
			printf("�õ�˽ԿKU{%d,%d}\n", d, N);
			C = pow(C, d);
			printf("%d��%d�η�Ϊ��%d\n", YC, d, C);
			M = C % N;
			printf("���ܵõ������ģ�%d\n", M); 
		}
		else { printf("�˵�ѡ���������������\n"); }
		menu();  scanf("%d", &t);
	}
	return  0;
}
void menu()
{
	printf("----------------\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.�˳�\n");
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
int gcd(int a, int b)//a��bС
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
	if (i < k && j < l) { printf("�����������������������\n"); return n; }
	else if (i == k && j < l) { printf("������ĵڶ�������������\n"); return n;}
	else if (i < k && j == l) { printf("������ĵ�һ������������\n"); return n;}
	else { printf("����������������ö���������\n"); n = 1; return n; }
}
