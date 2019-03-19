#include<stdio.h>
#include<stdlib.h>
#define total 5

typedef struct{ 
    char vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

int vexnum;
int D[total],S[total],P[total];
void  Dijkstra(int C[total][total], int D[total] ,int P[total], int S[total])   //C是邻接矩阵，D表示源到终点的最短距离，                                              
{                                                                               //P表示最短路径上最后经过的点，S存放源和已操作过的终点
    int i,w,v,sum=0;
    for ( i=1 ; i<vexnum; i++ ) 
    {     
        D[i]=C[0][i] ;  
        S[i]=0 ;
    } 
        S [0]= 1 ;   //0已访问过
        for( i=1; i<vexnum; i++) 
        {  
            w=MinCost ( D, S ) ; 
            S[w]=1 ;       //w已访问过
            for ( v=1 ; v<=vexnum ; v++ ) 
            if ( S[v]!=1 ) {
                    sum=D[w] + C[w][v] ; 
                    if (sum < D[v] ){
                        D[v] = sum ; 
                        P[v]=w;
                    }
            } 
        } 
}//   时间复杂度：O（n2） 

int MinCost (int D[total],int S[total]) 
{ 
    int i,w;
    int temp = 100000 ; 
    w = 2 ; 
    for ( i=1 ; i<vexnum ; i++ ) 
        if (!S[i]&&(D[i]<temp))
        {  
            temp = D[i] ; 
            w = i ; 
        } 
    return  w ; 
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
    vexnum=n;
    
    int x,y,w,i=0,j=0,count=0;

    // for(i=0;i<n;i++){                                                
    //     printf("Input node's information:");
    //     sacnf("%c",&graph.vertex[i]);
    // }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph->edge[i][j]=100000;
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

int main()
{
    MTGraph *graph;
    graph = Readfile(graph); 
    vexnum=graph->n;

    Dijkstra(graph->edge,D,P,S);
    int i;
    for(i=1;i<graph->n;i++)
    {
        printf("Shortest length from 0 to %d is: %d\n",i,D[i]);
    }
    system("pause");
}

