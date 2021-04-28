#include<stdio.h>
void a_tier(int n);
int main()
{
	int n,k,j;
	scanf_s("%d",&n);
	for (k=1;k<=n;k++)
	{
		for (j = k ; j <=n ; j++)
		{
			printf(" ");
		}
		a_tier(k);
		printf("\n");//换行
	}
}
//打印一层的数字
void a_tier(int n)
{
	int i ;
	for (i = 1; i <= n; i++)
	{
		printf("%2d",n);
	}
}