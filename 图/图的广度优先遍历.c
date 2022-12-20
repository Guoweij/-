
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 10

typedef int VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vertices[MAX_VERTEX_NUM];  // 存储图中所有点的信息
    EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 存储图中所有边的信息
    int vertexNum, edgeNum;  // 图中点的数量和边的数量
} Graph;

typedef struct {
    int data[MAX_VERTEX_NUM];  // 存储队列中的元素
    int front, rear;  // 队列的头和尾的位置
} Queue;

// 将v加入队列Q
void Enqueue(Queue* Q, int v) {
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front) {
        printf("队列已满，无法再加入新的元素。\n");
        return;
    }
    Q->data[Q->rear] = v;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
}

// 初始化队列Q
void InitQueue(Queue* Q) {
    Q->front = 0;
    Q->rear = 0;
}

// 判断队列Q是否为空
bool isEmpty(Queue Q) {
    return Q.front == Q.rear;
}

// 从队列Q中删除一个元素，并将其保存到变量v中
void Dequeue(Queue* Q, int* v) {
    *v = Q->data[Q->front];
    Q->front++;
}

// 获取图G中给定点v的第一个邻接点
int FirstNeighbor(Graph G, int v) {
    for (int i = 0; i < G.vertexNum; i++) {
        if (G.edges[v][i] > 0) {
            return i;
        }
    }
    return -1;  // 没有邻接点
}

// 获取图G中给定点v的下一个邻接点
int NextNeighbor(Graph G, int v, int w) {
    for (int i = w + 1; i < G.vertexNum; i++) {
        if (G.edges[v][i] > 0) {
            return i;
        }
    }
    return -1;  // 没有更多的邻接点
}

// 初始化访问数组visited
void InitVisited(bool visited[]) {
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        visited[i] = false;
    }
}

// 打印点的信息
void PrintVertex(int v) {
    printf("%d ", v);
}



bool visited[MAX_VERTEX_NUM];  // 记录每个点是否已被访问

//保证非连通图所有顶点进行遍历
void BFSTraverse(Graph G){   //对图G进行广度优先遍历
    for (int i = 0; i < G.vertexNum; ++i)
    {
        visited[i]=false;     //访问标记数组初始化
    }
    Queue Q;
    InitQueue(&Q);  //初始化辅助队列Q
    for (int i = 0; i < G.vertexNum; ++i)   //从0号顶点开始遍历
    {
       if (!visited[i])      //对每个连通分量调用一次BFS
       {
        BFS(G,i);   //Vi未访问过，从Vi开始BFS
       }
       
    }
    

    
}


// 广度优先搜索
void BFS(Graph G, int v) {
    
    InitVisited(visited);  // 初始化访问数组
    Queue Q;  // 队列用于维护已访问的点
    InitQueue(&Q);  // 初始化队列


    visit(v);  // 访问点v
    visited[v] = true;  // 标记点v已被访问
    Enqueue(&Q, v);  // 将点v加入队列

    while (!isEmpty(Q)) {
        int v;
        Dequeue(&Q, &v);  // 从队列中删除一个元素
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            // 遍历v的所有邻接点w
            if (!visited[w]) {
                visit(w);  // 访问点w
                visited[w] = true;  // 标记点w已被访问
                Enqueue(&Q, w);  // 将点w加入队列
            }
        }
    }
}

