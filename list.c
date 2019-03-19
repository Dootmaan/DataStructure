#include<stdio.h>
#include<stdlib.h>
//头节点不要存数据，因为没有指针指向它，一定要存的话会很麻烦的

typedef struct node{
    int data;
    struct node *next;
}NODE;

void Insert(int x,int p,NODE *head)    //插入
{
    int i=1;
    NODE *q;
    NODE *b=head;
    q=malloc(sizeof(NODE));           
    q->data=x;
    for(i=1;i<p;i++)
    {
        b=b->next;
    }
    if((*b).next==NULL)
    {
        q->next=NULL;
    }
    else{
        q->next=b->next;
    }
    b->next=q;     //头节点不存数据，从head->next开始存
}

int Locate(int x,NODE *head)           //定位
{
    int i=1;
    NODE *b=head->next;
    while((*b).next !=NULL)
    {
        if((*b).data==x)
        {
            return i;
        }
        i++;
        b=(*b).next;
    }
}

NODE Retrieve(int p,NODE *head)        
{
    int i;
    NODE *b=head->next;
    for(i=1;i<p;i++)
    {
        b=b->next;
    }
    return (*b);
}

void Delete(int p,NODE *head)
{
    int i;
    NODE *b=head;
    for(i=1;i<p;i++)
    {
        b=(*b).next;
    }
    (*b).next=(*((*b).next)).next;
    //free(b);     一free就挂，需要再看看；
}

int Previous(int p,NODE *head)
{
    if(p==1)
    {
        printf("无前缀");
    }
    else{
        return p-1;
    }
}

int Next(int p,NODE *head)
{
    int i;
    NODE *b=head->next;
    for(i=1;i<p;i++)
    {
        b=(*b).next;
    }
    if((*b).next==NULL)
    {
        printf("无后缀");
    }
    else 
    {
        return p+1;
    }
}

void Makenull(NODE *head)
{
    (*head).next=NULL;
}

int First(NODE *head)
{
    return 1;
}

int End(NODE *head)
{
    NODE *b=head->next;
    int i=1;
    while((*b).next != NULL)
    {
        i++;
        b=b->next;
    }
    return i;
}

void Print(NODE *head)
{
    NODE *b=head->next;
    printf("(");
    while((*b).next !=NULL)
    {
        printf("%d ,",b->data);
        b=b->next;
    }
    printf("%d",b->data);
    printf(")\n");
}

main()
{
    NODE head;
    Makenull(&head);
    Insert(2,1,&head);
    Insert(3,2,&head);
    Insert(4,1,&head);
    Insert(5,2,&head);
    Insert(6,1,&head);
    Insert(9,6,&head);
    Print(&head);
    NODE first=Retrieve(1,&head);
    printf("第一个元素：%d\n",first.data);
    int location=Locate(4,&head);
    // printf("%d\n",location);
    Delete(location,&head);
    Print(&head);
    location=Locate(3,&head);
    printf("3的位置：%d\n",location);
    int next=Next(location,&head);
    NODE nextdata=Retrieve(next,&head);
    printf("3的下一个元素：%d\n",nextdata.data);
    int last=End(&head);
    NODE lastdata=Retrieve(last,&head);
    printf("最后一个元素：%d\n",lastdata.data);
    Print(&head);
    Delete(last,&head);
    Print(&head);
    Delete(1,&head);
    Print(&head);
    NODE second =Retrieve(2,&head);
    printf("第2个位置对应：%d\n",second.data);
    
    system("pause"); 
}