// todo 一直有一个测试点通不过呀！！！
#include <iostream>
using namespace std;
typedef struct {
    int p = -1,k = 0;
}node;
const int maxn = 111111;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime() {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;      // true意味着，不是素数。
            }
        }
    }
}

int main() {
    Find_Prime();
    int n, m;
    node list[10];
    cin >> n;
    m = n;
    node tmp;   int nNum = 0, temp, count;
    for (int i = 0; i * i <= m; i++) {
        if (n % prime[i] == 0) {
            temp = prime[i];
            count = 0;
            do{
                n = n / temp;
                count++;
            }while (n%temp == 0);
            tmp.p = temp;
            tmp.k = count;
            list[nNum++] = tmp;
        }
        if (n == 1) break;
    }

    printf("%d=", m);
    if (n != 1) {
        tmp.p = n;
        tmp.k = 1;
        list[nNum++] = tmp;
    }

    for (int i = 0; i < nNum; i++) {
        if (list[i].k == 1) {
            printf("%d",list[i].p);
        } else {
            printf("%d^%d", list[i].p, list[i].k);
        }
        if (i != nNum - 1)  printf("*");
    }
    return 0;
}
