#include<stdio.h>
//�ձ������棬Ҫ����һ�������ձ���Ҫ���涼Ū�ȡ�
//��Ȼ��һ��ֻ��Ūһ���Ļ���Ч�ʾ�̫���ˡ�
//����ôһ����ƽ�׹���һ�ο���ͬʱ����k�������ձ���һ����������һ�档
//��������n�������ձ���������Ҫ���ٷ��Ӳ���ȫ�������أ�
int main()
{
	int bing_numb, pot_numb,T,dividend;
		T = 0;
	printf("���������Ĺ��ܷż��������ձ�");
	scanf("%d",&pot_numb);
	printf("���������м��������ձ�");
	scanf("%d",&bing_numb);
	dividend = bing_numb % pot_numb;
	if (bing_numb >= pot_numb && bing_numb % pot_numb == 0)
		T = 2 * (bing_numb / pot_numb);
	else if (pot_numb >= bing_numb)
		T = 2;
	if (bing_numb >= pot_numb && bing_numb % pot_numb != 0)
		T = (bing_numb/pot_numb+1)*2;
	printf("��Ҫ����ʱ��Ϊ��%d����",T);
	return 0;
}