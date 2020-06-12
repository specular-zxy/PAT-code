// todo 23分，有一个段错误
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int n, first;
struct {
    int value;
    int next;
}node[100005];
map<int, int> flag;
int main() {
    scanf("%d %d", &first, &n);
    int tp, tv, tn;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tp, &tv, &tn);
        node[tp].value = tv;
        node[tp].next = tn;
    }
    // deduplication
    int pre, p = first, nf = -1, next, tmp;
    while (p != -1) {
        tmp = fabs(node[p].value);
        if (flag[tmp] == 0) {
            flag[tmp] = 1;
            pre = p;
            p = node[p].next;
        } else {
            // 尾插法延伸新链条
            if (nf == -1) {
                nf = p;
                next = nf;
            } else {
                node[next].next = p;
                next = p;
            }
            node[pre].next = node[p].next;
            p = node[p].next;
            node[next].next = -1;
        }
    }
    node[next].next = -1;
    while (first != -1) {
        printf("%05d %d", first, node[first].value);
        if (node[first].next == -1)
            printf(" -1\n");
        else printf(" %05d\n", node[first].next);
        first = node[first].next;
    }
    while (nf != -1) {
        if (node[nf].next == -1)
            printf("%05d %d -1\n", nf, node[nf].value);
        else
            printf("%05d %d %05d\n", nf, node[nf].value, node[nf].next);
        nf = node[nf].next;
    }
    return 0;
}
