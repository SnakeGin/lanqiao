//三国游戏
//类似选择不能构成三角形
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5+10;
int n;
long A[N],B[N],C[N];

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1;i<=n;i++){
        cin>>B[i];
    }
    for(int i=1;i<=n;i++){
        cin>>C[i];
    }
}

bool cmp(long a , long b){
    return a>b;
}//降序排序

int func(long A[] , long B[], long C[] , int n){
    long D[N];
    for(int i=1;i<=n;i++){
        D[i] = A[i] - B[i] - C[i];
    }
    sort(D+1,D+1+n,cmp);

    long sum = 0;
    int ret = 0;
    for(int i=1;i<=n;i++){
        sum+=D[i];
        if(sum>0){
            ret++;
        }else{
            break;
        }
    }

    return ret;
}

int main(){

    input();

    long ans = max(max(func(A,B,C,n),func(B,C,A,n)),func(C,A,B,n));
    if(ans != 0){
        cout<<ans<<endl;
    }else{
        cout<<"-1"<<endl;
    }

    return 0;
}