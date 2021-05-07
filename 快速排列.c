#include<stdio.h>
void quick_sort(int S[], int left, int right);
int main()
{
	int i;
	int arr[10] = { 4, 1, 21, 5, 6, 2, 0, 9, 31, 81 };
	for (i = 0; i < 10; i++)  //7��9�д�ӡԭ�������������
		printf("%d ", arr[i]);
	printf("\n");
    quick_sort(arr, 0, 9);//10��13���ǿ������к����������
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
void quick_sort(int S[], int left, int right)
{
    if (left < right)//����Ҫ��ߵ�С���ұߵ�
    {
        int i = left, j = right, x = S[left];
        while (i < j)//��i=jʱ����ѭ��
        {
            while (i < j && S[j] >= x) // ��������һֱѭ����s[i]!<x
            {
                j--;
                if (S[j] < x)
                {
                    S[i] = S[j];
                    break;
                }
            }
            while (i < j && S[i] < x) // ��������һֱѭ����s[i]!<x
            {
                i++;
                if (S[i] >= x)
                {
                    S[j] = S[i];
                    break;
                }
            }
        }
        S[i] = x;
        quick_sort(S, left, i - 1); // �ݹ���� 
        quick_sort(S, i + 1, right);
    }
}
