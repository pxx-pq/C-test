#include<stdio.h>
#include <string.h>
/*
ooo����
��������������ɲ���������ÿ��������������2�У���1��Ϊһ�����Ȳ�����5���ַ�����
��2��Ϊһ�����Ȳ�����80���ַ�����ע��������ַ��������ո񣬼��ո�Ҳ������Ҫ��ͳ�Ƶ��ַ�֮һ��
������'#'ʱ�����������Ӧ�Ľ����Ҫ�����
ooo���
��ÿ������������ͳ�Ƶ�1�����ַ�����ÿ���ַ��ڵ�2���ַ����г��ֵĴ����������¸�ʽ�����
c0 n0
c1 n1
c2 n2
...
����ci�ǵ�1���е�i���ַ���ni��ci���ֵĴ�����
*/
#include <stdio.h> 
int main()
{
	int i=0, j=0,c;
	int time;
	char line1[6], line2[81];//���ַ������С�\0����ռһ��λ�õ�
	int lengeh_1, length_2;
	while (1)
	{
		//���벿��
		while (getchar()!='#')
		{
			line1[i] = getchar();
			i++;
		}
		line1[i] = '\0';//���ַ������С�\0����ռһ��λ�õ�
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
		//��ӡ����
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