typedef int Vertex
typedef int cost
typedef Vertex EdgeFrom


/*
 * 图的数据结构就以邻接矩阵为准,vertex数量为N,edge数量E
 */
typedef struct AdjNode *PtrToAdjNode;
struct AdjNode{
    Vertex V;
    EdgeFrom W;
    cost dist;

};
typedef PtrToAdjNode AdjNode;
struct AdjList{
    // 邻点的列表,就用python的列表
};
typedef struct AdjList *AdjList;
void addList(AdjNode node,AdjList list){
    //把node插入list尾部
}
