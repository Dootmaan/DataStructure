#include<stdio.h>
#include<stdlib.h>

typedef struct AVL{
    int data;
    int height;
    struct AVL *lchild,*rchild;
}AVLTree;

int Max(int i,int j)
{
    if(i>j)
        return i;
    else 
        return j;
}

int Height(AVLTree *tree)
{
    if(tree==NULL)
        return 0;
    else 
        return tree->height;
}

AVLTree *InitialTree(int data)
{
    AVLTree *p=malloc(sizeof(AVLTree));
    p->data=data;
    p->height=0;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}

AVLTree *LL(AVLTree *node)
{
    AVLTree *left=node->lchild;
    node->lchild=left->rchild;
    left->rchild=node;

    node->height=Max(Height(node->lchild),Height(node->rchild))+1;
    left->height=Max(Height(left->lchild),Height(left->rchild))+1;

    return left;
}
AVLTree *RR(AVLTree *node)
{
    AVLTree *right=node->rchild;
    node->rchild=right->lchild;
    right->lchild=node;

    node->height=Max(Height(node->rchild),Height(node->lchild))+1;
    right->height=Max(Height(right->lchild),Height(right->rchild))+1;

    return right;
}
AVLTree *LR(AVLTree *node)
{
    node->lchild=RR(node->lchild);
    return LL(node);
}
AVLTree *RL(AVLTree *node)
{
    node->rchild=LL(node->rchild);
    return RR(node);
}

AVLTree *Insert(int data,AVLTree *tree)
{
    if(tree==NULL)
    {
        tree=InitialTree(data);
    }
    else if(data<tree->data)
    {
        
        tree->lchild=Insert(data,tree->lchild);
        //Adjust the height
        if(Height(tree->lchild)-Height(tree->rchild)==2)
        {
            if(data<tree->lchild->data)
                tree=LL(tree);
            else    
                tree=LR(tree);
        }
    }
    else if(data>tree->data)
    {
        tree->rchild=Insert(data,tree->rchild);
        //Adjust the height
        if(Height(tree->rchild)-Height(tree->lchild)==2)
        {
            if(data>tree->rchild->data)
                tree=RR(tree);
            else
                tree=RL(tree);
        }
    }
    else              //data==tree->data
    {
        printf("Node already exist.Insertion failed.");
    }
    tree->height=Max(Height(tree->lchild),Height(tree->rchild))+1;
    return tree;
}

AVLTree *Search(int data,AVLTree *tree)
{
    if(tree->data==data)
    {
        return tree;
    }
    else
    {
        if(tree->lchild!=NULL)
            tree=Search(data,tree->lchild);
        if(tree->rchild!=NULL)
            tree=Search(data,tree->rchild);
    }
    return tree;
}

AVLTree *MaxNode(AVLTree *tree)
{
    AVLTree *max;
    max=tree;
    if(tree->rchild!=NULL)
        max=tree->rchild;
    return max;
}

AVLTree *DeleteNode(int data,AVLTree *tree)
{
    if(tree==NULL)
    {
        return NULL;
    }
    else if(data<tree->data)
    {
        tree->lchild=DeleteNode(data,tree->lchild);
        if(Height(tree->rchild)-Height(tree->lchild)==2)
        {
            AVLTree *r=tree->rchild;
            if(Height(r->lchild)>Height(r->rchild))
                tree=RL(tree);
            else
                tree=RR(tree);
        }
    }
    else if(data>tree->data)
    {
        tree->rchild=DeleteNode(data,tree->rchild);
        if(Height(tree->lchild)-Height(tree->rchild)==2)
        {
            AVLTree *p=tree->lchild;
            if(Height(p->rchild)>Height(p->lchild))
                tree=LR(tree);
            else
                tree=LL(tree);
        }
    }
    else            //the node needs to be deleted.
    {
        if(tree->lchild!=NULL && tree->rchild!=NULL)
        {
            if(Height(tree->lchild)>Height(tree->rchild))
            {
                AVLTree *max=MaxNode(tree->lchild);
                tree->data=max->data;
                tree->lchild=DeleteNode(max->data,tree->lchild);
            }
            else
            {
                AVLTree *min=MaxNode(tree->rchild);
                tree->data=min->data;
                tree->rchild=DeleteNode(min->data,tree->rchild);
            }
        }
        else
        {
            AVLTree *tmp=tree;
            if(tree->lchild!=NULL)
            {
                tree=tree->lchild;
            }
            else
            {
                tree=tree->rchild;
            }
            free(tmp);
        }
    }
    // tree->height=Max(Height(tree->lchild),Height(tree->rchild))+1;
    return tree;
}

AVLTree *Delete(int data,AVLTree *tree)
{
    AVLTree *p=Search(data,tree);
    if(p==NULL)
    {
        printf("No node found.Deletion failed.");
    }
    else
    {
        tree=DeleteNode(p->data,tree);
    }
    return tree;
}

main()
{
    AVLTree *avltree,*result;
    avltree=InitialTree(3);
    avltree=Insert(5,avltree);
    avltree=Insert(2,avltree);
    avltree=Delete(3,avltree);
    avltree=Insert(20,avltree);

    result=Search(2,avltree);

    avltree=Insert(10,avltree);
    avltree=Delete(5,avltree);
    
    printf("%d\n%d\n",avltree->lchild->data,result->data);

    system("pause");
}