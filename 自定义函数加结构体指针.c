//自定义函数完成接收键盘输入的表格数据，将其储存于主函数定义的a结构体数组变量中。主函数负责调用该自定义函数和输出数组a的内容（列表形式输出）。
#include<stdio.h>
typedef struct stu {
	int xuehao;
	char name[10];
	int Chinese;
	int Math;
	int English;
}STU;
void scanf_A(STU* A);
int main()
{
	int  i;
	STU* A;
	A = (STU*)malloc(3* sizeof(STU));
	scanf_A(A);
	printf("学号\t姓名\t语文\t数学\t英语\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n", A->xuehao, A->name, A->Chinese, A->Math, A->English);
	}
	return 0;
	
}
void scanf_A(STU *A) {
	int i;
	printf("学号\t姓名\t语文\t数学\t英语\n");
	for (i = 0; i < 3; i++, A++)
	{
		scanf("%d%s%d%d%d", &A->xuehao, A->name, &A->Chinese, &A->Math, &A->English);
	}
}