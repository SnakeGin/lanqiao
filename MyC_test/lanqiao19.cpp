//蜗牛
//dp题 20%
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define Vx 1
#define Vuy 0.7
#define Vdy 1.3

const int N = 10005;
long long n,x[N],a[N],b[N];
long double dp[N][2];//0表示在坐标轴上，1表示在竹竿上
//表示到了第i根竹竿时在竹竿上或者在坐标轴所用的时间

int main(){

    cin>>n;
    memset(x,0,sizeof(x));
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<n;i++){
        cin>>a[i]>>b[i+1];
    }
    /*  
        ###对于dp[0][0]=0;dp[0][1]=0(无定义)
        dp[1][0]=(x[1]-x[0])/Vx dp[1][1] = dp[1][0]+a[1]/Vuy
        dp[2][0]=min(dp[1][0]+(x[2]-x[1])/Vx , dp[1][1]+b[2]/Vdy)
        
        dp[2][1]=if(a[2]>b[2])
            min(dp[2][0]+a[2]/Vuy , dp[1][1]+(a[2]-b[2])/Vuy);
            else{
            min(dp[2][0]+a[2]/Vuy , dp[1][1]+(b[2]-a[2])/Vdy);
            }
    */
    dp[1][0]=(x[1]-x[0])/Vx;
    dp[1][1] = dp[1][0]+a[1]/Vuy;

    for(int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][0]+(x[i]-x[i-1])/Vx , dp[i-1][1]+b[i]/Vdy);
        if(a[i]>b[i]){
            dp[i][1] = min(dp[i][0]+a[i]/Vuy , dp[i-1][1]+(a[i]-b[i])/Vuy);
        }else{
            dp[i][1] = min(dp[i][0]+a[i]/Vuy , dp[i-1][1]+(b[i]-a[i])/Vdy);
        }
    }
    printf("%.2Lf\n",dp[n][0]);

    return 0;
}