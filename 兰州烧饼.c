#include<stdio.h>
//烧饼有两面，要做好一个兰州烧饼，要两面都弄热。
//当然，一次只能弄一个的话，效率就太低了。
//有这么一个大平底锅，一次可以同时放入k个兰州烧饼，一分钟能做好一面。
//而现在有n个兰州烧饼，至少需要多少分钟才能全部做好呢？
int main()
{
	int bing_numb, pot_numb,T,dividend;
		T = 0;
	printf("请输入您的锅能放几个兰州烧饼");
	scanf("%d",&pot_numb);
	printf("请输入您有几个兰州烧饼");
	scanf("%d",&bing_numb);
	dividend = bing_numb % pot_numb;
	if (bing_numb >= pot_numb && bing_numb % pot_numb == 0)
		T = 2 * (bing_numb / pot_numb);
	else if (pot_numb >= bing_numb)
		T = 2;
	if (bing_numb >= pot_numb && bing_numb % pot_numb != 0)
		T = (bing_numb/pot_numb+1)*2;
	printf("需要花费时间为：%d分钟",T);
	return 0;
}