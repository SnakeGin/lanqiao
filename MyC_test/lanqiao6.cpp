//有奖问答
#include <iostream>
using namespace std;

int main(){

    long long int sum = 0;
    int dp[31][100];
    for(int i=1;i<=30;i++){
      for(int j=0;j<=90;j+=10){
        dp[i][j] = 0;
      }
    }
    dp[1][0] = dp[1][10] = 1;
    for(int i=2;i<=30;i++){
        for(int j=0;j<=90;j+=10){
            if(j == 0){//如果在此处回答错误，那么dp[i][j]等于之前所有的结果之和
                for(int k=0;k<=90;k+=10){
                    dp[i][j] += dp[i-1][k];
                }
            }else{//如果没有回答错误，就正常记录
                dp[i][j] = dp[i-1][j-10];
                if(j == 70) 
                    sum+=dp[i][j];
            }
        }
    }

    cout<<sum<<endl;
    
    return 0;
}