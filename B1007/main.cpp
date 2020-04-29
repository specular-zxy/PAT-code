#include <cstdio>
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
    Find_Prime();
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i < pNum; i++) {
        if (prime[i] > n)
            break;
        else {
            if (prime[i] - prime[i - 1] == 2)
                count++;
        }
    }
    printf("%d\n", count);
    return 0;
}