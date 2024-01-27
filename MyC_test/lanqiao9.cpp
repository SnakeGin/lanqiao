//刷题统计
//60%
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long int a,b,n;
int flag[7] = {1,1,1,1,1,0,0};

int main(){

    cin>> a >> b >> n;

    long long int total = 0;
    int i=0;
    int ret = 0;
    while(total < n){
        if(flag[i] == 1)
            total+=a;
        else
            total+=b;
        i++;
        ret++;
        if(i==7)
            i = 0;
    }

    cout<<ret<<endl;

    return 0;
}
