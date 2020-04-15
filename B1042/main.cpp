#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int main() {
    string a;
    getline(cin,a);

    map<char, int> an;
    char index = '*';
    bool flag = true;
    for (char i : a) {
        if (i >= 'a' && i <= 'z') {
            index = i;
        } else if (i >= 'A' && i <= 'Z') {
            index = tolower(i);
        } else flag = false;

        if (!flag) {
            flag = true;
            continue;
        }

        if (an[index] == 0) an[index] = 1;
        else an[index]++;
    }


    int max = 0;
    char maxn;

    for (auto i : an) {
        if (i.second > max) {
            max = i.second;
            maxn = i.first;
        }
    }
    cout << maxn << " " << max;

    return 0;
}
