#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list* ne;
};
//在末尾插上一个数字，然后返回头节点
struct  list* headin(struct list *head) //这里要注意结构体指针函数的引用，需要在list后面加上星号‘*’。
{
	struct list * p = NULL, *pr = head;
	p = (struct list*)malloc(sizeof(struct list));
	scanf_s("%d", &p->data);
	if (head == NULL) head = p;  //若原链表为空链表，那么head=p，这里的head就是p，p的data就是head的，head这个头节点存了数据
	else
	{
		while (pr->ne != NULL) pr=pr->ne;//如果原链表不是空链表，那么就遍历到这个链表的最后一个节点位置，判断条件就是最后一个节点的ne指针指向NULL。
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
//删除与x相同的节点
struct list *del(struct list* head, int x)
{	
	struct list* p = head;
	struct list* pr = head;  //pr就是previous是过去的，意思是存储p的上一个节点，
	while (x != p->data && p->ne != NULL)
	{
		pr = p;
		p = p->ne;
	}
	if (x == p->data)
	{
		if (p == head) head = p->ne;//因为这里改变了head所以没办法，仍然要做成传值函数.
		else pr->ne = p->ne;
		free(p);
	}
	return head;
}

int main()
{
	struct list* head = NULL;
	struct list* tail = NULL;
	//输入n，代表你想要创建一个从1到n的链表
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) head=headin(head);
	print(head);
	//假设我们需要删除1
	head=del(head, 1);
	print(head);
	return 0;
}
