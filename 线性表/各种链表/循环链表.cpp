#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
typedef struct link
{
	int data;
	struct link* next;
}link;
link *append(link *head)
{
	link* p = NULL, *pr = head;
	p = (link*)malloc(sizeof(link));
	if (head == NULL) head = p;
	else
	{
		while (pr->next != head)	pr = pr->next;
		pr->next = p;
	}
	p->next = head;
	int x;
	scanf_s("%d", &x);
	p->data = x;
	return head;
}
void shownum(link* head)
{
	link* p = head;
	if (head == NULL) return;
	do
	{
		cout << p->data<<" ";
		p = p->next;
	} while (p->next != head);
	cout << p->data << " ";
}


int  main()
{

     //链表初始化
	link* head = NULL;
	//输入链表的长度
	scanf_s("%d", &n);
	int k = n;
	while (k--)  head = append(head);
	shownum(head);
	return 0;
}
