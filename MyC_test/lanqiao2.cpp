//4.移动 AC
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

void func(char str[], int &x , int &y , int length){
    for(int i=0;i<length;i++){
        switch (str[i])
        {
        case 'U':
            x-=1;
            break;
        case 'D':
            x+=1;
            break;
        case 'L':
            y-=1;
            break;
        case 'R':
            y+=1;
            break;
        }
    }
}

int main(){
    
    int x = 0, y = 0;

    char str[MAX];
    cin>>str;

    int slen = strlen(str);
    func(str,x,y,slen);

    cout<<x<<" "<<y<<endl;

    return 0;
}