#include<stdio.h>
#include<stdlib.h>
#define total 5

typedef struct{ 
    char vertex [total];  
    int edge[total][total]; 
    int n, e;  
}MTGraph;

MTGraph *Readfile(MTGraph *graph)
{
    FILE *fp;
    fp=fopen("D:\\mintree.txt","r");
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

void  Prim(int  C[total][total])
// { 
//     int n=total;
//     int  LOWCOST[total+1];
//     int  CLOSSET[total+1];
//     int i,j,k;
//     int  min;
//     for( i=2; i<=n; i++ ) 
//     {
//         LOWCOST[i] = C[1][i];
//         CLOSSET[i] = 1;
//     }
//     for(  i = 2;  i <= n; i++ )
//     {
//         min = LOWCOST[i]; 
//         k = i; 
//         for(  j = 2;   j <= n;  j++ ) 
//         if ( LOWCOST[j] < min ) {
//               min = LOWCOST[j] ;
//               k=j;  
//             } 
//             printf("%d, %d \n",k,CLOSSET[k]);
//             LOWCOST[k] = 100000 ;
//             for ( j = 2;  j <= n;  j++ ) 
//             if  ( C[k][j] <  LOWCOST[j] && LOWCOST[j] < 100000 ) 
//             {      
//                 LOWCOST[j]=C[k][j];   
//                 CLOSSET[j]=k;     
//             } 
//         } 
//     } // ʱ�临�Ӷȣ�O( |V|2 )
{
    int n=total;
    int  LOWCOST[total];
    int  CLOSSET[total];
    int i,j,k;
    int  min;
    for( i=1; i<n; i++ ) 
    {
        LOWCOST[i] = C[0][i];
        CLOSSET[i] = 1;
    }
    for(  i = 1;  i < n; i++ )
    {
        min = LOWCOST[i]; 
        k = i; 
        
        for(  j = 1;   j < n;  j++ ) 
        if ( LOWCOST[j] < min ) {
              min = LOWCOST[j] ;
              k=j;  
            } 
            printf("%d, %d \n",k,CLOSSET[k]);
            LOWCOST[k] = 100000 ;
            for ( j = 1;  j < n;  j++ ) 
            if  ( (C[k][j] <  LOWCOST[j]) && (LOWCOST[j] < 100000) ) 
            {      
                LOWCOST[j]=C[k][j];   
                CLOSSET[j]=k;     
            } 
        } 
    } // ʱ�临�Ӷȣ�O( |V|2 )

    
int main()
{
    MTGraph *graph;
    graph = Readfile(graph); 

    Prim(graph->edge);
    
    system("pause");
}