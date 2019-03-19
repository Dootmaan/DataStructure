#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM   5
#define total 5

typedef struct ArcBox {
     int tailvex, headvex;             //该弧的尾和头顶点的位置 
     struct ArcBox *hlink, *tlink;    //分别为弧头相同和弧尾相同的弧的链域 
     char info;                        //该弧相关信息的指针 
} ArcBox;
     
typedef struct VexNode { 
    char data; 
    ArcBox *firstin, *firstout;      //分别指向该顶点第一条入弧和出弧 
}VexNode;

typedef struct { 
    VexNode xlist[MAX_VERTEX_NUM];     //表头向量
    int vexnum,arcnum;                 //有向图的当前顶点数和弧数 
} OLGraph;

typedef struct{ 
    char vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

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

OLGraph *Orthogonal(MTGraph *graph,OLGraph *olgraph)
{
    int n=graph->n;
    olgraph=malloc(sizeof(OLGraph));
    olgraph->vexnum=n;
    olgraph->arcnum=graph->e;

    int i,j,k,x,y;
    for(i=0;i<n;i++)
    {
        olgraph->xlist[i].data=i;
        olgraph->xlist[i].firstin=NULL;
        olgraph->xlist[i].firstout=NULL;
    }

    int countin[total]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int countout=0; 
            if(graph->edge[i][j] !=0)        
            {
                ArcBox *p,*q,*r;
                p=malloc(sizeof(ArcBox));
                p->info=graph->vertex[i];
                p->headvex=i;
                p->tailvex=j;
                p->hlink=NULL;
                p->tlink=NULL;

                for(q=olgraph->xlist[i].firstout;q !=NULL; q=q->hlink)
                {
                    ;
                }
                q->hlink=p;

                for(q=olgraph->xlist[i].firstin;q !=NULL; q=q->tlink)
                {
                    ;
                }
                q->tlink=p;

                }
            }    
        }
        return olgraph;
    }
    

void Print(OLGraph *olgraph)
{
    int n=olgraph->vexnum;
    int i;
    ArcBox *p;
    for(i=0;i<n;i++)
    {
        p=olgraph->xlist[i].firstout;
        while(p->hlink != NULL)
        {
            printf("%d %d \n",p->headvex,p->tailvex);
            p=p->hlink;
        }
        printf("%d %d \n",p->headvex,p->tailvex);
    }
}

main()
{
    MTGraph *graph;
    graph=Readfile(graph);

    OLGraph *olgraph;
    olgraph=Orthogonal(graph,olgraph);

    // int i;
    // for(i=0;i<total;i++)
    // {
    //     printf("%d\t",olgraph->xlist[i].data);
    // }

    // Print(olgraph);
    printf("%d",olgraph->vexnum);

    Print(olgraph);
    
    system("pause");

}