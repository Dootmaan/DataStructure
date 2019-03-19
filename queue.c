#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front;
    NODE *rear;
}QUEUE;

void Makenull(QUEUE *q)   //清空队列
{
    NODE *n;
    n=malloc(sizeof(NODE));
    q->front=n;
    q->front->next=NULL;
    q->rear=q->front;
}

int Empty(QUEUE *q)   //队列是否为空？
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    return 0;
}

void Enqueue(int x,QUEUE *q)   //入队
{
    NODE *n;
    n=malloc(sizeof(NODE));
    n->data=x;
    n->next=NULL;
    (q->rear)->next=n;
    q->rear=n;
}

NODE Dequeue(QUEUE *q)    //出队
{
    if(q->front==q->rear)
    {
        printf("没有可删除的");
    }
    else{
        NODE *t;
        t=q->front->next;
        q->front->next=t->next;
        if (t->next==NULL) 
            q->rear=q->front; 
        //NODE *t not deleted!!
        return *t;
    }
}

int Front(QUEUE *q)   //返回队首元素
{
    if(q->front!=q->rear)
    {
        return q->front->data;
    }
}

void Print(QUEUE *q)       //打印整个队列
{
    NODE *p;
    p=q->front->next;
    printf("(");
    while(p->next != NULL)
    {
        printf("%d ,",p->data);
        p=p->next;
    }
    printf("%d",p->data);
    printf(")\n");
}

main()
{
    QUEUE Q;
    Makenull(&Q);
    Enqueue(4,&Q);
    Enqueue(5,&Q);
    Enqueue(8,&Q);
    Print(&Q);
    NODE de=Dequeue(&Q);
    printf("%d\n",de.data);
    Print(&Q);

    Enqueue(11,&Q);
    Enqueue(15,&Q);
    Enqueue(3,&Q);
    Print(&Q);
    de=Dequeue(&Q);
    printf("%d\n",de.data);
    Print(&Q);

    Enqueue(2,&Q);
    Enqueue(7,&Q);
    Print(&Q);
    de=Dequeue(&Q);
    printf("%d\n",de.data);
    Print(&Q);
    de=Dequeue(&Q);
    printf("%d\n",de.data);
    Print(&Q);
    de=Dequeue(&Q);
    printf("%d\n",de.data);
    Print(&Q);

    Enqueue(23,&Q);
    Print(&Q);
    while(Q.front !=Q.rear)
    {
        de=Dequeue(&Q);
        printf("%d\n",de.data);
    }
    system("pause");
}