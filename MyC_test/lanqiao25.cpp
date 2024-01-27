//长草
//0？？？数组开大了 rnm
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstring>

using namespace std;
const int MAX = 1e4+10;
int n,m,k;
typedef struct {
    char str;
    bool visited;
    int month;        
}elem;

elem a[MAX][MAX];

int main(){

    cin>>n>>m;
    memset(a,0,sizeof(a));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j].str;
            if(a[i][j].str == 'g'){
                a[i][j].month = 1;
            }
        }
    }

    cin>>k;

    for(int x=1;x<=k;x++){
        for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
                if(a[i][j].str == 'g'){
                    if(a[i][j].visited==false && a[i][j].month==1){
                        a[i-1][j].str = 'g';if(a[i-1][j].month !=1) a[i-1][j].month = 2; 
                        a[i+1][j].str = 'g';if(a[i][j-1].month !=1) a[i][j-1].month = 2; 
                        a[i][j+1].str = 'g';if(a[i+1][j].month !=1) a[i+1][j].month = 2; 
                        a[i][j-1].str = 'g';if(a[i][j+1].month !=1) a[i][j+1].month = 2; 
                        a[i][j].month = 0;
                        a[i][j].visited = true;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j].str =='g' && a[i][j].visited==false && a[i][j].month == 2){
                        a[i][j].month = 1;
                }
            }
        }
    }   

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j].str;
        }
        cout<<endl;
    }

    return 0;
}