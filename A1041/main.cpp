#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    string str;
    map<string, int> list;
    vector<string> l;
    for (int i = 0; i < n; i++){
        cin >> str;
        l.push_back(str);
        if (list[str] == 0) list[str] = 1;
        else list[str] += 1;
    }

    for (auto &i : l) {
        if (list[i] == 1){
            cout << i;
            return 0;
        }
    }

    cout << "None";
    return 0;
}
