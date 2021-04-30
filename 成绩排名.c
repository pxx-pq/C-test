#include<stdio.h>
/*成绩排名（接收输入成绩并输出成绩最高的和成绩最低的名字和学号）*/
int main()
{
	int max=0, min=100;
	int n,i,j=0,k=0;
	char name[100][11],xuehao[100][11];
	int score[100];
	scanf_s("%d",&n);//几个人
	for (i = 0; i < n; i++)
	{
		fflush(stdin);//清空输入缓冲区
		scanf_s("%s",name[i],11);//只能输10个字符
		getchar();//接收回车键
		scanf_s("%s",xuehao[i],11);
		scanf_s("%d", &score[i]);
		if (score[i] >= max)
		{
			max = score[i];
			j = i;//记住当前的下标
		}
		if (score[i] <= min)
		{
			min = score[i];
			k = i;//记住当前的下标
		}
	}
	printf("%s %s\n",name[j],xuehao[j]);
	printf("%s %s\n", name[k],xuehao[k]);
	return 0;
}