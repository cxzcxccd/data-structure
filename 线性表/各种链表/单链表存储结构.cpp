#include<stdio.h>
#include<stdlib.h>
typedef  struct link
{
    int data;
    struct link * next;
}link;
//函数功能：新建一个节点并添加到链表末尾，返回添加节点后的链表的头指针
link *Appendlink(link *head)
{
    link *p=NULL,*pr=head;
    int x;
    p=(link *)malloc(sizeof(link));
  if(head==NULL)  head=p;
  else 
{
    while(pr->next!=NULL)   pr=pr->next;
    pr->next=p;
}
p->next=NULL;
//接下来输入p的数据
scanf("%d",&x);
p->data=x;
return head;
}
//在第k个数后面添加一个数
link *Appendmid(link *head,int k)
{
    int i=0;
    link *p=head;
    while(p->next!=NULL)
    {
        if(i==k-1) break;
        p=p->next;
        i++;
    }
link *pr=NULL;
pr=(link *)malloc(sizeof(link));
int x;
scanf("%d",&x);
pr->data=x;
pr->next=p->next;
p->next=pr;
return head;
}
//删除第k个数后面的那一个数
void del(link *head,int k)
{
    int i=0;
    link *p=head;
    while(p->next!=NULL)
    {
        if(i==k-1) break;
        p=p->next;
        i++;
    }
    link *pr=p->next;
    p->next=p->next->next;
    free(pr);
}
//打印整个链表
void shownum(link *head)
{
    link *p=head;
    while(p!=NULL) 
    {
        printf("%d ",p->data);
        p=p->next;
    }  
    printf("\n");
}
int main()
{
    //创建链表，（初始化）
    int n;
    //定义头指针
    link *head=NULL;
    //输入链表长度n
    scanf("%d",&n);
  while(n--)  head=Appendlink(head);
  //实例输入 5 1 2 3 4 5
   shownum(head);
  //删除第二个数后面的数
   del(head,2);
   shownum(head);
   //在第二个数后面加上250
   head=Appendmid(head,2);
   shownum(head);
    return 0;
}
