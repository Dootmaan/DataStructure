#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct list{
    int data[max];
    int last;
}LIST;

void Insert(int x,int p,LIST *l)   //插入x到位置p
{
    int q;
    if((*l).last>=max-1)
    {
        printf("表满");
    }
    else if (p<=0||p>(*l).last+1)
    {
        printf("不存在的位置");
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

int Locate(int x,LIST *l)      //在LIST中定位x
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

int Retrieve(int p,LIST *l)    //返回p位置所存的数据
{
    if(p<=0||p>(*l).last)
    printf("不存在的位置");
    else
    return((*l).data[p]);
}

void Delete(int p,LIST *l)     //删除p位置的数据
{
    int q;
    if(p<=0||p>(*l).last)
    {
        printf("不存在的位置");
    }
    else{
        
        for(q=p+1;q<=(*l).last;q++)
        {
            (*l).data[q-1]=(*l).data[q];
        }
        (*l).last--;
    }
}

int Previous(int p,LIST *l)             //返回p位置前一个元素的位置
{
    if(p<=0||p>(*l).last)
    {
        printf("不存在的位置");
    }
    else if(p==1)
    {
        printf("无定义");
    }
    else{
        return p-1;
    }
}

int Next(int p,LIST *l)           //返回p位置后一个元素的位置
{
    if(p<=0||p>(*l).last)
    {
        printf("不存在的位置");
    }
    else if(p==(*l).last)
    {
        printf("无定义");
    }
    else{
        return p+1;
    }
}

void Makenull(LIST *l)      //清空
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
        printf("表为空");
    }
}

int End(LIST *l)       //返回最后一个数据的位置
{
    if((*l).last>0)
    {
        return (*l).last;
    }
    else
    printf("表为空");
}

void Print(LIST *l)         //打印整个顺序表
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
    printf("第一个元素：%d\n",first);
    Print(&L);
    int location=Locate(4,&L);
    // printf("%d\n",location);
    Delete(location,&L);
    Print(&L);
    location=Locate(3,&L);
    printf("3的位置：%d\n",location);
    Print(&L);
    int next=Next(location,&L);
    int nextdata=Retrieve(next,&L);
    printf("3的下一个元素：%d\n",nextdata);
    Print(&L);
    int last=End(&L);
    int lastdata=Retrieve(last,&L);
    printf("最后一个元素：%d\n",lastdata);
    Print(&L);
    Delete(last,&L);
    Print(&L);
    Delete(1,&L);
    Print(&L);
    int second =Retrieve(2,&L);
    printf("第2个位置对应：%d\n",second);
    Print(&L);
    system("pause"); 
}

