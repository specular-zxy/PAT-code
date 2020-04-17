#include <iostream>
#include <map>

using namespace std;
int main() {
    int n;
    cin >> n;

    int num, id, grade;
    map<int, int> list;

    for (int i = 0; i < n; i++) {
        scanf("%d-%d %d", &num, &id, &grade);
        list[num] += grade;
    }

    int maxn, max = -1;

    for (auto i : list) {
        if (i.second > max) {
            max = i.second;
            maxn = i.first;
        }
    }

    printf("%d %d", maxn, max);
    return 0;
}
