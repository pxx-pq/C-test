//自定义函数完成接收键盘输入的6个整数，将其储存于主函数定义的a一维数组变量中。主函数负责调用该自定义函数和输出数组a的各个元素的值。
#include<stdio.h>
void scanf_A(int(*A)[3]);
int main()
{
	int a[4][3], i, j;
	scanf_A(a);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("a[%d][%d]=%d\t", i, j, a[i][j]);
		}
		return 0;
	}
}
void scanf_A(int(*A)[3]){
	int i,j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; i < 3; j++)
		{
			printf("第%d行,第%d个数据\n", i + 1, j + 1);
			scanf("%d",*(A+i)+j);
		}
	}
}