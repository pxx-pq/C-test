#include<stdio.h>
void quick_sort(int S[], int left, int right);
int main()
{
	int i;
	int arr[10] = { 4, 1, 21, 5, 6, 2, 0, 9, 31, 81 };
	for (i = 0; i < 10; i++)  //7到9行打印原来的数组的样子
		printf("%d ", arr[i]);
	printf("\n");
    quick_sort(arr, 0, 9);//10到13行是快速排列后数组的样子
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
void quick_sort(int S[], int left, int right)
{
    if (left < right)//必须要左边的小于右边的
    {
        int i = left, j = right, x = S[left];
        while (i < j)//但i=j时跳出循环
        {
            while (i < j && S[j] >= x) // 从右向左一直循环到s[i]!<x
            {
                j--;
                if (S[j] < x)
                {
                    S[i] = S[j];
                    break;
                }
            }
            while (i < j && S[i] < x) // 从左向右一直循环到s[i]!<x
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
        quick_sort(S, left, i - 1); // 递归调用 
        quick_sort(S, i + 1, right);
    }
}
