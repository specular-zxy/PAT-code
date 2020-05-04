#include <iostream>
#include <set>
using namespace std;
set<int> sett[50];
void cmpl(set<int> tmp, set<int> temp) {
    int nc = 0, nt = tmp.size();
    for (int i : temp) {
        if (tmp.find(i) == tmp.end()) {
            nt++;
        } else {
            nc++;
        }
    }
    float count = (float)nc / (float)nt;
    printf("%.1f%%\n",count * 100);
}
int main() {
    int n,k,len, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &temp);
            sett[i].insert(temp);
        }
    }
    scanf("%d", &k);
    int p1, p2;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p1, &p2);
        cmpl(sett[p1 - 1], sett[p2 - 1]);
    }
    return 0;
}
