#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//Сѧ�������������ѧϵͳ
/*����ʮ�����������㣬����������Ϊ1��10֮������������������Ϊ��������ļӼ��˳�������һ��
�����������������ѧ�������ʾ��Right��������Wrong��,ÿ��10�֣������ܷ֡�*/
int main() {
	srand((unsigned)time(NULL));
	int a, b, right = 0, i = 0, input;
	int B, result = 0;
	char A;
	printf("----------------------------\n");
	for (i = 0; i < 10; i++) {
		a = rand() % 10 + 1;//a,b����������
		b = rand() % 10 + 1;
		B = rand() % 4;//16��20�����ú�������ķ��ź��ж����е�����
		if (B == 0) { A = '+'; result = a + b; }
		if (B == 1) { A = '-'; result = a - b; }
		if (B == 2) { A = '*'; result = a * b; }
		if (B == 3) { A = '/'; result = a / b; }//�����е����⣬���ǲ�̫�����θ���
		printf("%d%c%d=", a, A, b);
		scanf("%d", &input);
		if (input == result)
		{
			printf("Right\n" );
			right++;
		}
		else if (input != result)
			printf("Wrong\n");
		if (i == 9)
		{
			printf("you got a score is:%d", right * 10);
			break;
		}
	}
	return 0;
}
