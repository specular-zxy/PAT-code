// 麻烦最大值写一个 0x3fffffff,这样才是很大很大的数
#include <iostream>
#include <algorithm>
using namespace std;
int num[100010];
int leftmax[100010];
int rightmin[100010];
int result[1000010];

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    leftmax[0] = 0;
    for (int i = 1; i < n; i++) {
        leftmax[i] = max(num[i - 1], leftmax[i - 1]);
    }
    rightmin[n - 1] = 0x3fffffff;
    for (int i = n - 2; i >= 0; i--) {
        rightmin[i] = min(rightmin[i + 1], num[i + 1]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] > leftmax[i] && num[i] < rightmin[i]) {
            result[count++] = num[i];
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        if (i != count - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
