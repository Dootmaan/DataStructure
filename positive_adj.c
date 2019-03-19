#include<stdio.h>
#include<stdlib.h>
#define total 5

typedef struct{ 
    char vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

typedef struct node{
    int node;
    struct node *next;
}NODE;

MTGraph *Readfile(MTGraph *graph)
{
    FILE *fp;
    fp=fopen("D:\\Graph.txt","r");
    if(fp==NULL)
    {
        printf("Failed to open the file!");
        return 0;
    }
    
    int b,n;
    fscanf(fp,"%d %d",&b,&n);

    graph=malloc(sizeof(MTGraph));

    graph->n=n;
    
    int x,y,w,i=0,j=0,count=0;

    // for(i=0;i<n;i++){                                                
    //     printf("Input node's information:");
    //     sacnf("%c",&graph.vertex[i]);
    // }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph->edge[i][j]=0;
        }
    }
    if(b==1)
    {
        while(fscanf(fp,"%d %d %d\n",&x,&y,&w)==3)
        {
            graph->edge[x][y]=w;
            count++;
        }
    }
    else{
        while(fscanf(fp,"%d %d %d\n",&x,&y,&w)==3)
        {
            graph->edge[x][y]=w;
            graph->edge[y][x]=w;
            count++;
        }
    }
    graph->e=count;
    return graph;
}

NODE *Positive_adj(MTGraph *graph,NODE *nodes)
{
    int n=graph->n;
    int i,j;
    nodes=malloc(n*sizeof(NODE));
    for(i=0;i<n;i++)
    {
        nodes[i].node=i;
        nodes[i].next=NULL;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph->edge[i][j] !=0)
            {
                NODE *p;
                p=&nodes[i];                             //�ƶ�����i��nodes�ĵ�ַ
                while(p->next !=NULL)
                {
                    p=p->next;
                }
                p->next=malloc(sizeof(NODE));
                p->next->node=j;
                p->next->next=NULL;
            }
        }
    }

    return nodes;
}

void Print(NODE *nodes,int n)          //�˴�NODE���ڽӱ�ṹ��
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Start with:%d\t",nodes[i].node);
        NODE *p;
        printf("------>");
        for(p=nodes[i].next;p !=NULL;p=p->next)
        {
            printf("%d  ",p->node);
        }
        printf("\n");
    }
}

int main()
{
    MTGraph *graph;
    graph = Readfile(graph); 

    NODE *nodes;
    nodes=Positive_adj(graph,nodes);

    // printf("%d",nodes[1].next->next->node);       
    Print(nodes,graph->n);
    system("pause");
}