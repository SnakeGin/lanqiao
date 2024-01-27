//螺旋折线
#include <iostream>
using namespace std;

int main(){

    long long int x,y;
    cin>>x>>y;

    if(x<=y && x>=-y){
        cout<<(2*y-1)*(2*y)+x-(-y)<<endl;
    }else if(y<=x && y>=-x){
        cout<<(2*x)*(2*x)+x-y<<endl;
    }else if(x<0 && y<=-x && y>=x-1){
        cout<<(2*(-x)-1)*(2*(-x)-1)+y-x-1<<endl;
    }else{
        cout<<(2*(-y))*(2*(-y)+1)-y-x<<endl;
    }

    return 0;
}