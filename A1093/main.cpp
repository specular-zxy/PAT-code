#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int count_t = 0, count_p = 0;
    for (char i : str) {
        if (i == 'T')
            count_t++;
    }
    long ans = 0;
    for (char i : str) {
        if (i == 'P')   count_p++;
        else if (i == 'T') count_t--;
        else if (i == 'A') ans = (ans + count_t * count_p) % 1000000007;
    }
    cout << ans;
    return 0;
}
