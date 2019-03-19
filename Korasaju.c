#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 5
#define total 5
#define MAX_VEX 5

typedef struct ArcBox
{
    int tailvex, headvex;         //该弧的尾和头顶点的位�??
    struct ArcBox *hlink, *tlink; //分别为弧头相同和弧尾相同的弧的链�??
    char info;                    //该弧相关信息的指�??
} ArcBox;

typedef struct VexNode
{
    char data;
    ArcBox *firstin, *firstout; //分别指向该顶点�??一条入弧和出弧
} VexNode;

typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM]; //表头向量
    int vexnum, arcnum;            //有向图的当前顶点数和弧数
} OLGraph;

typedef struct
{
    char vertex[total];
    int edge[total][total];
    int n, e;
} MTGraph;

void Readfile(MTGraph *graph)
{
    FILE *fp;
    fp = fopen("D:\\korasaju.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open the file!");
    }

    int b, n;
    fscanf(fp, "%d %d", &b, &n);

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

void Orthogonal(MTGraph *graph, OLGraph *olgraph)
{
    int n = graph->n;
    olgraph->vexnum = n;
    olgraph->arcnum = graph->e;
    ArcBox *p, *q;
    int i, j;
    for (i = 0; i < n; i++)
    {
        // olgraph->xlist[i].data = i;
        olgraph->xlist[i].firstin = NULL;
        olgraph->xlist[i].firstout = NULL;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph->edge[i][j] != 0)
            {
                p = malloc(sizeof(ArcBox));
                p->headvex = i;
                p->tailvex = j;
                p->hlink = NULL;
                p->tlink = NULL;

                // if(olgraph->xlist[i].firstin==NULL)
                // {
                //     olgraph->xlist[i].firstin=p;
                // }
                // else
                //     {
                //         q=olgraph->xlist[i].firstin;
                //         while(q->hlink !=NULL)
                //         {
                //             q=q->hlink;
                //         }
                //         q->hlink=p;
                //     }

                // if(olgraph->xlist[j].firstout==NULL)
                // {
                //     olgraph->xlist[j].firstout=p;
                // }
                // else{
                //     q=olgraph->xlist[j].firstout;
                //     while(q->tlink !=NULL)
                //     {
                //         q=q->tlink;
                //     }
                //     q->tlink=p;
                // }
                if (olgraph->xlist[i].firstin==NULL)
                {
                    olgraph->xlist[i].firstin = p;
                }
                else
                {
                    q = olgraph->xlist[i].firstin;
                    while (q->hlink != NULL)
                    {
                        q = q->hlink;
                    }
                    q->hlink = p;
                }
                if (olgraph->xlist[j].firstout==NULL)
                {
                    olgraph->xlist[j].firstout = p;
                }
                else
                {
                    q = olgraph->xlist[j].firstout;
                    while (q->tlink != NULL)
                    {
                        q = q->tlink;
                    }
                    q->tlink = p;
                }
                }
            }
        }
    }


// void Orthogonal(MTGraph* graph,OLGraph *olgraph)
// {
//     int i,j;
//     ArcBox *h;
//     ArcBox *p;
//     olgraph->arcnum=graph->e;
//     olgraph->vexnum=graph->n;
//     for(i=0;i<graph->n;i++)
//     {
//         olgraph->xlist[i].firstin=NULL;
//         olgraph->xlist[i].firstout=NULL;
//     }
//     for(i=0;i<graph->n;i++)
//     {
//         for(j=0;j<graph->n;j++)
//         {
//             if(graph->edge[i][j]!=0)
//             {
//                 h=malloc(sizeof(ArcBox));
//                 h->headvex=i;
//                 h->tailvex=j;
//                 h->hlink=NULL;
//                 h->tlink=NULL;
                
//                 if(olgraph->xlist[i].firstin==NULL)
//                 {
//                     olgraph->xlist[i].firstin=h;
//                 }
//                 else
//                 {
//                     p=olgraph->xlist[i].firstin;
//                     while(p->hlink!=NULL)
//                     {
//                         p=p->hlink;
//                     }
//                     p->hlink=h;
//                 }
//                 if(olgraph->xlist[j].firstout==NULL)
//                 {
//                     olgraph->xlist[j].firstout=h;
//                 }
//                 else
//                 {
//                     p=olgraph->xlist[j].firstout;
//                     while(p->tlink!=NULL)
//                     {
//                         p=p->tlink;
//                     }
//                     p->tlink=h;
//                 }

//             }
//         }
//     }
// }
int in_order[MAX_VEX];

int visited[total] = {0}, count = 0;

void DFS(OLGraph *G, int v)
{
    ArcBox *p;
    visited[v] = 1;
    for (p = G->xlist[v].firstout; p != NULL; p = p->tlink)
        if (!visited[p->headvex])
            DFS(G, p->headvex);
    in_order[count++] = v;
}

void Rev_DFS(OLGraph *G, int v)
{
    ArcBox *p;
    visited[v] = 1;
    printf("%d ", v); /*  输出顶点 */
    for (p = G->xlist[v].firstin; p != NULL; p = p->hlink)
        if (!visited[p->tailvex])
            Rev_DFS(G, p->tailvex);
}

void Strongly_Connected_Component(OLGraph *G)
{
    int k = 1, v, j;
    for (v = 0; v < G->vexnum; v++)
        visited[v] = 0;
    for (v = 0; v < G->vexnum; v++) /*  对图G正向遍历 */
        if (!visited[v])
            DFS(G, v);
    for (v = 0; v < G->vexnum; v++)
        visited[v] = 0;
    for (j = G->vexnum - 1; j >= 0; j--)
    { /*  对图G逆向遍历 */
        v = in_order[j];
        if (!visited[v])
        {
            printf("\nNo.%d strong-connection's nodes:", k++);
            Rev_DFS(G, v);
        }
    }
}

main()
{
    MTGraph graph;
    Readfile(&graph);

    OLGraph olgraph;
    Orthogonal(&graph, &olgraph);

    // printf("%d",olgraph->xlist[0].firstout->tailvex);
    // printf("%d",visited[0]);
    Strongly_Connected_Component(&olgraph);

    system("pause");
}