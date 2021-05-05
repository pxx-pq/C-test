#include<stdio.h>
#include <string.h>
/*
ooo输入
测试输入包含若干测试用例，每个测试用例包含2行，第1行为一个长度不超过5的字符串，
第2行为一个长度不超过80的字符串。注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。
当读到'#'时输入结束，相应的结果不要输出。
ooo输出
对每个测试用例，统计第1行中字符串的每个字符在第2行字符串中出现的次数，按如下格式输出：
c0 n0
c1 n1
c2 n2
...
其中ci是第1行中第i个字符，ni是ci出现的次数。
*/
#include <stdio.h> 
int main()
{
	int i=0, j=0,c;
	int time;
	char line1[6], line2[81];//在字符数组中’\0’是占一个位置的
	int lengeh_1, length_2;
	while (1)
	{
		//输入部分
		while (getchar()!='#')
		{
			line1[i] = getchar();
			i++;
		}
		line1[i] = '\0';//在字符数组中’\0’是占一个位置的
		if (line1[0] == '#')
			break;
		while (getchar() != '#')
		{
			line2[j] = getchar();
			j++;
		}
		line2[j] = '\0';
		lengeh_1 = strlen(line1);
		length_2 = strlen(line2);
		//打印部分
		for (i = 0; i < lengeh_1; i++)
		{time = 0;
			for (j = 0; j < length_2; j++)
			{
				if (line1[i] == line2[j])
					time++;
			}
		printf("%c %d\n",line1[i],time);
		}
	}
	return 0;
}