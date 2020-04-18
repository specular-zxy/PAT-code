#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    float store;
    float price = 0;
    float rank;
} node;

vector<node> list;

bool cmp(node a, node b){
    return a.rank > b.rank;
}
int main() {
    int n, m;
    cin >> n >> m;
    list.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &list[i].store);
    }
    for (int i = 0; i < n; i++) {
        scanf("%f", &list[i].price);
        list[i].rank = list[i].price / list[i].store;
    }

    sort(list.begin(), list.end(), cmp);

    float total = 0.0;
    for (auto i : list) {
        if (m == 0) {
            break;
        }

        if (i.store > m) {  // 库存大于总数
            total += m * i.rank;
            m = 0;
        } else {  // 库存小于总数
            m -= i.store;
            total += i.store * i.rank;
        }
    }

    printf("%.2f", total);
    return 0;
}
