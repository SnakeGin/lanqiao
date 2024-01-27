//统计子矩阵
//统计二维前缀和+双指针
/*  如果l-r区间的值大于k
    那么l指针左移（边界）
    不过不大于k
    那么r指针右移，直到到达边界
    并且在l指针达到边界时，统计满足题意的个数
    重复此步骤，知道遍历完整个矩阵
    此算法的时间复杂度为O(n^3);
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, k;
long long res;
int arr[520][520];
int sum[520][520];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
            sum[i][j] = arr[i][j] + sum[i][(j - 1)];
    }//统计二维前缀和

    for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j++){//双指针
            int l, r, temp;
            l = r = temp = 0;
            for (r = 1; r <= n; r++) {
                temp += sum[r][j] - sum[r][i - 1];
                while (temp>k){
                    l++;
                    temp -= sum[l][j] - sum[l][i - 1];
                }
                res += r - l;
            }
        }
    cout << res;
    return 0;
}