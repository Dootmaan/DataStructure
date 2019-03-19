#include <stdio.h>
#include <stdlib.h>
#define max 100
#define maxsize 100
typedef struct BTree
{
    char data;
    struct BTree *lchild, *rchild;
} BTree;

typedef struct BTreeplus{
    BTree *ptr;
    int flag;
}BTreeplus;

void Preorder(BTree *root)
{
    BTree *s[100];
    int top = -1;
    while(root != NULL || top != -1)
    {
        while(root != NULL)
        {
            printf("%c", root->data);
            s[++top] = root;
            root = root->lchild;
        }
        if(top != -1)
        {
            root = s[top--];
            root = root->rchild;
        }
    }
}

void Inorder(BTree *root)
{
    BTree *s[100];
    int top = -1;
    while(root != NULL || top != -1)
    {
        while(root != NULL)
        {
            s[++top] = root;
            root = root->lchild;
        }
        if(top != -1)
        {
            root = s[top--];
            printf("%c", root->data);
            root = root->rchild;
        }
    }
}

void Postorder(BTree *root)
{
    int top = -1;
    BTreeplus s[100];
    while (root != NULL || top != -1)
    {
        // printf("1");
        while (root != NULL)
        {
            top++;
            s[top].ptr = root;
            s[top].flag = 1;
            root = root->lchild;
        }
    
    while (top != -1 && s[top].flag == 2)
    {
        root = s[top--].ptr;
        printf("%c", root->data);
        if(root->data==s[0].ptr->data)    //到根节点时结束程序
            return;
    }
    if (top != -1)
    {
        s[top].flag = 2;
        root = s[top].ptr->rchild;
    }
    }
}

int main()
{
    BTree *tree2,*tree3,*tree4,*tree5,*tree6;
    tree2=malloc(sizeof(BTree));
    tree3=malloc(sizeof(BTree));
    tree4=malloc(sizeof(BTree));
    tree5=malloc(sizeof(BTree));
    tree6=malloc(sizeof(BTree));
    char content[maxsize];
    
    //自己写个树来遍历
    tree2->data='A';
    tree3->data='B';
    tree4->data='C';
    tree5->data='D';
    tree6->data='E';

    tree2->lchild=tree3;
    tree2->rchild=tree4;
    tree3->lchild=NULL;
    tree3->rchild=tree5;
    tree4->lchild=tree6;
    tree4->rchild=NULL;
    tree5->lchild=NULL;
    tree5->rchild=NULL;
    tree6->lchild=NULL;
    tree6->rchild=NULL;

    Preorder(tree2);
    printf("\n");

    Inorder(tree2);
    printf("\n");

    Postorder(tree2);
    printf("\n");
    system("pause");
}