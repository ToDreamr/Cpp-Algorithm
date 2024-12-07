//
// Created by Rainy-Heights on 2024/12/7.
//

#ifndef CARL_CODE_GRAPH_H
#define CARL_CODE_GRAPH_H
#define MaxVertex 5

typedef char E;   //顶点存放的数据类型

typedef struct MatrixGraph {
    int vertexCount;   //顶点数
    int edgeCount;     //边数
    int matrix[MaxVertex][MaxVertex];   //邻接矩阵
    E data[MaxVertex];    //各个顶点对应的数据
} * Graph;

#define MaxVertex 5

typedef char E;

typedef struct Node {   //结点和头结点分开定义，普通结点记录邻接顶点信息
    int nextVertex;
    struct Node * next;
} * Node;

struct HeadNode {   //头结点记录元素
    E element;
    struct Node * next;
};

typedef struct AdjacencyGraph {
    int vertexCount;   //顶点数
    int edgeCount;     //边数
    struct HeadNode vertex[MaxVertex];
} * NodeGraph;

#endif //CARL_CODE_GRAPH_H
