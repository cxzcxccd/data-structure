#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct link
{
    int data;
    struct link *next;
}link;

typedef struct queue{
    link *head;
    link *tail;
}queue;
//初始化队列
void init(queue *Q)
{
    link *head=(link*)malloc(sizeof(link));
    Q->head=Q->tail=head;
    Q->head->next=NULL;
}
//判断队列是否为空
bool isempty(queue *Q)
{
    if(Q->head==Q->tail)  return 1;
    return 0;
}
//新元素入队
void  insert(queue*Q，int x)
{
    link *p=(link *)malloc(sizeof(link));
    p->data=x;
    p->next=NULL;
    Q->tail->next=p;//新结点接到上一个节点的尾部
    Q->tail=p;//新任队尾
}
//出队
void del(queue *Q,int *x)
{
    if(isempty(Q))
    {
        printf("队列为空，无法出队");
        return -1000000;
    }
   link *p=Q->front->next;
   Q->front->next=p->next;
   if(Q->tail==p) Q->tail=Q->head;
   *x=p->data;
   free(p);
}


int main()
{
    
    
    
    
    
    return 0;
}
