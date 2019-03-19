#include<stdio.h>
#include<stdlib.h>
#define total 5
typedef struct{ 
    char vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

typedef struct node{
    int vertex;
    struct node *next;
}NODE;

typedef struct adj{
    NODE vexlist[total];
    int n,e;
}AdjGraph;

int visited[total];

void DFS1 (AdjGraph* graph, int i) //以vi为出发点时对邻接表表示的图G进行先深搜索
{   
    NODE *q; 
    printf("%d ",graph->vexlist[i].vertex);     //访问顶点vi;
    visited[i]=1;                      //标记vi已访问 
    // dfn[i]=count++;                        //对vi进行编号 
    q=&(graph->vexlist[i]);       //取vi边表的头指针 
    while(q->next != NULL) { //依次搜索vi的邻接点vj, 这里 
        if(visited[q->next->vertex]==0)   //若vj尚未访问 
        DFS1(graph, q->next->vertex);   //则以vj为出发点先深搜索 
        q=q->next; 
    }
} //DFS1

void DFSTraverse (AdjGraph* graph)     //主算法 /* 先深搜索一邻接表表示的图G；而以邻接矩阵表示G时，算法 完全相同 */ 
{   
    
    int i , count = 1; 
    for ( i = 0; i < graph->n; i++ ) 
        visited [i] =0;   //标志数组初始化 
    for ( i = 0; i < graph->n; i++ ) 
        if ( ! visited[i] ) DFS1 ( graph, i ); //从顶点 i 出发的一次搜索，BFSX(G, i ) 
    }

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

AdjGraph *Positive_adj(MTGraph *graph,AdjGraph *nodes)
{
    int n=graph->n;
    int i,j;
    nodes=malloc(n*sizeof(AdjGraph));
    nodes->n=n;
    for(i=0;i<n;i++)
    {
        nodes->vexlist[i].vertex=i;
        nodes->vexlist[i].next=NULL;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph->edge[i][j] !=0)
            {
                NODE *p;
                p=&(nodes->vexlist[i]);                             //�ƶ�����i��nodes�ĵ�ַ
                while(p->next !=NULL)
                {
                    p=p->next;
                }
                p->next=malloc(sizeof(AdjGraph));
                p->next->vertex=j;
                p->next->next=NULL;
            }
        }
    }
    
    return nodes;
}

main()
{
    MTGraph *graph;
    graph = Readfile(graph); 

    AdjGraph *AdjGraph;
    AdjGraph=Positive_adj(graph,AdjGraph);
    // printf("%d",AdjGraph->vexlist[1].next->next->vertex);
    
    DFSTraverse(AdjGraph);

    system("pause");

}