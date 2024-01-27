//次数差 AC
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 27
#define Length 1000
int main(){

    int count[MAX];
    char str[Length];

    memset(count,0,sizeof(count));

    cin>>str;

    int length = strlen(str);
    for(int i=0;i<length;i++){
        count[str[i]-'a'+1]++;
    }//计数

    int max = 0;
    int min = 1000;
    for(int i=1;i<MAX;i++){
        if(max<count[i])
            max = count[i];
        if(min>count[i] && count[i]!=0)
            min = count[i];
    }

   // cout<<max<<" "<<min<<endl;

    cout<<max-min<<endl;

    return 0;
}