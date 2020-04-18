// 使用hashmap的格式，通过数组索引存储硬币数目，然后直接查看是否有对应的两个硬币
// 0 代表没有， n 代表有n个
#include <iostream>

using namespace std;

int main() {
    int n, m, tmp;
    int coin[10001];
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        coin[tmp]++;
    }

    for (int i =0; i < 10001; i++) {
        if(coin[i]) {
            coin[i]--;
            if ( m > i && coin[m - i]) {
                printf("%d %d", coin[i], coin[m-i]);
                return 0;
            }
            coin[i]++;
        }
    }

    printf("No Solution");
    return 0;
}
