#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

void Insert(int x,int p,NODE *head)
{
    NODE *a=head;
    NODE *m;
    NODE *b;
    int i;
    if(p==1)
    {
        if(a->next==NULL)
        {
            a->data=x;
        }
        else
        {
                  m=malloc(sizeof(NODE));
        m->data=a->data;
        a->data=x;
        b=a->next;
        a->next=m;
        m->next=b;  
        }

        
    }
    else
    {
        m=malloc(sizeof(NODE));
         m->data=x;
        for(i=1;i<=p-2;i++)
        {
            a=a->next;
        }
             b=a->next;
        a->next=m;
         m->next=b;
    }
    
}

int Locate(int x,NODE *head)
{
    int i=1;
    NODE *b=head;
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
    NODE *b=head;
    for(i=0;i<p;i++)
    {
        b=(*b).next;
    }
    return (*b);
}

void Delete(int p,NODE *head)
{
    int i;
    NODE *b=head;
    for(i=0;i<p;i++)
    {
        b=(*b).next;
    }
    (*b).next=(*((*b).next)).next;
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
    NODE *b=head;
    for(i=0;i<p;i++)
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
    head->next=NULL;
}

int First(NODE *head)
{
    return 1;
}

int End(NODE *head)
{
    NODE *b=head;
    int i=0;
    while((*b).next != NULL)
    {
        i++;
    }
    return i;
}

void Print(NODE *head)
{
    NODE *b=head;
    printf("(");
    while(b->next !=NULL)
    {
        printf("%d ,",b->data);
        b=b->next;
    }
    printf("%d",b->data);
    printf(")");
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
    Print(&head);
    int location=Locate(4,&head);
    // printf("%d\n",location);
    Delete(location,&head);
    Print(&head);
    location=Locate(3,&head);
    printf("3的位置：%d\n",location);
    Print(&head);
    int next=Next(location,&head);
    NODE nextdata=Retrieve(next,&head);
    printf("3的下一个元素：%d\n",nextdata.data);
    Print(&head);
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
    Print(&head);
    system("pause"); 
}