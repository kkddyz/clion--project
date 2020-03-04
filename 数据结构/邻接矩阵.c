/* 图的数据结构-邻接矩阵 -- 接口函数 -- 从标准输入流，读入一幅图  */
//0.用户设置数据类型
typedef int Vertex
typedef int WeightType
typedef int DataType

//1. 数据结构的实现 -- 邻接矩阵
typedef struct Gnode *PtrTOGNode;            // 很聪明的通过typedef制造出一个指针类
struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    WeightType G[MaxVertaxNum][MaxVertaxNum] // 表示两点是否相邻 WeightType 权重类型
    DataType Data[MaxVertaxNum]              // 顶点数据
};
typedef PtrTOGNode MGraph                    // MGraph是指向使用邻接矩阵的图结构

// 2.1 接口函数 -- CreatGraph -- 创建无边图 
typedef int Vertex

//创造一个数组需要 从heap申请对象的空间(malloc),规划内部空间(声明),以及初始化空间。

MGraph CreatGraph (int VertexNum){
    Vertex V , W ;
    MGraph Graph ;

    Graph = (MGraph)malloc(sizeof(struct GNode)) //为什么需要强制类型转换？？
    /*
     malloc的空间默认当作char数组使用。
     一旦你申明结构类型(告诉编译器如何划分内存)，那么一个变量就被“创造出来了”
     */
    Graph -> Nv = VertexNum ; //当你声明数据解构的类型后，编译器自然会安排哪里放Nv 哪里放Ne
    Graph -> Ne = 0 ;

    for (V=0; V<Graph->Nv; V++){
        for (W=0; W<Graph->Nv; W++) {
            Graph->G[V][w] = 0;
        }
    }

    return Graph;
}



//2.2 接口函数 -- SetVertexData -- 设置顶点数据


//2.2.1 顶点类型
/* 为什么将函数的输入，额外定义一个数据结构
   从C的函数传参开始，我们就有了传值而不是传变量的“规范”。
   因为 任何程序的实现都是分层的，不同的层实现不同的作用，需要不同的变量。(接口不同)
   每一层都使用接口规范定义的变量，就像java的私有变量。
*/
typedef struct VertexNode* PtrToVertexNode;
struct VertexNode{
    Vertex vertex;
    DataType value;
};
typedef PtrToVertexNode VertexNode;


//2.2.2 接口函数 -- SetVertexData -- 导入顶点数据
void SetVertexDData(MGraph Graph,VertexNode vertexNode){
    Graph->Date[vertexNode->vertex]=vertexNode->value;
}


//2.3 接口函数 -- InsertEdge -- 插入边

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

// 3.从标准输入流，读入一幅图  分两层 
// 数据读入层(标准数据流-->VertexNode/ENode)||  建立图 creat(Nv) setVertexDate(VerexNode) insertEdge(Edge)
 vold BuildGraph(){
    int Nv ;
    Vertex V ;
    MGraph Graph ;
    Edge E ; VertexNode vertexNode;
    scanf("%d",&Nv);
    Graph = CreatGraph(Nv);
    scanf("%d",&Graph->Ne);
    if( Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct Edge)) ;
        for ( int i = 0; i < Graph->Nv; ++i) {
            /* 从标准输入流读入边 */
            scanf("%d %d %d",&E->V,&E->W,&E->weight);
            /* 插入边*/
            InsertEdge(Graph,E);

        }
    }
////////////////////////////////////////////////////////////////////////////////
    vertexNode = (VertexNode)malloc(sizeof(struct VertexNode));
    for ( i = 0; i <Graph->Nv ; ++i) {
        /* 从标准输入流读入顶点数据 */
        scanf("%d %d",&vertexNode->vertex,&vertexNode->value);
        /* 设置顶点数据*/
        SetVertexDData(Graph,vertexNode);
    }
    return Graph;
}
/*
 * 从思考的角度应该是从大框架到小细节，从前往后编程，如：python，
 * 但是就C而言这样会导致前面的一些引用无法被编译器认可，因此只能从小到大
 */
