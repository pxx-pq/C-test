#include<stdio.h>
int Common_multiple(int a,int b);
int main() {
	int n1, n2,number;
	printf("Input n1 n2:");
	scanf_s("%d%d",&n1,&n2);
	number=Common_multiple(n1, n2);
	printf("%d",number);
	return 0;
}
int Common_multiple(int a, int b)
{
	int max,i;
	if (a >= b) {
		max = a;
	}
	else
		max = b;
	for (i = max;; i++)
	{
		if (i % a == 0 && i % b == 0)
			break;
	}

	return i;
}