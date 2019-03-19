#include<stdio.h>
#include<stdlib.h>
#define max 30
#define maxsize 100       //不管了，先搞个二叉树再说(搞出来的东西很不对劲，无所谓了，是个树就好)

typedef struct BTree{
    char data;
    struct BTree *lchild,*rchild;
}BTree;           

// typedef struct CTNode{
//     char data;
//     struct CTNode *next;
// }CTNode;

// typedef struct CTBox{
//     char data;
//     CTNode *firstchild;
// }CTBox;

// typedef struct CTree{
//     CTBox nodes[max];
//     int n,r;
// }CTree;

int Readfile(char *content)
{
    FILE *fp;
    fp=fopen("D:\\Tree.txt","r");
    if(fp==NULL)
    {
        printf("Failed to open the file!");
        return 0;
    }

    int count=0;
    content[count]=fgetc(fp);
    while(content[count]!= EOF)
    {
        count++;
        content[count]=fgetc(fp);  
    }
}

// CTree *Analyze(char *content)
// {
//     int count=0;
//     CTree *tree=malloc(5*sizeof(CTree));    
//     int treecount=-1;  
//     int boxcount=0;   
//     while(content[count]!=EOF)
//     {
//         if(content[count]=='#')
//         {
//             treecount++;
//             boxcount=0;
//         }
//         if(content[count]>=65&&content[count]<=90)
//         {
//             tree[treecount].nodes[boxcount].data=content[count];
//             tree[treecount].nodes[boxcount].firstchild=NULL;
//             if(content[count-1]=='{')
//             {
//                 int c=count+2;
//                 for(c=count+2;content[c]!='}';c++)
//                 {
//                     if(content[c]>=65 && content[c]<=90){
//                     CTNode *q=malloc(sizeof(CTNode));
//                     q->data=content[c];
//                     q->next=NULL;
//                         if(tree[treecount].nodes[boxcount].firstchild==NULL)
//                         tree[treecount].nodes[boxcount].firstchild=q;
//                         else
//                         {
//                             CTNode *p=tree[treecount].nodes[boxcount].firstchild;
//                             while(p->next != NULL)
//                             {
//                                 p=p->next;  
//                             }
//                             p->next=q;
//                             q->next=NULL;
//                         }
//                     }
//                 }
//             }
//             boxcount++;
//         }
//         count++;
//     }
//     return tree;
// }

void Forest2tree(int n,BTree *tree2,char *data)    //对输入的另一种解读
{
    char c=data[n];
    if(c=='#')
    {
        tree2=NULL;
    }
    else if(c==EOF)
    {
        return;
    }
    else
    {
        tree2=malloc(sizeof(BTree));
        tree2->data=c;
        
        Forest2tree(n+1,tree2->lchild,data);
        Forest2tree(n+1,tree2->rchild,data);
    }
}

int main()
{
    char content[maxsize];
    int result=Readfile(content);
    if(result==0) return 0;
    // CTree *tree=Analyze(content);
    BTree *tree2;
    int count=1,c=0;
    char data[max];

    while(content[count]!=EOF)
    {
        if(content[count]>=65 && content[count]<=90 ||content[count]=='#')
        {
            data[c]=content[count];
            c++;
        }
        count++;
    }
    data[c]=EOF;

    // c=0;              //data数组正常
    // while(data[c] !=EOF)
    // {
    //     printf("%c",data[c]);
    //     c++;
    // }
    // printf("   %d\n",c);

    // c=0;
    // while(data[c]!=EOF)
    // {
    //     printf("%c",data[c]);
    //     c++;
    // }
    
    Forest2tree(0,tree2,data);

    // printf("%c",tree[1].nodes[0].data);
    
    system("pause");
}