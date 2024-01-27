//左移右移
//可以用哈希表来做
//30% 超时
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define OK 1
#define ERROR 0
#define MAX 200000

typedef int Status;
typedef int elem;

typedef struct{
    char str;
    elem data;
}Option;

typedef struct LNode{
    elem data;
    struct LNode* next;
}LNode,*Linklist;

void InitList(Linklist &L){
    L = new LNode;
    L->next = NULL;
}

Status CreateList(Linklist &L , int n){

    LNode *r,*p;
    r = L;
    for(int i=1;i<=n;i++){
        p = new LNode;
        p->data = i;
        p->next= NULL;
        r->next = p;
        r = p;
    }//尾插法建立链表

    return OK;
}

int N,M;
Option A[MAX];

void Input(int m){
    for(int i=0;i<m;i++){
        cin>>A[i].str>>A[i].data;
    }
}

Status func(Option a , Linklist &L){
    if(a.str == 'L'){
        LNode *p;
        LNode *pre;
        p = L->next;
        pre = L;
        while(p->data!=a.data){
            p = p->next;
            pre = pre->next;
        }//找到p节点及其前驱
        //完成左移操作
        pre->next = p->next;
        p->next = L->next;
        L->next = p;

    }else{//a.str == 'R'
        LNode *p,*pre,*r;
        p = L->next;
        pre = L;
        r = L->next;
        while(r->next){
            r = r->next;
        }//找到尾节点
        while(p->data!=a.data){
            p = p->next;
            pre = pre->next;
        }//找到p与其前驱节点

        //完成右移
        pre->next = p->next;
        p->next = NULL;
        r->next = p;
    }
    return OK;
}

void PrintList(Linklist L){
    LNode *p;
    p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){

    cin>>N>>M;
    Linklist L;
    InitList(L);
    CreateList(L,N);

    Input(M);

    for(int i=0;i<M;i++){
        func(A[i],L);
    }

    PrintList(L);

    cout<<endl;

    return 0;
}