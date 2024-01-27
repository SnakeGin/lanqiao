//方程整数解
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

int main(){
    
    //19是分界点
    int a = 1;
    int c = 19;
    int ret = 1000;
    for(a = 1;a<=18;a++){
        for(c = 19;c<=31;c++){
            int d = pow(a,2)+pow(c,2);
            int m = ret - d;
            int b = sqrt(m);
            if(pow(b,2) == m){
                printf("%d %d %d\n",a,b,c);
            }
        }
    }
    return 0;
}