//�Զ��庯����ɽ��ռ�������ı�����ݣ����䴢���������������a�ṹ����������С�������������ø��Զ��庯�����������a�����ݣ��б���ʽ�������
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
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n", A->xuehao, A->name, A->Chinese, A->Math, A->English);
	}
	return 0;
	
}
void scanf_A(STU *A) {
	int i;
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\n");
	for (i = 0; i < 3; i++, A++)
	{
		scanf("%d%s%d%d%d", &A->xuehao, A->name, &A->Chinese, &A->Math, &A->English);
	}
}