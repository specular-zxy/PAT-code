// 关键点在于： coupon 不需要用完，而product也不需要被买完。
// 我们只需要找出最大值就可以了
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int nc, np;
    vector<int> coup;
    vector<int> prod;
    scanf("%d", &nc);
    coup.resize(nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &coup[i]);
    }
    scanf("%d", &np);
    prod.resize(np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &prod[i]);
    }

    sort(coup.begin(), coup.end());
    sort(prod.begin(), prod.end());

    int result = 0;
    int i = 0, j = 0;
    while (i < nc && j < np && coup[i] < 0 && prod[j] < 0 ) {
        result += coup[i] * prod[j];
        i++; j++;
    }
    i = nc - 1;
    j = np - 1;
    while (i >= 0 && j>= 0 && coup[i] > 0 && prod[j] > 0) {
        result += coup[i] * prod[j];
        i--; j--;
    }

    printf("%d\n", result);
    return 0;
}
