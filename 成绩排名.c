#include<stdio.h>
/*�ɼ���������������ɼ�������ɼ���ߵĺͳɼ���͵����ֺ�ѧ�ţ�*/
int main()
{
	int max=0, min=100;
	int n,i,j=0,k=0;
	char name[100][11],xuehao[100][11];
	int score[100];
	scanf_s("%d",&n);//������
	for (i = 0; i < n; i++)
	{
		fflush(stdin);//������뻺����
		scanf_s("%s",name[i],11);//ֻ����10���ַ�
		getchar();//���ջس���
		scanf_s("%s",xuehao[i],11);
		scanf_s("%d", &score[i]);
		if (score[i] >= max)
		{
			max = score[i];
			j = i;//��ס��ǰ���±�
		}
		if (score[i] <= min)
		{
			min = score[i];
			k = i;//��ס��ǰ���±�
		}
	}
	printf("%s %s\n",name[j],xuehao[j]);
	printf("%s %s\n", name[k],xuehao[k]);
	return 0;
}