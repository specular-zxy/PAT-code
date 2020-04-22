#include <iostream>
#include <algorithm>
using namespace std;
int num[10010] = {0};
int n,p;

int binarysearch(int i, long long x) {
    if (num[n - 1] <= x) {
        return n;
    }
    int l = i + 1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r)/2;
        if (num[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}
int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    sort(num, num+n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = binarysearch(i, (long long)num[i] * p);
        ans = max(ans, j-i);
    }

    printf("%d\n",ans);
    return 0;
}
