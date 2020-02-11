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
                              //一句话：malloc申请了对象需要的空间，类型转换声明了空间容纳的对象。
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
typedef struct VertexNode* PtrToVertexNode;//为什么将函数的输入，额外定义一个数据结构
/*
 *
 *  输入数据的结构定义使得：输入的规范使得函数可以成为一个“黑盒” .
 *  从C的函数传参开始，我们就有了传值而不是传变量的“规范”。
 *  因为变量是数据的载体。
 *  为了调用函数，所接受的上一层变量的数据，必须被加工为新的变量
 *  于是每一层相同的数据有两个不同的变量载体，一个是上一层传入符合这一层的变量，一个是传入下一层符合下一层规范的变量
 *  即每一层都有只属于自己的变量，这是分层(解耦合)的基础，
 *
 * */
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

// 3.从标准输入流，读入一幅图
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
 * 但是就C而言这样会导致前面的一些引用无法被编译器认可，只能从小到大，从后往前
 */
