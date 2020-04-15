#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string a,b;
    getline(cin, a);
    getline(cin,b);

    map<char, int> an;
    for (char & i : b) {
        if (an[i] == 0) {
            an[i] = 1;
        } else an[i]++;
    }

    int extra = 0;
    for (int i = 0; i < a.length(); i++) {
        if (an[a[i]] != 0) {  // 找到一个数值 - 1
            an[a[i]]--;
        } else {
            extra += 1;
        } // 冗余的 + 1
    }

    int need = 0;
    for (auto it : an) {
        if (it.second != 0) {
            need += it.second;
        }
    }

    if (need != 0) {
        cout << "No" << " " << need;
    } else {
        cout << "Yes" << " " << extra;
    }

    return 0;
}
