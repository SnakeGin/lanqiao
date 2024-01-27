//滑行
//动态规划之记忆化搜索
#include <iostream>
#include <cstring>
using namespace std;

const int N = 110; //为了满足所有测试样例

int n,m; 
int A[N][N]; //矩阵
int f[N][N]; //记忆数组,存储每一个坐标能到达的最远位置
//偏移量数组
//坐标偏移量 这样排列是为了可以覆盖所有可能！
int dir[5] = {0,1,0,-1,0};

int dp(int x , int y){
    //记忆化搜索
    if(f[x][y] != -1) return f[x][y]; //搜索过就不再搜索

    f[x][y] = 1;//初始化，如果一个点都走不了最远距离就是1

    for(int i=0;i<4;i++){
        int cx = x+dir[i] , cy = y+dir[i+1];
        if(cx>0 && cx<=n && cy>0 && cy<= n && A[x][y]>A[cx][cy]){
            //这个坐标在矩阵范围内，并且满足题目要求
            f[x][y] = max(f[x][y] , dp(cx,cy)+1);
        }  
    }

    return f[x][y];

}

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>A[i][j];
        }
    }
    //memset函数包含在cstring头文件内
    memset(f,-1,sizeof f); //初始化f都为-1
    //-1就代表未搜索，在dp函数中会根据此判断是否搜索过

    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            res = max(res,dp(i,j));
        }
    }

    cout<<res<<endl;

    return 0;
}