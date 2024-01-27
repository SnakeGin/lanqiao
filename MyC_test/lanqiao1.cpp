//3.排序 30%
#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int sum = 0;
    int m = n,flag = 1;
    while(m>0 && flag == 1){
        flag = 0;
        for(int j=1;j<m;j++){
            if(a[j]>a[j+1]){
                flag = 1;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                sum+=a[j+1];
            }
        }
        m--;
    }
    cout<<sum<<endl;

    return 0;
}