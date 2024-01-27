#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 20

typedef char elem;
typedef int Status;

//二叉树
typedef struct BiNode {
    elem data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;  

void InitTree(BiTree &T) {
    T = NULL;  
}

Status CreateBiT(BiTree &T) {
    elem data;
    cin >> data;
    if (data == '#') {
        T = NULL;
        return 0;
    }
    T = new BiNode;  
    T->data = data;
    CreateBiT(T->lchild);  
    CreateBiT(T->rchild);  
    return 1; 

} 

void PreTree(BiTree T){
    if(T == NULL)
        return;
    cout<<T->data<<" ";
    PreTree(T->lchild);
    PreTree(T->rchild);
}

//顺序栈
typedef struct{
    elem *base;
    elem *top;
    int stacksize;
}SqStack;

void InitSqStack(SqStack &S){
    S.base = new elem[MAX];
    S.top = S.base;
    S.stacksize = MAX;
}

Status Push(SqStack &S , elem e){
    if(S.top - S.base == S.stacksize)
        return OK;
    *(S.top) = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S , elem &e){
    if(S.base == S.top)
        return OK;
    e = *(S.top-1);
    S.top--;

    return OK;
}

elem GetTop(SqStack S){
    if(S.base == S.top)
        return '#';
    else
        return *(S.top-1);
}

//单链表
typedef struct LNode{
    elem data;
    struct LNode *next;
}LNode,*Linklist;

void InitList(Linklist &L){
    L = new LNode;
    L->next = NULL;
}

Status CreateList(Linklist &L){

    elem data;
    cin>>data;
    LNode *p,*r;
    r = L;
    while(data != '#'){
        p = new LNode;
        p->data = data;
        p->next = NULL;
        r->next = p;
        r = p;
    }

    return OK;
}

Status CreateHlist(Linklist &L){
    elem data;
    cin>>data;
    LNode *p,*h;
    h = L;
    while(data != '#'){
        p = new LNode;
        p->data = data;
        p->next = h->next;
        h->next = p;
    }
    return OK;
}

Status Printlist(Linklist L){
    LNode *p;
    p = L->next;
    while(p){
        cout<<p->data;
        p = p->next;
    }
    return OK;
}

int main(){

    BiTree T;
    InitTree(T);
    CreateBiT(T);

    PreTree(T);
    cout<<endl;

    SqStack S;
    InitSqStack(S);
    elem e,x;
    cin>>e;
    Push(S,e);
    elem top = GetTop(S);
    cout<<"The Top of the Stack is :"<<top<<endl;
    Pop(S,x);
    cout<<x<<endl;

    Linklist L1,L2;
    InitList(L1);
    InitList(L2);
    CreateList(L1);
    CreateHlist(L2);

    Printlist(L1);
    cout<<endl;
    Printlist(L2);
    cout<<endl;

    return 0;
}
