#include <iostream>
using namespace std;

int main() {
    int n;
    double result = 0.00;
    double tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%lf", &tmp);
        if (i == 0 || i == n-1) {
            result += tmp * n;
        } else {
            result += tmp * (i + 1) * (n - i);
        }
    }

    printf("%.2lf", result);
    return 0;
}
