#include <stdio.h>
#include <stdlib.h>
#define max 30
#define maxsize 100
typedef struct BTree
{
    char data;
    struct BTree *lchild, *rchild;
    int start,end;
} BTree;

BTree *Preorder(BTree *root)
{
    int precount=1;
    BTree *s[max];
    int top = -1;
    while(root != NULL || top != -1)
    {
        while(root != NULL)
        {
            // printf("%c", root->data);
            root->start=precount;
            precount++;
            s[++top] = root;
            root = root->lchild;
        }
        
        if(top != -1)
        {
            root = s[top--];
            root = root->rchild;
            precount++;
        }
    }
}

BTree *Inorder(BTree *root)
{
    int incount=1;
    BTree *s[max];
    int top = -1;
    while(root != NULL || top != -1)
    {
        while(root != NULL)
        {
            s[++top] = root;
            root = root->lchild;
            incount++;                      //关键
        }

        if(top != -1)
        {
            root = s[top--];
            // printf("%c", root->data);
            root->end=incount;
            incount++;
            root = root->rchild;
        }
    }
}

void Print(BTree *root)
{
    BTree *s[max];
    int top = -1;
    while(root != NULL || top != -1)
    {
        while(root != NULL)
        {
            printf("%c:(%d,%d)  ",root->data,root->start,root->end);
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

    int incount=1;
    int precount=1;

    Preorder(tree2);
    Inorder(tree2);
    Print(tree2);

    
    system("pause");
}