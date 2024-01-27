//灌溉 AC
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 110

typedef struct{
    int data;
    bool visited;
}elem;

int n,m,t,k;
elem pos[MAX][MAX];
int ret;

void input(){
    cin>>n>>m>>t;

    memset(pos,0,sizeof(pos));

    for(int i=0;i<t;i++){
        int c,r;
        cin>>r>>c;
        pos[r][c].data = 1;
        pos[r][c].visited = 1;
    }

    cin>>k;
}

void func(int n , int m, int k, elem pos[MAX][MAX]){
    if(k==0)
        return;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pos[i][j].data == 1 && pos[i][j].visited == true){
                pos[i-1][j].data = 1;
                pos[i+1][j].data = 1;
                pos[i][j-1].data = 1;
                pos[i][j+1].data = 1;
            }
        }
    }

    //为此次遍历为1的全部赋值为访问过
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pos[i][j].data == 1){
                pos[i-1][j].visited = true;
                pos[i+1][j].visited = true;
                pos[i][j-1].visited = true;
                pos[i][j+1].visited = true;
            }
        }
    }
    func(n,m,k-1,pos);
}

void count(int n, int m,elem pos[MAX][MAX]){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(pos[i][j].data == 1)
                ret++;
}

void output(){
    cout<<ret<<endl;
}

int main(){

    input();
    func(n,m,k,pos);
    count(n,m,pos);
    output();

    return 0;
}