#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> grade(101);
    scanf("%d", &n);

    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        grade[tmp] += 1;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        if (i != 0) printf(" %d", grade[tmp]);
        else printf("%d", grade[tmp]);
    }

    return 0;
}
