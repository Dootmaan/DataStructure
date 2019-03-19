#include<stdio.h>
#include<stdlib.h>
#define total 5

typedef struct{ 
    int vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

// typedef struct nodes{
//     int vertex;
//     struct nodes *next;
// }NODES;

// typedef struct adj{
//     NODES vexlist[total];
//     int n,e;
// }AdjGraph;

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front;
    NODE *rear;
}QUEUE;

void Makenull(QUEUE *q)   //��ն���??
{
    NODE *n;
    n=malloc(sizeof(NODE));
    q->front=n;
    q->front->next=NULL;
    q->rear=q->front;
}

int Empty(QUEUE *q)   //�����Ƿ�Ϊ�գ�
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    return 0;
}

void Enqueue(int x,QUEUE *q)   //���??
{
    NODE *n;
    n=malloc(sizeof(NODE));
    n->data=x;
    n->next=NULL;
    (q->rear)->next=n;
    q->rear=n;
}

NODE Dequeue(QUEUE *q)    //����
{
    if(q->front==q->rear)
    {
        printf("û�п�ɾ����");
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

int Front(QUEUE *q)   //���ض���Ԫ��
{
    if(q->front!=q->rear)
    {
        return q->front->data;
    }
}

int visited[total];

void BFS2(MTGraph *graph, int k) 
{     
    int i , j; QUEUE Q;  
    Makenull(&Q); 
    printf("%d ",graph->vertex[k]);   //访问vk 
    visited[k] = 1; 
    Enqueue (k, &Q);   // vk进队
    while ( ! Empty (&Q) ) {
    NODE p=Dequeue(&Q); //vi出队 
    i=p.data;
    for(j=0; j<graph->n; j++) {
            if ( graph->edge[ i ][ j ] !=0 && !visited[ j ]) { 
            printf("%d ",graph->vertex[j]);//访问vj 
            visited[ j ]=1;  
            Enqueue ( j , &Q ); //访问过的vj入队 
            } 
        }                          
    }                          
} 

void BFSTraverse (MTGraph* graph)     //���㷨 /* ��������һ�ڽӱ��ʾ��ͼG�������ڽӾ����ʾGʱ���㷨 ��ȫ��ͬ */ 
{   
    int i , count = 1; 
    for ( i = 0; i < graph->n; i++ ) 
        visited [i] =0;  
    for ( i = 0; i < graph->n; i++ ) 
        if ( ! visited[i] ) 
            BFS2 ( graph, i ); 
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

main()
{
    MTGraph *graph;
    graph = Readfile(graph);
    int i;
    
    for(i=0;i<graph->n;i++)
    {
        graph->vertex[i]=i;
    }
    
    BFSTraverse(graph);

    system("pause");

}