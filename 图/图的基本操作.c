#include <stdbool.h>
#include <stddef.h>

//邻接矩阵
#define MAX_VERTICES 100
bool Adjacent(int G[][MAX_VERTICES], int x, int y)
{
    // 如果G[x][y]的值非零，就返回true
    if (G[x][y] != 0)
    {
        return true;
    }

    // 否则，返回false
    return false;
}




//邻接表法
struct AdjListNode
{
    int vertex; // 节点的编号
    struct AdjListNode *next; // 指向下一个节点的指针
};

struct ALGraph
{
    int numVertices; // 图中节点的数量
    struct AdjListNode **vertices; // 邻接表
};

bool Adjacent(struct ALGraph *G, int x, int y)
{
    // 取出节点x的邻接表
    struct AdjListNode *head = G->vertices[x];

    // 遍历邻接表
    while (head != NULL)
    {
        // 如果找到节点y，就返回true
        if (head->vertex == y)
        {
            return true;
        }

        // 继续遍历邻接表
        head = head->next;
    }

    // 如果没有找到节点y，就返回false
    return false;
}




