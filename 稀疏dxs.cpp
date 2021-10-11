#include <stdio.h>
#include <malloc.h>
//�������ʽ����Ľ��
typedef struct Pnode {
	float coef;//ϵ��
	int expn;//ָ��
	struct Pnode* next;//ָ����,ָ�����ʽ��һ����Ľ��ָ��
}Pnode, * Polynomial/*ָ��ṹ���ָ��*/;
void CreatePolyn(Polynomial& P, int n);
int main() {
	Pnode* head_A, * head_B, * head_AB;
	Pnode* P_A, * P_B, * P_AB, * r;
	int n1, n2;
	int sum = 0;
	printf("������p1������\n");
	scanf("%d", &n1);
	CreatePolyn(head_A, n1);
	printf("������p2������\n");
	scanf("%d", &n2);
	CreatePolyn(head_B, n2);
	//�����������
	P_A = head_A->next;
	P_B = head_B->next;
	P_AB = head_A;
	while (P_A && P_B) {
		if (P_A->expn == P_B->expn) {
			sum = P_A->coef + P_B->coef;
			if (sum != 0) {
				P_A->coef = sum;
				P_AB->next = P_A;//��ӽ���洢��P_AB��ָ��Ľ��
				P_AB = P_A;//P_AB����һλ
				P_A = P_A->next;//P_A����һλ
				r = P_B;//r��ʱ����P_B ָ��Ľڵ㣬�����ͷ�
				P_B = P_B->next;free(r);
			}
			else {
				r = P_A;
				P_A = P_A->next;
				free(r);
				r = P_B;
				P_B = P_B->next;free(r);
			}
		}
		else if (P_A->expn < P_B->expn) {
			P_AB->next = P_A;
			P_AB = P_A;
			P_A = P_A->next;
		}
		else {
			P_AB->next = P_B;
			P_AB = P_B;
			P_B = P_B->next;
		}
	}
	P_AB->next = P_A ? P_A : P_B;
	free(head_B);
	//��ӡ��Ӻ������
	head_AB = head_A->next;//head_ABָ����Ԫ���
	while (head_AB) {
		printf("%fx^%d", head_AB->coef, head_AB->expn);
		if (head_AB->next && head_AB->next->coef > 0)
			printf("+");//��һλ�������������Ӻ�
		head_AB = head_AB->next;
	}
	return 0;
}
void CreatePolyn(Polynomial &P, int n) {//����ϡ�����ʽ����:
	Pnode* S, * pre, * pa;
	P = (Polynomial)malloc(sizeof(Pnode));
	P->next = NULL;//�����ʼ��
	int i;
	for (i = 1; i <= n; i++) {
		printf("�������%d���ϵ����ָ��\n", i);
		S = (Pnode*)malloc(sizeof(Pnode));//�����½ڵ�
		scanf("%f %d", &S->coef, &S->expn);
		pre = P;//preָ��ͷ���
		pa  = P->next;//paָ����Ԫ���
		//�ö���ʽ�������������
		while (pa && pa->expn  <  S->expn) {//�������ָ������paָ���ָ��
			pre = pa;//pre����һλ
			pa = pa->next;//pa����һλ
		}
		S->next = pa;//��������pa���뵽pa����ǰ�����pre֮��
		pre->next = S;
	}
}
