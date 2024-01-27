//青蛙过河
//数学题！！！
//二分查找，利用前缀和数组进行二分查找到最小的步长
/*
将所有的石头按照区间分类：1步可达的石头，2步可达的石头，，，，显然能通过一步走到，就绝对不通过两步去走
因为石头能被踩的次数是有限的，例如：1，2，3，4，假如最大步长为3，在1的时候，可以一步走到4号石头，但要是
从1走到2，再从2走到4，跟直接从岸上走到2，再从2走到4没有区别，因此，每一次移动，都必须移动到不同标号的区间去
有效的移动只有跨不同区间的移动
步长合法性判断：
对于任意石头i,区间[i,i+x)中的石头可被踩的总数>=2x
证明：
岸，1，2，3，|4，5，6，|7，8，9，岸
按照有效移动理论，在1时，下一步只能走到4去，因此，想要容纳1全部的被踩次数，4号的石头高度应>=1号，而显然，
想要总过河次数>=2x，那么区间[1,3]中石头总高度>=2x，因为出门的第一步必须要有2x次以上，即[1,3]总高度>=2x，
又因4号高度>=1号高度，故区间[2,4]高度之和>=2x，以此类推，可以证明，要想总过河次数>=2x，任一石头编号开始长度为
步长的区间石头总高度之和>=2x

就是说要找到最小的1->n中的n满足：
sum[1...n]>=2x


再按照二分法搜索答案，适用二分法的特性：当步长为ans时可满足题目要求，ans+1一定可以满足题目要求
初始解区间[1,n],不断将解区间二分寻找到能够满足题目要求的最小解
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define OK 1
#define ERROR 0

typedef int Status;

//变量申明
const int N = 100000;
int n,x;
int H[N],sum[N];
int y;
int l,r;//二分查找

//输入
void input(){
    cin>>n>>x;
    memset(H,0,sizeof(H));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<n;i++){
        cin>>H[i];
        sum[i] = sum[i-1]+H[i];//前缀和
    }
    l = 1;
    r = n;
}

//主函数
Status func1(int m){
    for(int i=1;i<n-m+1;i++){
        if(sum[i-1+m]-sum[i-1]<2*x)
            return ERROR;
    }
    return OK;
}

Status func2(){
    while(l!=r){
        int mid = (l+r)/2;
        if(func1(mid)) 
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

//输出
void output(){
    y = l;
    cout<<y<<endl;
}

int main(){

    input();
    func2();
    output();

    return 0;
}