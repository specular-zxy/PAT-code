#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        a[t] = i;
    } // 不一样的存储方式，a[t] = i ,意为 t 的输入顺序是i；
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    } // 不一样的存储方式，导致我无法较好地理解其算法思路。
    cout << cnt;
    return 0;
}