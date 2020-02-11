// 图的数据结构-邻接表 -- 接口函数 -- 从标准输入流，读入一幅图  */

//0.用户设置数据类型
typedef int Vertex
typedef int WeightType
typedef int DataType


//1.1 数据结构的实现 -- 邻接表 AdjacentList

typedef struct Gnode* PtrToGNode; //  即PtrTpGNode 是指向结构GNode的指针
struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    AdjList G ; // AdjList 是邻接表的英文缩写 G是顶点，表结点，数组||通过G[i]访问 顶点表结点
};
typedef PtrTOGNode LGraph



//1.2VertexNode 顶点--链表的顶点表结点 || 因为是数组，传指针参数就是传数组名，不需要PtrTpVertexNode

typedef struct VertexNode{                   /* 顶点表结点 */

    DataType Data;                           /* 数据域 -- 顶点数据 */
    EdgeNode FirstEdge;                 /* 指针域 -- 指向一个边表结点*/
}VertexNode,AdjList[MaxVertexNum=Nv];

//1.3EdgeNode   边-- 边表结点 并没有使用指针来代替结点


typedef struct EdgeNode{
    Vertex adjvex;                           /* 数组域 -- 邻接顶点
    WeightType Weight;                                --  权重    */
    struct EdgeNode *Next;                  /* 指针域 -- 指向一个边表结点*/
}EdgeNode;



//2.1 接口函数 -- CreatGraph -- 创建无边图,并设置顶点数据

        /* 也可以像之前把SetVertexData单独封装成一个函数  */

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


//2.2 接口函数 -- InsertEdge -- 插入边
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


//1.3.3 完整代码 略

        /* 和之前一样 BuildGraph函数某块相同，所以函数结构层次不变。*/

