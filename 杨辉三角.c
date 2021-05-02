#include<stdio.h>
//打印杨辉三角
int main()
{
	int i, j;//i=行j=列
	int one_cen[10][10];
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j <= i; j++)
			{
				if (i == j || j == 0)
					one_cen[i][j] = 1;
				else
					one_cen[i][j] = one_cen[i - 1][j] + one_cen[i - 1][j - 1];
				printf("%5d", one_cen[i][j]);
			}
			printf("\n");
	}
	return 0;
}