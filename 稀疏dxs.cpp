#include <stdio.h>
#include <malloc.h>
//定义多项式链表的结点
typedef struct Pnode {
	float coef;//系数
	int expn;//指数
	struct Pnode* next;//指针域,指向多项式的一个项的结点指针
}Pnode, * Polynomial/*指向结构体的指针*/;
void CreatePolyn(Polynomial& P, int n);
int main() {
	Pnode* head_A, * head_B, * head_AB;
	Pnode* P_A, * P_B, * P_AB, * r;
	int n1, n2;
	int sum = 0;
	printf("请输入p1的项数\n");
	scanf("%d", &n1);
	CreatePolyn(head_A, n1);
	printf("请输入p2的项数\n");
	scanf("%d", &n2);
	CreatePolyn(head_B, n2);
	//相加两个链表
	P_A = head_A->next;
	P_B = head_B->next;
	P_AB = head_A;
	while (P_A && P_B) {
		if (P_A->expn == P_B->expn) {
			sum = P_A->coef + P_B->coef;
			if (sum != 0) {
				P_A->coef = sum;
				P_AB->next = P_A;//相加结果存储到P_AB所指向的结点
				P_AB = P_A;//P_AB后移一位
				P_A = P_A->next;//P_A后移一位
				r = P_B;//r暂时保存P_B 指向的节点，便于释放
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
	//打印相加后的链表
	head_AB = head_A->next;//head_AB指向首元结点
	while (head_AB) {
		printf("%fx^%d", head_AB->coef, head_AB->expn);
		if (head_AB->next && head_AB->next->coef > 0)
			printf("+");//下一位如果是正数输出加号
		head_AB = head_AB->next;
	}
	return 0;
}
void CreatePolyn(Polynomial &P, int n) {//建立稀疏多项式链表:
	Pnode* S, * pre, * pa;
	P = (Polynomial)malloc(sizeof(Pnode));
	P->next = NULL;//链表初始化
	int i;
	for (i = 1; i <= n; i++) {
		printf("请输入第%d项的系数和指数\n", i);
		S = (Pnode*)malloc(sizeof(Pnode));//生成新节点
		scanf("%f %d", &S->coef, &S->expn);
		pre = P;//pre指向头结点
		pa  = P->next;//pa指向首元结点
		//让多项式链表的有序排列
		while (pa && pa->expn  <  S->expn) {//当输入的指数大于pa指向的指数
			pre = pa;//pre后移一位
			pa = pa->next;//pa后移一位
		}
		S->next = pa;//将输入项pa插入到pa和其前趋结点pre之间
		pre->next = S;
	}
}
