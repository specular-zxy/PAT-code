#include <iostream>
 #include<bits/stdc++.h>
using namespace std;

bool judge(string a) {
    int len = a.length();
    // 0 1 2 3 4 5 6 7 8
    for (int i = 0; i < len/2; i++) {
        if (a[i] != a[len - i - 1]) return false;
    }
    return true;
}
int main() {
    string a, b, c;
    int i, step, len, r, catchin = 0;
    cin >> a >> step;
    for (i = 0; i < step; i++) {
        if (judge(a)) break;
        len = a.length(); b = a;
        reverse(b.begin(), b.end());
        c.clear();
        catchin = 0;
        for (int j = 0; j < len; j++) {
            r = a[j] + b[j] - '0' - '0' + catchin;
            catchin = r / 10;
            r = r % 10;
            c.append(to_string(r));
        }
        if (catchin != 0) c.append(to_string(catchin));
        a = c;
        reverse(a.begin(), a.end());
    }

    if (judge(a)){
        cout << a << endl;
        cout << i << endl;
    } else {
        cout << a << endl;
        cout << step << endl;
    }
    return 0;
}