#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string a, b, ans;
    getline(cin, a);
    getline(cin,b);
    int len = b.length();
    bool flag = false;
    if (a.find("+") != string::npos) {
        flag = true;
    }

    for (int i = 0; i < len; i++){
        if (a.find(toupper(b[i])) != string::npos) continue;
        if (isupper(b[i]) && flag) continue;
        ans += b[i];
    }

    cout << ans;
    return 0;
}
