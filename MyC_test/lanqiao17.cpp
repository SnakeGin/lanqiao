//奇怪的数
//应该又是一个算前缀和，不断加位的到dp的动态规划题
//dp[n][m] = dp[n-1][m-1]+....dp[n-1][m-9];
//初始化dp[1][m] = (m+1)/2 【当m为个位数时】
//dp[1][m] = 5 【当m为十位数时】
//要分n的奇偶性
//不断动规，归到题目所要求的n位
//5%nnd 有问题待改进
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 20000

int n,m;
long ret;
const long mod = 998244353;
int dp[MAX][51];

void input(){
    cin>>n>>m;
}

void Init(int m){//初始化dp
    memset(dp,0,sizeof(dp));
    if(m<10){
        for(int j=1;j<=m;j++)
        dp[1][j] = (j+1)/2;
    }else{
        for(int j=10;j<=m;j++)
        dp[1][j] = 5;
    }
}

int sum(int i ,int j){
    int sum = 0;
    if(i%2 == 0){
        for(int k=0;k<=j;k+=2){
            sum+=dp[i-1][j-k];
        }
    }else{
        for(int k=0;k<=j;k+=2){
            sum+=dp[i-1][j-k];
        }
    }
    return sum;
}

void func(){
    for(int i=2;i<=n;i++){
        if(i%2 == 0){
            for(int j=0;j<=m;j++){
                dp[i][j] = sum(i,j);
            }
        }else{
            for(int j=0;j<=m;j++){
                dp[i][j] = sum(i,j);
            }
        }
    }
}

void output(){
    cout<<dp[n][m]%mod<<endl;
}

int main(){

    input();
    Init(m);
    func();
    output();

    return 0;
}