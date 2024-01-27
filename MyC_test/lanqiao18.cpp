//经典dp题，要先对原始序列进行排序，之后再进行动态规划
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010, mod = 1e9+7;
int T, n, m;
struct node{
    int wht, val;
}a[N];
int f[N][20*N];

bool cmp(node a, node b){
    return a.val + a.wht < b.val + b.wht;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].wht >> a[i].val, m += a[i].wht;
    
    sort(a+1, a+n+1, cmp);

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            f[i][k] = max(f[i][k], f[i-1][k]);
            if(k >= a[i].wht && k - a[i].wht <= a[i].val)
                f[i][k] = max(f[i][k], f[i-1][k-a[i].wht] + a[i].val);
            ans = max(ans, f[i][k]);
        }
    }
    cout << ans;
    
    return 0;
}
