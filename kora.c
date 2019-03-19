#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM   5
#define total 5

typedef struct ArcBox {
     int tailvex, headvex;             //该弧的尾和头顶点的位�? 
     struct ArcBox *hlink, *tlink;    //分别为弧头相同和弧尾相同的弧的链�? 
     char info;                        //该弧相关信息的指�? 
} ArcBox;
     
typedef struct VexNode { 
    char data; 
    ArcBox *firstin, *firstout;      //分别指向该顶点�??一条入弧和出弧 
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

OLGraph Orthogonal(MTGraph *graph,OLGraph *olgraph)
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
        int count=0;
        for(j=0;j<n;j++)
        {
            if(graph->edge[i][j] !=0)        
            {
                ArcBox *p,*q;
                olgraph->xlist[i].data=i;
                
                p=malloc(sizeof(ArcBox));
                p->headvex=i;
                p->tailvex=j;
                p->hlink=NULL;
                p->tlink=NULL;

                q=olgraph->xlist[i].firstout;

                if(count==0)
                {
                    olgraph->xlist[i].firstout=p;
                    count++;
                }
                else{

                    while(q->hlink !=NULL)
                    {
                        q=q->hlink;
                    }
                    q->hlink=p;
                    count++;
                }

                q=olgraph->xlist[j].firstin;
                if(countin[j]==0)
                {
                    olgraph->xlist[j].firstin=p;
                    countin[j]++;
                }
                else{
                    while(q->tlink !=NULL)
                    {
                        q=q->tlink;
                    }
                    q->tlink=p;
                    countin[j]++;
                }
            }
        }    
    }
    return *olgraph;
}

void Print(OLGraph *olgraph)
{
    int n=olgraph->vexnum;
    int i;
    ArcBox *p;
    for(i=0;i<n;i++)
    {
        printf("Start with %d:   ",olgraph->xlist[i].data);
        for(p=olgraph->xlist[i].firstout;p !=NULL;p=p->hlink){
            printf("%d  ",p->tailvex);
        }
        printf("\n");  
    }
    printf("====================\n");

    for(i=0;i<n;i++)
    {
        printf("End with %d:   ",olgraph->xlist[i].data);
        for(p=olgraph->xlist[i].firstin;p !=NULL;p=p->tlink){
            printf("%d  ",p->headvex);
        }
        printf("\n"); 
    }
}

int in_order[total] ; 
int visited[total],count=0;
void  DFS(OLGraph *G , int v) 
{    
    ArcBox  *p ;  
    visited[v]=1 ; 
    for  (p=G->xlist[v].firstout ; p!=NULL ; p=p->tlink) 
        if  (!visited[p->headvex])  
            DFS(G , p->headvex) ; 
    in_order[count++]=v ; 
} 

void  Rev_DFS(OLGraph *G , int v) 
{    
    ArcBox  *p ; 
    visited[v]=1 ; 
    printf("%d  " , v) ;     /*  输出顶点 */ 
    for  (p=G->xlist[v].firstin ; p!=NULL ; p=p->hlink) 
    if  (!visited[p->tailvex]) 
    Rev_DFS(G , p->tailvex) ; 
} 

void  Strongly_Connected_Component(OLGraph *G) 
{     
    int  k=1, v, j ; 
    for (v=0; v<G->vexnum; v++)  
    visited[v]=0 ; 
    for (v=0; v<G->vexnum; v++)    /*  ��ͼG������� */ 
    if (!visited[v])  DFS(G, v) ;     
    for (v=0; v<G->vexnum; v++)  
    visited[v]=0 ; 
    for (j=G->vexnum-1; j>=0; j--) 
    {  /*  ��ͼG������� */ 
    v=in_order[j] ; 
    if (!visited[v]) 
    { 
        printf("��%d����ͨ��������: \n", k++) ; 
        Rev_DFS(G, v) ;
        printf("\n");
        } 
    }
} 

main()
{
    MTGraph *graph;
    graph=Readfile(graph);

    OLGraph *olgraph,result;
    result=Orthogonal(graph,olgraph);

    printf("%d",result.xlist[3].firstout->tailvex);
    // int i;
    // for(i=0;i<total;i++)
    // {
    //     printf("%d\t",olgraph->xlist[i].data);
    // }

    
    // printf("%d",olgraph->xlist[1].firstin->tailvex);   //经验证�?�确
    Strongly_Connected_Component(&result);
    system("pause");

}