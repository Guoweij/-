
// 邻接矩阵有向图/无向图
#define MaxVertexNum 100  //顶点数目的最大值

typedef struct MGragp
{
    char Vex[MaxVertexNum];  //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int Vexnum,arcnum;//图的当前顶点数和边数/弧数
};



// 邻接矩阵法存储带权图、网
#define INFINITY //宏定义常量“无穷”  最大的Int值

typedef char VertexType;  //定点的数据类型
typedef int EdgeType;  //带权图中边上权值的数据类型
typedef struct MGraph2
{
    char Vex[MaxVertexNum];  //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int Vexnum,arcnum;//图的当前顶点数和边数/弧数
};




// 邻接表法（顺序+链式存储）
// 顶点
typedef struct VNode
{
   VertexType data;   //顶点信息
   ArcNode *first;   //第一条弧/边
}VNode,AdjList[MaxVertexNum];

// 边/弧
typedef struct ArcNode{
    int adjvex;   //边/弧指向哪个结点
    struct ArcNode *next;   //指向下一条弧的指针
    //InfoType info   //边权值
}ArcNode;

//用邻接表存储图
typedef struct ALGraph
{
    AdjList vertices;
    int Vexnum,arcnum;

}ALGraph;


