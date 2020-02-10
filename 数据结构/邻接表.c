typedef int Vertex
typedef int WeightType
typedef int DataType
//??? 如何规划变量定义的顺序

// 1.1 数据结构 -- 数据结构的实现 -- 邻接表 AdjacentList

typedef struct Gnode* PtrToGNode; //  即PtrTpGNode 是指向结构GNode的指针
struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    AdjList G ; // AdjList 是邻接表的英文缩写 G是顶点，表结点，数组||通过G[i]访问 顶点表结点
};
typedef PtrTOGNode LGraph // 现在 LGraph是一种指向邻接表的图结构

// 重点是我们如何自定义，邻接表 它实际上 是链表“数组”，每个顶点对应一个链表


//1.2.1VertexNode 顶点--链表的顶点表结点 || 因为是数组，传指针参数就是传数组名，不需要PtrTpVertexNode

typedef struct VertexNode{                   /* 顶点表结点 */

    DataType Data;                           /* 数据域 -- 顶点数据 */
    EdgeNode FirstEdge;                 /* 指针域 -- 指向一个边表结点*/
}VertexNode,AdjList[MaxVertexNum=Nv];

//1.2.2EdgeNode 边-- 边，表结点 并没有使用指针来代替结点


typedef struct EdgeNode{
    Vertex adjvex;                           /* 数组域 -- 邻接顶点
    WeightType Weight;                                --  权重    */
    struct EdgeNode *Next;                  /* 指针域 -- 指向一个边表结点*/
}EdgeNode;



//1.3.1 初始化图
LGraph CreatGraph(int VertexNum){
    Vertex V,W;
    LGraph Graph;

    Graph = (LGraph)malloc(sizof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (V = 0; V <Graph->Nv ; V++) {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph
}

//1.3.2 插入EdgeNode
//1.3.2.1打包边数据
typedef struct Edge* PtrToEdge;
struct Edge {
    Vertex V ;
    Vertex W ;
    WeightType weight ;
};
typedef PtrToEdge Edge;
void InsertEdge(LGraph Graph,Edge E){
    //创建新的边表结点
    EdgeNode* NewEdgeNode = (EdgeNode*)malloc(sizeof(struct Edge));

    NewEdgeNode->adjvex = E->W;
    NewEdgeNode->weight = E->weight;
    //头插法
    NewEdgeNode->Next=Graph->G[E->V]->Next;
    Graph->G[E->V]->Next=NewEdgeNode;
}

//1.3.3 完整代码 省略

// 和之前一样 得益于封装的思想，即使内部细节变化，不影响外部输入，不会破坏代码结构
