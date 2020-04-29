#include <stdio.h>
const int maxn = 111111;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime() {
    for (int i = 2; i < maxn; i++) {
        if (!p[i]) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;      // true意味着，不是素数。
            }
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Find_Prime();
    int count = 0;
    for (int i = n - 1; i < m; i++) {
        printf("%d", prime[i]);
        count++;
        if (count % 10 == 0)    printf("\n");
        else if (i != m - 1)    printf(" ");
    }
    return 0;
}