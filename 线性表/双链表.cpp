#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct link
{
	int data;
	struct link* next;
	struct link* prior;
}link;
link* append(link* tail)
{
	int x;
	scanf("%d", &x);
	link* p = NULL;
	link* pr = tail;
	p = (link*)malloc(sizeof(link));
	p->data = x;
	p->next = NULL;
	p->prior = pr;
	pr->next = p;
	return p;
}
int main()
{
	link* head = NULL;
	head = (link*)malloc(sizeof(link));
	head->next = NULL;
	head->prior = NULL;
	link* tail = head;
	int n = 5;
	while (n--) tail = append(tail);
	link* p = head;
	while (p->next != NULL)
	{
		cout << p->data<<" ";
		if(p->prior!=NULL) cout<<p->prior->data<<" ";
		if(p->next!=NULL) cout<<p->next->data<<"\n";
		p = p->next;
	}
	cout << p->data<<" ";
	return 0;
}
