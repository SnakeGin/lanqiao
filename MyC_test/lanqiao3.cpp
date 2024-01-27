//6.九宫重排
//不会
#include <iostream>
using namespace std;

#define MAX 10000
#define OK 1
#define ERROR 0

typedef int Status;
typedef char Vextype;
typedef int Arctype;

typedef struct{
    int vexnum,arcnum;//顶点与边的数目
    Arctype arcs[MAX][MAX];
    Vextype vexs[MAX];
}AMGraph;

typedef struct{
    Vextype base[MAX];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

Status EnQueue(SqQueue &Q , Vextype e){
    if((Q.rear+1)%MAX == Q.front)//队满
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAX;
    return OK;
}

Status DeQueue(SqQueue &Q , Vextype &e){
    if(Q.rear == Q.front)
        return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return OK;
}

int main(){

    AMGraph G1,G2;
    G1.vexnum = 9;
    G2.vexnum = 9;

    //顶点表的输入与边表的初始化
    for(int i=0;i<G1.vexnum;i++){
        cin>>G1.vexs[i];
        for(int j=0;j<G1.vexnum;j++){
            G1.arcs[i][j] = 0;
        }
    }
    
     for(int i=0;i<G2.vexnum;i++){
        cin>>G2.vexs[i];
         for(int j=0;j<G2.vexnum;j++){
            G2.arcs[i][j] = 0;
        }
    }

    return 0;
}