#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//小学生计算机辅助教学系统
/*连做十道简单四则运算，两个操作数为1到10之间的随机数，运算类型为随机产生的加减乘除中任意一种
不给机会重做，如果学生答对显示（Right），否则（Wrong）,每题10分，计算总分。*/
int main() {
	srand((unsigned)time(NULL));
	int a, b, right = 0, i = 0, input;
	int B, result = 0;
	char A;
	printf("----------------------------\n");
	for (i = 0; i < 10; i++) {
		a = rand() % 10 + 1;//a,b两个操作数
		b = rand() % 10 + 1;
		B = rand() % 4;//16到20行做好后续所需的符号和判断其中的条件
		if (B == 0) { A = '+'; result = a + b; }
		if (B == 1) { A = '-'; result = a - b; }
		if (B == 2) { A = '*'; result = a * b; }
		if (B == 3) { A = '/'; result = a / b; }//这里有点问题，但是不太清楚如何更改
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
