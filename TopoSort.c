#include<stdio.h>
#include<stdlib.h>
#define total 5

typedef struct{ 
    int vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

typedef struct nodes{
    int vertex;
    struct nodes *next;
}NODES;

typedef struct adj{
    NODES vexlist[total];
    int n,e;
}AdjGraph;

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front;
    NODE *rear;
}QUEUE;

void Makenull(QUEUE *q)   //锟斤拷斩锟斤拷锟�???
{
    NODE *n;
    n=malloc(sizeof(NODE));
    q->front=n;
    q->front->next=NULL;
    q->rear=q->front;
}

int Empty(QUEUE *q)   //锟斤拷锟斤拷锟�?�凤拷为锟秸ｏ拷
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    return 0;
}

void Enqueue(int x,QUEUE *q)   //锟斤拷锟�???
{
    NODE *n;
    n=malloc(sizeof(NODE));
    n->data=x;
    n->next=NULL;
    (q->rear)->next=n;
    q->rear=n;
}

NODE Dequeue(QUEUE *q)    //锟斤拷锟斤拷
{
    if(q->front==q->rear)
    {
        printf("����Ϊ�� ");
    }
    else{
        NODE *t;
        t=q->front->next;
        q->front->next=t->next;
        if (t->next==NULL) 
            q->rear=q->front; 
        //NODE *t not deleted!!
        return *t;
    }
}

int Front(QUEUE *q)   //锟斤拷锟�??讹拷锟斤拷元锟斤�??
{
    if(q->front!=q->rear)
    {
        return q->front->data;
    }
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
    nodes=malloc(sizeof(AdjGraph));
    nodes->n=n;
    nodes->e=graph->e;
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
                NODES *p;
                p=&(nodes->vexlist[i]);                             //锟狡讹拷锟斤拷锟斤拷i锟斤拷nodes锟侥碉拷址
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

int indegree[total]={0};

void  Topologicalsort(AdjGraph G ) 
{   
    int v=0,nodes,n,w;
    NODES *p;
    n=G.n;
    QUEUE  Q ; 
    nodes = 0 ; 
    Makenull( &Q ) ; 
    for( v=0; v<G.n ; v++ ) 
        if ( indegree[v] ==0 )
            Enqueue( v, &Q );
    while ( !Empty( &Q ) ) 
    { 
        v = Dequeue(&Q).data; 
        
        printf("%d\t",v);   
        nodes ++ ; 
        for(p=G.vexlist[v].next; p !=NULL;p=p->next)    //临接于v的每顶点
        {
            w=p->vertex;
            if( !(--indegree[w])) 
                Enqueue(w,&Q) ;              //��Ϊ0ʱ���
        }
    } 
        if ( nodes < n )
            printf("There's a loop.\t");
}

main()
{
    MTGraph *graph;
    graph = Readfile(graph);

    AdjGraph *adjgraph;
    adjgraph=Positive_adj(graph,adjgraph);

    int i,j;
    int n =graph->n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph->edge[i][j]!=0)
            {
                indegree[j]++;
            }
        }
    }

    Topologicalsort(*adjgraph);

    system("pause");
}
