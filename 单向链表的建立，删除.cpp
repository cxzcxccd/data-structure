#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list* ne;
};
//��ĩβ����һ�����֣�Ȼ�󷵻�ͷ�ڵ�
struct  list* headin(struct list *head) //����Ҫע��ṹ��ָ�뺯�������ã���Ҫ��list��������Ǻš�*����
{
	struct list * p = NULL, *pr = head;
	p = (struct list*)malloc(sizeof(struct list));
	scanf_s("%d", &p->data);
	if (head == NULL) head = p;  //��ԭ����Ϊ��������ôhead=p�������head����p��p��data����head�ģ�head���ͷ�ڵ��������
	else
	{
		while (pr->ne != NULL) pr=pr->ne;//���ԭ�����ǿ�������ô�ͱ����������������һ���ڵ�λ�ã��ж������������һ���ڵ��neָ��ָ��NULL��
		pr->ne = p;
	}
	p->ne = NULL;
	return head;
}
void print(struct list* head)
{
	struct list* p = head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->ne;
	}
	printf("\n");
}
//ɾ����x��ͬ�Ľڵ�
struct list *del(struct list* head, int x)
{	
	struct list* p = head;
	struct list* pr = head;  //pr����previous�ǹ�ȥ�ģ���˼�Ǵ洢p����һ���ڵ㣬
	while (x != p->data && p->ne != NULL)
	{
		pr = p;
		p = p->ne;
	}
	if (x == p->data)
	{
		if (p == head) head = p->ne;//��Ϊ����ı���head����û�취����ȻҪ���ɴ�ֵ����.
		else pr->ne = p->ne;
		free(p);
	}
	return head;
}

int main()
{
	struct list* head = NULL;
	struct list* tail = NULL;
	//����n����������Ҫ����һ����1��n������
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) head=headin(head);
	print(head);
	//����������Ҫɾ��1
	head=del(head, 1);
	print(head);
	return 0;
}
