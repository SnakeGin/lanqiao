//重新排序
//0%
#include <iostream>
using namespace std;
#define MAX 10000

typedef struct{
    int data;
    bool visited;
}elem;

void func(elem A[],int n ,int l[], int r[] , int m ,int count[]){
    
    int max_inA = 1;
    for(int i=1;i<=n;i++){
        if(A[i].data>A[max_inA].data && !A[i].visited){
            max_inA = i;
        }
    }//找到目前最大值的位置且是严格大于
    
    //cout<<max_inA<<" ";
    A[max_inA].visited = true; //该最大值位置不可再访问

    int pos_cf = 1;
    for(int j=1;j<=n;j++){
        if(count[j]>count[pos_cf]){
            pos_cf = j;
        }
    }//找到重复次数最多的地方且是严格最多
    //cout<<pos_cf<<endl;
    
    if(count[pos_cf]!=1){
        //交换位置,避免到了全是1的地步，仍要交换位置
        A[0] = A[max_inA];
        A[max_inA] = A[pos_cf];
        A[pos_cf] = A[0];
    }
    
    if(count[pos_cf] != 1){
        count[pos_cf]--;//此处位置要降1，下一次就不再访问此处
        func(A,n,l,r,m,count);
    }
    
}

int main(){
    int n;
    cin>>n;
    
    elem A[n+1];
    for(int i=1;i<=n;i++){
        cin>>A[i].data;
    }
    
    int m;
    cin>>m;
    int l[m],r[m];
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    
    int origin = 0;
    for(int i=0;i<m;i++){
        for(int j = l[i];j<=r[i];j++){
            origin += A[j].data;
        }
    }
    //cout<<origin;
    
    //此题就是要让最大的部分重合，如果不能重合，就各自使得自己的部分最大
    //如果有多重重复？-->取重复长度最长的部分？还是取重复区间最多的部分？
    int count[n];
    for(int i=1;i<=n;i++){
        count[i] = 0;
    }   
    
    for(int i=0;i<m;i++){
        for(int j=l[i];j<=r[i];j++){
            count[j]++;//将重复取到的位置计数
        }
    }//在重复次数最多的地方放置数组中较大的值
    
    func(A,n,l,r,m,count);
    
    int now = 0;
    for(int i=0;i<m;i++){
        for(int j = l[i];j<=r[i];j++){
            now += A[j].data;
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<A[i].data<<" ";
    //}

    cout<<now-origin<<endl;
    
    return 0;
}
