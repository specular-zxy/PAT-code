#include <iostream>
#include <queue>
using namespace std;
struct {
    int weight;
    int rank;
}mice[1010];
int main() {
    int np, ng;
    cin >> np >> ng;
    for(int i = 0; i < np; i++) {
        scanf("%d", &mice[i].weight);
    }
    queue<int> q;
    int order;
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int tmp = np, group;
    while(q.size() != 1) {
        if (tmp % ng == 0) group = tmp / ng;
        else group = tmp / ng + 1;
        for (int i = 0; i < group; i++) {
            int k = q.front();
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= tmp) break;
                int front = q.front();
                if (mice[front].weight > mice[k].weight) {
                    k = front;
                }
                mice[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        tmp = group;
    }

    mice[q.front()].rank = 1;
    for (int i = 0; i < np; i++) {
        printf("%d", mice[i].rank);
        if (i < np - 1) printf(" ");
    }

    return 0;
}
