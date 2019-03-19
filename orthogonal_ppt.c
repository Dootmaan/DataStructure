#define MAX_VERTEX_NUM   20 
typedef struct ArcBox { 
    int  tailvex, headvex;       //该弧的尾和头顶点的位置 
    struct ArcBox * hlink, * tlink;  //分别为弧头相同和弧尾相同的弧的链域 
    char  info; //该弧相关信息的指针 
} ArcBox; 

typedef struct VexNode { 
    char  data; 
    ArcBox * firstin, * firstout;      //分别指向该顶点第一条入弧和出弧 
} VexNode; 

typedef struct {
    VexNode  xlist[MAX_VERTEX_NUM]; //表头向量 
    int vexnum, arcnum;       //有向图的当前顶点数和弧数 
} OLGraph;

void CreateDG (OLGraph  &G)   //采用十字链表存储表示，构造有向图 
{  
    scanf (&G.vexnum, &G.arcnum, &IncInfo);   //IncInfo为0则各弧不含其他信息 
    for (i = 0; i < G.vexnum; + + i) 
    { //构造表头向量 
    scanf (&G.xlist[i].data); //输入顶点值 
    G.xlist[i].firstin = NULL; 
    G.xlist[i].firstout = NULL;   //初始化指针 
    } for (k = 0; k < G.arcnum; + + k) { //输入各弧并构造十字链表 
    scanf (&v1, &v2); //输入一条弧的始点和终点 
    i = LocateVex (G, v1);  
    j = LocateVex (G, v2);  //确定v1和v2在G中位置 
    p = (ArcBox *) malloc (sizeof (ArcBox)); //假定有足够空间 
    * p = {i, j, G.xlist[j].firstin, G.xlist[i].firstout, NULL}; //对弧结点赋值{tailvex, headvex, hlink, tlink, info} 
    G.xlist[j].firstin = G.xlist[i].firstout = p; //完成在入弧和出弧链头的插入 
    if (IncInfo)   
        Input (*p－>info);       //若弧含有相关信息，则输入 
    } // for
} // CreateDG

main()
{
    
}

