// 注意 up == 0 的时候
#include <iostream>
using namespace std;
typedef struct {
    int up = 0, down = 1;
}rati;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
rati reduction(rati node) {
    if (node.up == 0) node.down = 1;
    if (node.down < 0) {node.up = 0 - node.up; node.down = -node.down; }
    else {
        int t = gcd(node.up, node.down);
        node.up /= t;
        node.down /= t;
    }
    return node;
}
rati add(rati a, rati b) {
    rati c;
    c.down = a.down * b.down;
    c.up = a.down * b.up + a.up * b.down;
    c = reduction(c);
    return c;
}
int main() {
    int n;
    rati node, result;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &node.up, &node.down);
        result = add(result, node);
    }

    if (result.up == 0) {
        printf("0\n");
        return 0;
    }
    if (result.up > result.down) {
        int tmp = result.up / result.down;
        result.up = result.up % result.down;
        if (result.up == 0) {
            printf("%d\n", tmp);
        }
        else printf("%d %d/%d\n", tmp, result.up, result.down);
    } else printf("%d/%d\n", result.up, result.down);
    return 0;
}
