#include <stdio.h>
#include <stdlib.h>
#define MaxS 50

typedef struct
{
    int vex[MaxS];
    int edge[MaxS][MaxS];
    int n,e;/*n:������    e:����*/
}Graph;/*�ڽӾ���*/

typedef struct  afn
{
    int headvex;
    int tailvex;
    struct afn *hlink,*tlink;
    int quan;
}ArcBox;/*ʮ������  �������һ�����*/
typedef struct
{
    int quan;
    struct  afn *firstIn,*firstOut;
}VexNode;/*ʮ������  ����*/
typedef struct
{
    VexNode a[MaxS];
    int n,e;
}OLGraph;/*ʮ������*/

void Readfile(Graph *graph)
{
    FILE *fp;
    fp = fopen("D:\\korasaju.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open the file!");
    }

    int b, n;
    fscanf(fp, "%d %d", &b, &n);

    graph = malloc(sizeof(Graph));
    graph->n = n;

    int x, y, w, i = 0, j = 0, count = 0;

    // for(i=0;i<n;i++){
    //     printf("Input node's information:");
    //     sacnf("%c",&graph.vertex[i]);
    // }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph->edge[i][j] = 0;
        }
    }
    if (b == 1)
    {
        while (fscanf(fp, "%d %d %d\n", &x, &y, &w) == 3)
        {
            graph->edge[x][y] = w;
            count++;
        }
    }
    else
    {
        while (fscanf(fp, "%d %d %d\n", &x, &y, &w) == 3)
        {
            graph->edge[x][y] = w;
            graph->edge[y][x] = w;
            count++;
        }
    }
    graph->e = count;
}

void LtoS(Graph* graph,OLGraph *olgraph)
{
    int i,j;
    ArcBox *h;
    ArcBox *beforeh;
    olgraph->e=graph->e;
    olgraph->n=graph->n;
    for(i=0;i<graph->n;i++)
    {
        olgraph->a[i].firstIn=NULL;
        olgraph->a[i].firstOut=NULL;
    }
    for(i=0;i<graph->n;i++)
    {
        for(j=0;j<graph->n;j++)
        {
            if(graph->edge[i][j]!=0)
            {
                h=malloc(sizeof(ArcBox));
                h->headvex=i;
                h->tailvex=j;
                h->hlink=NULL;
                h->tlink=NULL;
                h->quan=graph->edge[i][j];
                if(olgraph->a[i].firstIn==NULL)
                {
                    olgraph->a[i].firstIn=h;
                }
                else
                {
                    beforeh=olgraph->a[i].firstIn;
                    while(beforeh->hlink!=NULL)
                    {
                        beforeh=beforeh->hlink;
                    }
                    beforeh->hlink=h;
                }
                if(olgraph->a[j].firstOut==NULL)
                {
                    olgraph->a[j].firstOut=h;
                }
                else
                {
                    beforeh=olgraph->a[j].firstOut;
                    while(beforeh->tlink!=NULL)
                    {
                        beforeh=beforeh->tlink;
                    }
                    beforeh->tlink=h;
                }

            }
        }
    }
}


int in_order[MaxS] ;
int visited[MaxS];
int count=0;
void DFS(OLGraph *m,int v)
{
    ArcBox  *p ;
    visited[v]=1 ;

    for  (p=m->a[v].firstOut ; p!=NULL ; p=p->tlink)
    {
        if  (visited[p->headvex]==0)
        {
            DFS(m , p->headvex) ;
        }
    }
    in_order[count++]=v ;

}
void  Rev_DFS(OLGraph *m , int v)
 {

    ArcBox  *p ;
    visited[v]= 1 ;
    printf("%d  " , v) ;
    for(p=m->a[v].firstIn ; p!=NULL ; p=p->hlink)
        if  (visited[p->tailvex]==0)
             Rev_DFS(m , p->tailvex) ;
}

void  Strongly_Connected_Component(OLGraph *m)
{
    int  k=1, v, j ;
    for (v=0; v<m->n; v++)
        visited[v]=0 ;
    for (v=0; v<m->n; v++)
        if (visited[v]==0)
            DFS(m, v) ;
    for (v=0; v<m->n; v++)
        visited[v]=0 ;
    for (j=m->n-1; j>=0; j--)
        {
            v=in_order[j] ;
            if (visited[v]==0)
            {
                printf("\n��%d����ͨ��������: ", k++) ;
                Rev_DFS(m, v);
            }
        }
}

int main()
{

    Graph q1;
    OLGraph q3;
    Readfile(&q1);
    LtoS(&q1,&q3);
    Strongly_Connected_Component(&q3);
    
    system("pause");
}
