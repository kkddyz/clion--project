/* 数据结构 -- 数据结构的实现 -- 邻接矩阵 */

typedef int Vertex
typedef int WeightType
typedef int DataType

//1.1 图的数据结构
typedef struct Gnode *PtrTOGNode;            // 很聪明的通过typedef制造出一个指针类
struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    WeightType G[MaxVertaxNum][MaxVertaxNum] // 表示两点是否相邻 WeightType 权重类型
    DataType Data[MaxVertaxNum]              // 顶点数据
};
typedef PtrTOGNode MGraph                    // MGraph是指向使用邻接矩阵的图结构

// 2.1 数据结构 -- 初始化
typedef int Vertex
MGraph CreatGraph (int VertexNum){
    Vertex V , W ;
    MGraph Graph ;

    Graph = (MGraph)malloc(sizeof(struct GNode)) //为什么需要强制类型转换？？
    /*
     指针的类型不是它的类型，而是他指向内存的类型。malloc返回某块内存的首地址，其类型是void。
     内存类型决定内存的使用方式，int* 就会用4字节存放数据
     既然这块内存用来存放一个GNode类型的数据，那么这块内存的类型自然应该是GNode.
     */
    Graph -> Nv = VertexNum ; /*Graphs->为何是一个GNode对象 -- malloc强制类型转换，告诉编译器申请的内存存放变量的类型，因而对应的
                              Graph指针指向一个MGraph指针应该指向的对象-GNode*/
                              //一句话：malloc申请了对象需要的空间，类型转换创建了空间容纳的对象。
    Graph -> Ne = 0 ;

    for (V=0; V<Graph->Nv; V++){
        for (W=0; W<Graph->Nv; W++) {
            Graph->G[V][w] = 0;
        }
    }

    return Graph;
}
// 2.2 数据结构 -- 插入边
typedef struct ENode *PtrToENode
struct ENode {
    Vertex V ;
    Vertex W ;
    WeightType weight ;
};
typedef PtrToENode Edge

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V][E->W]=E->weight
}

// 全部函数
vold BuildGraph(){
    int Nv ;
    Vertex V ;
    MGraph Graph ;
    Edge E ;
    scanf("%d",&Nv);
    Graph = CreatGraph(Nv);
    scanf("%d",&Graph->Ne);
    if( Graph->Ne != 0){
        /* 读入边 */
        E = (Edge)malloc(sizeof(struct Edge)) ;
        for ( i = 0; i < Graph->Nv; ++i) {
            scanf("%d %d %d",&E->V,&E->W,&E->weight);
            InsertEdge(Graph,E);

        }
    }
    /* 读入顶点数据 */
    for (int V = 0; V <Graph->Nv ; ++V) {
        scanf("%d",&Graph->Data[V]);
    }
    return Graph;
}
/*
 * 从思考的角度应该是从大框架到小细节，从前往后编程，如：python，
 * 但是就C而言这样会导致前面的一些引用无法被编译器认可，只能从小到大，从后往前
 */
