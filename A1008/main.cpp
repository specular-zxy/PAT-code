#include <iostream>
using namespace std;

int main() {
    int n, nextf, nowf = 0;
    int result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nextf);
        if (nextf > nowf) {
            result += (nextf - nowf) * 6;
        } else result += (nowf - nextf) * 4;
        nowf = nextf;
    }
    result += 5 * n;
    cout << result << endl;

    return 0;
}
