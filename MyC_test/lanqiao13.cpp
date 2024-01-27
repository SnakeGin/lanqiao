//生物芯片
//40%
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100000
long long N,L,R;

int main(){

    cin>>N>>L>>R;
    int a[MAX];
    memset(a,0,sizeof(a));

    for(long long i=2;i<=N;i++){
        for(long long j=1;j*i<=N;j++){
            if(a[i*j] == 1){
                a[i*j] = 0;
            }else{
                a[i*j] = 1;
            }
        }
    }

    long long count = 0;
    for(long long i=L;i<=R;i++){
        if(a[i] == 1)
            count++;
    }

    cout<<count<<endl;

    return 0;
}