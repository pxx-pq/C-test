#include<stdio.h>
#include<string.h>
void menu();
int main()
{
	int n,k=1;
	menu();
	printf("��������Ҫ��ѯ��ҵ��\n");
	scanf("%d",&n);
	getchar();
	while (k==1) {
		if (n == 1){
			char mw[100] = { 0 };char my[100] = { 0 };//mw:���ģ�my:��Կ
			char cz[100] = { 0 };char result[100] = { 0 };//cz:���� 
			int i = 0, j = 0, k, t;
			printf("���������ģ�");gets(mw); i = strlen(mw);
			printf("��������Կ��");gets(my); j = strlen(my);
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
			printf("��ά�����ǿɵó���������:");
			for (k = 0; k < i; k++)printf("%c",result[k]);
			printf("\n");
		}
		else if (n == 2)
		{
			char mw[100] = { 0 }; char my[100] = { 0 };//mw:���ģ�my:��Կ
			char cz[100] = { 0 }; char result[100] = { 0 };//cz:���� 
			int i = 0, j = 0, k, t;
			printf("���������ģ�"); gets(mw); i = strlen(mw);
			printf("��������Կ��"); gets(my); j = strlen(my);
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
			printf("��ά�����ǿɵó���������:");
			for (k = 0; k < i; k++)printf("%c", result[k]);
			printf("\n");
		}
		else if (n == 3)break;
		else printf("��Ǹ ����\n");
		printf("----------------------\n");
		printf("��������Ҫ��ѯ��ҵ��\n");
		scanf("%d", &n);
		getchar();
	}
	return 0;
}
void menu()
{
	printf("1.ά�����Ǽ���\n");
	printf("2.ά�����ǽ���\n");
	printf("3.�˳�\n");
}
