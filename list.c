#include<stdio.h>
#include<stdlib.h>
//ͷ�ڵ㲻Ҫ�����ݣ���Ϊû��ָ��ָ������һ��Ҫ��Ļ�����鷳��

typedef struct node{
    int data;
    struct node *next;
}NODE;

void Insert(int x,int p,NODE *head)    //����
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
    b->next=q;     //ͷ�ڵ㲻�����ݣ���head->next��ʼ��
}

int Locate(int x,NODE *head)           //��λ
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
    //free(b);     һfree�͹ң���Ҫ�ٿ�����
}

int Previous(int p,NODE *head)
{
    if(p==1)
    {
        printf("��ǰ׺");
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
        printf("�޺�׺");
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
    printf("��һ��Ԫ�أ�%d\n",first.data);
    int location=Locate(4,&head);
    // printf("%d\n",location);
    Delete(location,&head);
    Print(&head);
    location=Locate(3,&head);
    printf("3��λ�ã�%d\n",location);
    int next=Next(location,&head);
    NODE nextdata=Retrieve(next,&head);
    printf("3����һ��Ԫ�أ�%d\n",nextdata.data);
    int last=End(&head);
    NODE lastdata=Retrieve(last,&head);
    printf("���һ��Ԫ�أ�%d\n",lastdata.data);
    Print(&head);
    Delete(last,&head);
    Print(&head);
    Delete(1,&head);
    Print(&head);
    NODE second =Retrieve(2,&head);
    printf("��2��λ�ö�Ӧ��%d\n",second.data);
    
    system("pause"); 
}