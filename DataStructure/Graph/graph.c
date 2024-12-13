//
// Created by Rainy-Heights on 2024/12/7.
//

#include <malloc.h>
#include "graph.h"
#include "stdio.h"
Graph create(){   //创建时，我们可以指定图中初始有多少个结点
    Graph graph = (Graph) malloc(sizeof(struct MatrixGraph));
    graph->vertexCount = 0;    //顶点和边数肯定一开始是0
    graph->edgeCount = 0;
    for (int i = 0; i < MaxVertex; ++i)    //记得把矩阵每个位置都置为0
        for (int j = 0; j < MaxVertex; ++j)
            graph->matrix[i][j] = 0;
    return graph;
}

void addVertex(Graph graph, E element){
    if(graph->vertexCount >= MaxVertex) return;
    graph->data[graph->vertexCount++] = element;   //添加新元素
}

void addEdge(Graph graph, int a, int b){   //添加几号顶点到几号顶点的边
    if(graph->matrix[a][b] == 0) {
        graph->matrix[a][b] = 1;  //注意如果是无向图的话，需要[a][b]和[b][a]都置为1
        graph->edgeCount++;
    }
}

void printGraph(Graph graph){
    for (int i = -1; i < graph->vertexCount; ++i) {
        for (int j = -1; j < graph->vertexCount; ++j) {
            if(j == -1)
                printf("%c", 'A' + i);
            else if(i == -1)
                printf("%3c", 'A' + j);
            else
                printf("%3d", graph->matrix[i][j]);
        }
        putchar('\n');
    }
}

NodeGraph createNodeGraph(){   //创建时，我们可以指定图中初始有多少个结点
    NodeGraph graph = malloc(sizeof(struct AdjacencyGraph));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;   //头结点数组一开始可以不用管
}

void addNodeVertex(NodeGraph graph, E element){
    if(graph->vertexCount >= MaxVertex) return;   //跟之前一样
    graph->vertex[graph->vertexCount].element = element;   //添加新结点时，再来修改也行
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addNodeEdge(NodeGraph graph, int a, int b){
    Node node = graph->vertex[a].next;
    Node newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if(!node) {    //如果头结点下一个都没有，那么直接连上去
        graph->vertex[a].next = newNode;
    } else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do {
            if(node->nextVertex == b) return;   //如果已经连接了对应的顶点，那么直接返回
            if(node->next) node = node->next;   //否则继续向后遍历
            else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //边数计数+1
}

void printNodeGraph(NodeGraph graph){
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
}

/**
 * 深度优先搜索算法（无向图和有向图都适用）
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 */
void dfs(NodeGraph graph, int startVertex, int targetVertex, int * visited) {
    visited[startVertex] = 1;   //走过之后一定记得mark一下
    printf("%c -> ", graph->vertex[startVertex].element);   //打印当前顶点值
    Node node = graph->vertex[startVertex].next;   //遍历当前顶点所有的分支
    while (node) {
        if(!visited[node->nextVertex])   //如果已经到过（有可能是走其他分支到过，或是回头路）那就不继续了
            dfs(graph, node->nextVertex, targetVertex, visited);  //没到过就继续往下走，这里将startVertex设定为对于分支的下一个顶点，按照同样的方式去寻找
        node = node->next;
    }
}

//int main() {
//    Graph graph = create();
//    for (int c = 'A'; c <= 'D'; ++c)
//        addVertex(graph, (char) c);
//    addEdge(graph, 0, 1);   //A -> B
//    addEdge(graph, 1, 2);   //B -> C
//    addEdge(graph, 2, 3);   //C -> D
//    addEdge(graph, 3, 0);   //D -> A
//    addEdge(graph, 2, 0);   //C -> A
//
//
//    NodeGraph nodeGraph = createNodeGraph();
//    for (int c = 'A'; c <= 'D'; ++c)
//        addNodeVertex(nodeGraph, (char) c);
//    addNodeEdge(nodeGraph, 0, 1);   //A -> B
//    addNodeEdge(nodeGraph, 1, 2);   //B -> C
//    addNodeEdge(nodeGraph, 2, 3);   //C -> D
//    addNodeEdge(nodeGraph, 3, 0);   //D -> A
//    addNodeEdge(nodeGraph, 2, 0);   //C -> A
//
//    printGraph(graph);
//
//    printNodeGraph(nodeGraph);
//}