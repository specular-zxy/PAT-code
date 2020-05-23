// comment 通不过最后一个，得分24
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct {
    int value;
    int next;
}node[100010];
int first, n, g;
void reverse(int front, int end) {
    int p = front;
    vector<int> next;
    next.push_back(p);
    while (p != end) {
        next.push_back(node[p].next);
        p = node[p].next;
    }
    next.push_back(node[p].next);
    node[next[0]].next = next[g];
    int tmp = next[0];
    for (int i = 1; i < g; i++) {
        node[next[i]].next = tmp;
        tmp = next[i];
    }
}
int main() {
    scanf("%d %d %d", &first, &n, &g);
    int po, tv, ne;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &po, &tv, &ne);
        node[po].value = tv;
        node[po].next = ne;
    }
    if (n >= g) {
        int count = n / g;
        int pre = first, p;
        int tmp = first;
        // 如果有循环，如何续上
        while (count != 0) {
            if (count != n / g) {
                tmp = pre;
                pre = node[pre].next;   // 下一个的开始
            }
            p = pre;
            for (int i = 0; i < g - 1; i++) {
                p = node[p].next;
            }
            reverse(pre, p);
            // reverse 之后 p 在前， pre 在后
            if (count == n / g) {   // 定下first
                first = p;
            } else {
                node[tmp].next = p;
            }

            count--;
        }
        p = first;
        for (int i = 0; i < n; i++) {
            printf("%05d %d ", p, node[p].value);
            if (node[p].next == -1)
                printf("%d\n", node[p].next);
            else
                printf("%05d\n", node[p].next);
            p = node[p].next;
        }
    } else {
        int p = first;
        for (int i = 0; i < n; i++) {
            printf("%05d %d ", p, node[p].value);
            if (node[p].next == -1)
                printf("%d\n", node[p].next);
            else
                printf("%05d\n", node[p].next);
            p = node[p].next;
        }
    }
    return 0;
}
