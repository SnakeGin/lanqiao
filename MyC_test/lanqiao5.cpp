//数字三角形
#include <iostream>
using namespace std;

int Max(int a,int b){//返回a，b的最大值 
    if(a<b){
        return b;
    }else{
        return a;
    }
}

int main(){
    int n;
    cin>>n;
    int An[n][n]; 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>An[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(i>=1){
                if(j==0)
                    An[i][j] += An[i-1][j];
                else if(j == i)
                    An[i][j] += An[i-1][j-1];
                else{
                    int max1 =Max(An[i - 1][j - 1],An[i - 1][j]); 
                    An[i][j] += max1;
                }
            }
        }
    }
  
    if(n%2==1)  
        printf("%d\n",An[n-1][(n-1)/2]);
    else 
        printf("%d\n",Max(An[n-1][(n-1)/2],An[n-1][(n-1)/2+1]));
        
    return 0;
}

