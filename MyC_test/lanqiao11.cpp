//GCD
//数学知识题
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//gcd(a,b) = gcd(a,b-a)
//-->gcd(a+k,b+k) = gcd(a+k,a-b)
//a-b已知
int GCD(long a, long b){
    if(a<b)
        swap(a,b);
    if(a%b == 0){
        return b;
    }else{
        long c = a;
        a = b;
        b = c%b;
        GCD(a,b);
    }
}

int main()
{
    long a,b;
    cin>>a>>b;
    
    if(a<b)
        swap(a,b);

    long c = a-b;
    long k;

    k = c - a%c;
    
    cout<<k;
    return 0;
}
