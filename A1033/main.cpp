#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

typedef struct {
    double price,dis;
}node;

node list[maxn];

bool cmp(node a, node b) {
    return a.dis < b.dis;
}

int main() {
    int n;
    double Cmax, D, Davg;
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &list[i].price, &list[i].dis);
    }

    list[n].price = 0;    // 数组最后加一组 node
    list[n].dis = D;

    sort(list, list + n, cmp);

    if (list[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
    } else {
        int now = 0;    // 当前编号
        double expens = 0, nowTank = 0, MAX = Cmax * Davg;   // 花费， 当前油量， 最长距离
        while (now < n) {         // 通过油站来记录距离
            int k = -1;
            double minprice = INF;
            for (int i = now + 1; i <= n && list[i].dis - list[now].dis <= MAX; i++ ) {
                if (list[i].price < minprice) {    // strategy one : 小于当前值并且最近
                    minprice = list[i].price;
                    k = i;

                    if (minprice < list[now].price) break;   // minprice 小于当前的price，直接跳出
                } // 等找完所有的并选出一个最小值，再跳出。
            }

            if (k == -1) break;   // k == -1 找不到，输出“最长距离”

            double need = (list[k].dis - list[now].dis) / Davg;    // need 为从 now 到 k 的油量

            if (minprice < list[now].price) {   // 小于当前的price；
                if (nowTank < need) {           // 油量不够，加点油
                    expens += (need - nowTank) * list[now].price;
                    nowTank = 0;
                } else {                        // 油量够，直接相减
                    nowTank -= need;
                }
            } else {                           // 当前能到达的最小值
                expens += (Cmax - nowTank) * list[now].price;
                nowTank = Cmax - need;
            }

            now = k;
        }

        if (now == n)                            // 能到达， 输出总花费
            printf("%.2f\n", expens);
        else                                     // 不能到达， 输出最远距离
            printf("Tha maximum travel distance = %.2f\n", list[now].dis + MAX);
    }


    return 0;
}
