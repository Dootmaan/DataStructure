#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 5
#define total 5
typedef enum visit {unvisited, visited} VisitIf;
typedef struct EBox {
     VisitIf   mark; //访问标记 
     int  ivex, jvex; //该边依附的两个顶点的位置 
     struct EBox   * ilink, * jlink; //分别指向依附这两个顶点的下一条边 
     char *info; //该边信息指针 
}EBox; 
     
typedef struct VexBox {
     char data; 
     EBox * firstedge; //分别指向该顶点第一条入弧和出弧 
}VexBox; 

typedef struct {
     VexBox adjmulist[MAX_VERTEX_NUM]; 
     int  vexnum, edgenum; //无向图的当前顶点数和边数 
}AMLGraph;

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

AMLGraph *CreateUDG_AML(AMLGraph *amlgraph,MTGraph *graph)   //用邻接多重表存储，构造无向图G  
// {    
//     string v1,v2;   
//     int i,j,k;
//         cin>>G.vexnum>>G.arcnum;
//         for(i=0;i<G.vexnum;i++) {
//         cin>>G.adjmulist[i].data;    
//         G.adjmulist[i].firstedge=NULL;  
// }  
    // amlgraph=malloc(sizeof(AMLGraph));
    // amlgraph->vexnum=graph->n;
    // amlgraph->edgenum=graph->e;
    // int i,n,j;
    // n=graph->n;
    // for(i=0;i<n;i++)
    // {
    //     amlgraph->adjmulist[i].data=i;
    // }

    // for(i=0;i<n;i++)  {
    //         // cin>>v1>>v2;
    //         // i=Locate_Vex(G,v1);  
    //         // j=Locate_Vex(G,v2);  
    //         // while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1) 
    //         // {  
    //         //     cout<<"结点位置输入错误,重新输入: ";
    //         //     cin>>v1>>v2;  i=Locate_Vex(G,v1);      
    //         //     j=Locate_Vex(G,v2);   
    //         // }   
    //         // EBox *p=new EBox;
    //         // p->ivex=i;  p->jvex=j;  
    //         // p->ilink=G.adjmulist[i].firstedge;     
    //         // p->jlink=G.adjmulist[j].firstedge;  
    //         // p->mark=0;          
    //         // G.adjmulist[i].firstedge=G.adjmulist[j].firstedge=p;  
    //             for(j=0;j<n;j++)
    //             {
    //                 if(graph->edge[i][j] !=0)
    //                 {
    //                     EBox *p=malloc(sizeof(EBox));
    //                     p->ivex=i;p->jvex=j;
    //                     p->ilink=amlgraph->adjmulist[i].firstedge;
    //                     p->jlink=amlgraph->adjmulist[j].firstedge;
    //                     p->mark=0;  
    //                     amlgraph->adjmulist[i].firstedge=amlgraph->adjmulist[j].firstedge=p;
    //                 }
    //             }
    //         }
    //     }
//@override
{
    amlgraph=malloc(sizeof(AMLGraph));
    amlgraph->vexnum=graph->n;
    amlgraph->edgenum=graph->e;
    int i,n,j;
    n=graph->n;

    for(i=0;i<n;i++)
    {
        amlgraph->adjmulist[i].data=i;
        amlgraph->adjmulist[i].firstedge=NULL;
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(graph->edge[i][j] !=0)
            {
                EBox *p=malloc(sizeof(EBox));
                p->ivex=i;
                p->jvex=j;
                p->ilink=NULL;
                p->jlink=NULL;
                p->mark=0;

                p->ilink=amlgraph->adjmulist[i].firstedge;
                p->jlink=amlgraph->adjmulist[j].firstedge;
                amlgraph->adjmulist[i].firstedge=p;
                amlgraph->adjmulist[j].firstedge=p;

            }
        }
    }
    return amlgraph;
}

main()
{
    MTGraph *graph;
    graph=Readfile(graph);

    AMLGraph *amlgraph;
    amlgraph=CreateUDG_AML(amlgraph,graph);

    // Print(amlgraph);
    int n=graph->n;
    int i;
    EBox *p,*q;
    for(i=0;i<n;i++)
    {
        printf("Start with:%d\t  ",amlgraph->adjmulist[i].data);
        p=amlgraph->adjmulist[i].firstedge;
        while(p!=NULL)
        {
            printf("%d-->%d\t",p->ivex,p->jvex);
            q=p;
            if(q->ivex==i)
                p=p->ilink;
            else
                p=p->jlink;
        }
        printf("\n");
        // printf("%d->%d",amlgraph->adjmulist[0].firstedge->ivex,amlgraph->adjmulist[0].firstedge->jvex);
    }
    system("pause");
}