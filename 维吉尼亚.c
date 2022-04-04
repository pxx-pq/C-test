#include<stdio.h>
#include<string.h>
void menu();
int main()
{
	int n,k=1;
	menu();
	printf("请输入您要查询的业务\n");
	scanf("%d",&n);
	getchar();
	while (k==1) {
		if (n == 1){
			char mw[100] = { 0 };char my[100] = { 0 };//mw:明文，my:密钥
			char cz[100] = { 0 };char result[100] = { 0 };//cz:重组 
			int i = 0, j = 0, k, t;
			printf("请输入明文：");gets(mw); i = strlen(mw);
			printf("请输入密钥：");gets(my); j = strlen(my);
			if (i > j){
				for (k = 0, t = 0; k < i; k++, t++){
					if (t == j)t = 0;
					cz[k] = my[t];
				}
			}
			else  for (k = 0; k < i; k++) cz[k] = my[k];
			for (k = 0,n=0; k < i; k++,n++) {
				if ((mw[k] >= 'A' && mw[k] <= 'Z')&&(cz[n] >= 'A' && cz[n] <= 'Z'))
					result[k] = (cz[n] + mw[k] - 130) % 26 + 65;
				else if((mw[k] >= 'A' && mw[k] <= 'Z') && (cz[n] >= 'a' && cz[n] <= 'z'))
					result[k] = (cz[n] + mw[k] - 162) % 26 + 65;
				else if ((mw[k] >= 'a' && mw[k] <= 'z') && (cz[n] >= 'A' && cz[n] <= 'Z'))
					result[k] = (cz[n] + mw[k] - 162) % 26 + 97;
				else if ((mw[k] >= 'a' && mw[k] <= 'z') && (cz[n] >= 'a' && cz[n] <= 'z'))
					result[k] = (cz[n] + mw[k] - 194) % 26 + 97;
				else { result[k] = mw[k]; n = n - 1; }
			}
			printf("由维吉尼亚可得出的密文是:");
			for (k = 0; k < i; k++)printf("%c",result[k]);
			printf("\n");
		}
		else if (n == 2)
		{
			char mw[100] = { 0 }; char my[100] = { 0 };//mw:密文，my:密钥
			char cz[100] = { 0 }; char result[100] = { 0 };//cz:重组 
			int i = 0, j = 0, k, t;
			printf("请输入密文："); gets(mw); i = strlen(mw);
			printf("请输入密钥："); gets(my); j = strlen(my);
			if (i > j) {
				for (k = 0, t = 0; k < i; k++, t++) {
					if (t == j)t = 0;
					cz[k] = my[t];
				}
			}
			else  for (k = 0; k < i; k++) cz[k] = my[k];
			for (k = 0,n=0; k < i; k++,n++) { 
				if ((mw[k] >= 'A' && mw[k] <= 'Z') && (cz[n] >= 'A' && cz[n] <= 'Z'))
					result[k] = ((mw[k] - cz[n]+26) % 26) + 65;
				else if ((mw[k] >= 'A' && mw[k] <= 'Z') && (cz[n] >= 'a' && cz[n] <= 'z'))
					result[k] = ((mw[k] - cz[n]+32+26) % 26) + 65;
				else if ((mw[k] >= 'a' && mw[k] <= 'z') && (cz[n] >= 'A' && cz[n] <= 'Z'))
					result[k] = ((mw[k] - cz[n]-32+26) % 26) + 97;
				else if ((mw[k] >= 'a' && mw[k] <= 'z') && (cz[n] >= 'a' && cz[n] <= 'z'))
					result[k] = ((mw[k] - cz[n]+26) % 26) + 97;
				else { result[k] = mw[k]; n = n - 1; }
				 }
			printf("有维吉尼亚可得出的明文是:");
			for (k = 0; k < i; k++)printf("%c", result[k]);
			printf("\n");
		}
		else if (n == 3)break;
		else printf("抱歉 错误！\n");
		printf("----------------------\n");
		printf("请输入您要查询的业务\n");
		scanf("%d", &n);
		getchar();
	}
	return 0;
}
void menu()
{
	printf("1.维吉尼亚加密\n");
	printf("2.维吉尼亚解密\n");
	printf("3.退出\n");
}
