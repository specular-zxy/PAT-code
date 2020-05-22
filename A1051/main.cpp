// 通过不了测试。。。
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, m, num;
int main() {
    stack<int> list;
    vector<int> l;
    cin >> num >> m >> n;
    int index, tmp, flag = 0;
    for (int i = 0; i < num; i++) {
        l.clear();  index = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &tmp);
            l.push_back(tmp);
        }
        for (int k = 1; k <= m; k++) {
            list.push(k);
            if (list.size() > n) {
                flag = 1;
                break;
            }
            while (!list.empty() && list.top() == l[index]) {
                list.pop();
                index++;
            }
        }
        if (flag == 0 && list.empty()){
            printf("Yes\n");
            flag = 0;
        } else printf("No\n");
        while(!list.empty()) {
            list.pop();
        }
        flag = 0;
    }
    return 0;
}
