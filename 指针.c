//�Զ��庯����ɽ��ռ��������6�����������䴢���������������aһά��������С�������������ø��Զ��庯�����������a�ĸ���Ԫ�ص�ֵ��
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
			printf("��%d��,��%d������\n", i + 1, j + 1);
			scanf("%d",*(A+i)+j);
		}
	}
}