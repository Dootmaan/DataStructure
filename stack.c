#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct stack{
    int data[max];
    int top;
}STACK;

void Makenull(STACK *s)    //清空
{
    s->top=-1;
}

int Empty(STACK *s)    //看栈是否为空
{
    if(s->top<0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int Top(STACK *s)    //返回栈顶元素
{
    return s->data[s->top];
}

void Pop(STACK *s)        //弹栈
{
    if(s->top<0)
    {
        printf("无元素");
    }
    else
    {
        s->top--;
    }
}

void Push(int p,STACK *s)         //把p压栈
{
    (s->top)++;
    s->data[s->top]=p;
}



main()
{
    STACK s;
    Makenull(&s);
    Push(4,&s);
    Push(5,&s);
    Push(8,&s);
    int top =Top(&s);
    printf("%d\n",top);
    Pop(&s);
    
    Push(11,&s);
    Push(15,&s);
    Push(3,&s);
    int top2 =Top(&s);
    printf("%d\n",top2);
    Pop(&s);

    Push(2,&s);
    Push(7,&s);
    int top3 =Top(&s);
    printf("%d\n",top3);
    Pop(&s);
    int top4 =Top(&s);
    printf("%d\n",top4);
    Pop(&s);
    int top5 =Top(&s);
    printf("%d\n",top5);
    Pop(&s);
    int top6 =Top(&s);
    printf("%d\n",top6);
    Pop(&s);

    Push(23,&s);
    while(!Empty(&s)){
        int pop =Top(&s);
        printf("%d\n",pop);
        Pop(&s);
    }

    system("pause");
}