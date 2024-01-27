//数组切分
//AC dp题
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5+5;
const long long mod = 1e9+7;
int n,A[N];
long dp[N];//前n个数的拆分种类
//将每种都切开就算一种
//自身不切开也算是一种

int min(int a, int b){
    return a<b?a:b;
}

int max(int a, int b){
    return a>b?a:b;
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        int m,M;
        m=M=A[i];
        for(int j=i;j>=1;j--){
            m = min(A[j],m);
            M = max(A[j],M);
            if(M-m == i-j){//如果这一段满足连续自然数，那么dp[i] = dp[i]+dp[j-1];
                dp[i] += dp[j-1];
                dp[i] %= mod;
            }
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}