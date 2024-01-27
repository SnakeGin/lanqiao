//平均
//AC 贪心
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5+5;

typedef struct{
    int a,b;
}elem;

elem a[N];
int cnt[10];
int n;

bool cmp(elem a , elem b){
    return a.b<b.b;
}//升序排序

int main(){

    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
        cnt[a[i].a]++;
    }

    sort(a+1,a+n+1,cmp);//按照其代价对数组进行升序排序

    int left = n/10;
    //if count[0-9] == left 那么就不要去改变了
    int ret = 0;
    for(int i=1;i<=n;i++){
        int posi = a[i].a;
        int value = a[i].b;
        if(cnt[posi] > left){
            cnt[posi]--;
            for(int i=1;i<=n;i++){
                if(cnt[a[i].a] < left){
                    cnt[a[i].a]++;
                }
            }
            ret+=value;
        }
    }

    cout<<ret<<endl;

    return 0;
}