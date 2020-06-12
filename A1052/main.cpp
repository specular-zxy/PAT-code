// todo 21 分，还差4分
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {
    int position;
    int value;
    int next;
}list;
list node[100005];
bool cmp(list a, list b) {
    return a.value < b.value;
}
int main() {
    int n, first, rn = 0;
    scanf("%d %d", &n, &first);
    int tp, tv, tn;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tp, &tv, &tn);
        node[tp].position = tp;
        node[tp].value = tv;
        node[tp].next = tn;
    }
    vector<list> l;
    int p = first;
    for (int i = 0; i < n; i++) {
        l.push_back(node[p]);
        p = node[p].next;
        rn++;
    }
    if (rn == 0) {
        printf("0 -1\n");
    } else {
        sort(l.begin(), l.end(), cmp);
        for (int i = 0; i < n - 1; i++) {
            l[i].next = l[i + 1].position;
        }
        l[n - 1].next = -1;
        printf("%d %05d\n", rn, l[0].position);
        for (auto i : l) {
            if (i.next == -1) {
                printf("%05d %d %d\n", i.position, i.value, i.next);
            } else {
                printf("%05d %d %05d\n", i.position, i.value, i.next);
            }
        }
    }
    return 0;
}
