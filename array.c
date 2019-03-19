#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct list{
    int data[max];
    int last;
}LIST;

void Insert(int x,int p,LIST *l)   //����x��λ��p
{
    int q;
    if((*l).last>=max-1)
    {
        printf("����");
    }
    else if (p<=0||p>(*l).last+1)
    {
        printf("�����ڵ�λ��");
    }
    else
    {
        for(q=(*l).last;q>=p;q--)
        {
            (*l).data[q+1]=(*l).data[q];
        }
        (*l).data[p]=x;
        (*l).last++;                
    }
}

int Locate(int x,LIST *l)      //��LIST�ж�λx
{
    int i;
    for(i=0;i<=(*l).last;i++)
    {
        if((*l).data[i]==x)
        {
            return i;
        }
    }
    return (*l).last+1;
}

int Retrieve(int p,LIST *l)    //����pλ�����������
{
    if(p<=0||p>(*l).last)
    printf("�����ڵ�λ��");
    else
    return((*l).data[p]);
}

void Delete(int p,LIST *l)     //ɾ��pλ�õ�����
{
    int q;
    if(p<=0||p>(*l).last)
    {
        printf("�����ڵ�λ��");
    }
    else{
        
        for(q=p+1;q<=(*l).last;q++)
        {
            (*l).data[q-1]=(*l).data[q];
        }
        (*l).last--;
    }
}

int Previous(int p,LIST *l)             //����pλ��ǰһ��Ԫ�ص�λ��
{
    if(p<=0||p>(*l).last)
    {
        printf("�����ڵ�λ��");
    }
    else if(p==1)
    {
        printf("�޶���");
    }
    else{
        return p-1;
    }
}

int Next(int p,LIST *l)           //����pλ�ú�һ��Ԫ�ص�λ��
{
    if(p<=0||p>(*l).last)
    {
        printf("�����ڵ�λ��");
    }
    else if(p==(*l).last)
    {
        printf("�޶���");
    }
    else{
        return p+1;
    }
}

void Makenull(LIST *l)      //���
{
    (*l).last=0;
    return ((*l).last+1);
}

int First(LIST *l)
{
    if((*l).last>0)
    {
        return 1;
    }
    else 
    {
        printf("��Ϊ��");
    }
}

int End(LIST *l)       //�������һ�����ݵ�λ��
{
    if((*l).last>0)
    {
        return (*l).last;
    }
    else
    printf("��Ϊ��");
}

void Print(LIST *l)         //��ӡ����˳���
{
    int i=1;
    printf("(");
    for(i=1;i<(*l).last;i++)
    {
        printf("%d ,",(*l).data[i]);
    }
    printf("%d)\n",(*l).data[i]);
}
main()
{
    LIST L;
    Makenull(&L);
    Insert(2,1,&L);
    Insert(3,2,&L);
    Insert(4,1,&L);
    Insert(5,2,&L);
    Insert(6,1,&L);
    Insert(9,6,&L);
    Print(&L);
    int first=Retrieve(1,&L);
    printf("��һ��Ԫ�أ�%d\n",first);
    Print(&L);
    int location=Locate(4,&L);
    // printf("%d\n",location);
    Delete(location,&L);
    Print(&L);
    location=Locate(3,&L);
    printf("3��λ�ã�%d\n",location);
    Print(&L);
    int next=Next(location,&L);
    int nextdata=Retrieve(next,&L);
    printf("3����һ��Ԫ�أ�%d\n",nextdata);
    Print(&L);
    int last=End(&L);
    int lastdata=Retrieve(last,&L);
    printf("���һ��Ԫ�أ�%d\n",lastdata);
    Print(&L);
    Delete(last,&L);
    Print(&L);
    Delete(1,&L);
    Print(&L);
    int second =Retrieve(2,&L);
    printf("��2��λ�ö�Ӧ��%d\n",second);
    Print(&L);
    system("pause"); 
}

