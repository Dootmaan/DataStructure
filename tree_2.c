#include<stdio.h>
#include<stdlib.h>
#define max 30
#define maxsize 100                

typedef struct CTNode{
    char data;
    struct CTNode *next;
}CTNode;

typedef struct CTBox{
    char data;
    CTNode *firstchild;
}CTBox;

typedef struct CTree{
    CTBox nodes[max];
    int n,r;
}CTree;

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

CTree *Analyze(char *content)
{
    int count=0;
    CTree *tree=malloc(5*sizeof(CTree));    
    int treecount=-1;  
    int boxcount=0;   
    while(content[count]!=EOF)
    {
        if(content[count]=='#')
        {
            treecount++;
            boxcount=0;
        }
        if(content[count]>=65&&content[count]<=90)
        {
            tree[treecount].nodes[boxcount].data=content[count];
            tree[treecount].nodes[boxcount].firstchild=NULL;
            if(content[count-1]=='{')
            {
                int c=count+2;
                for(c=count+2;content[c]!='}';c++)
                {
                    if(content[c]>=65 && content[c]<=90){
                    CTNode *q=malloc(sizeof(CTNode));
                    q->data=content[c];
                    q->next=NULL;
                        if(tree[treecount].nodes[boxcount].firstchild==NULL)
                        tree[treecount].nodes[boxcount].firstchild=q;
                        else
                        {
                            CTNode *p=tree[treecount].nodes[boxcount].firstchild;
                            while(p->next != NULL)
                            {
                                p=p->next;  
                            }
                            p->next=q;
                            q->next=NULL;
                        }
                    }
                }
            }
            boxcount++;
        }
        count++;
    }
    return tree;
}

int main()
{
    char content[maxsize];
    int result=Readfile(content);
    if(result==0) return 0;
    CTree *tree=Analyze(content);
    printf("%c",tree[1].nodes[0].data);
    

    system("pause");
}