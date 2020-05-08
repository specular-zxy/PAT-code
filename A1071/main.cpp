#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    string str, tmp;
    getline(cin, str);
    int index = 0, left = 0, len = 0;
    map<string, int> list;
    for (char &i : str) {
        if (isalnum(i)) {
            len++;
            if (isupper(i))
                i = tolower(i);
        }
        else if (len == 0) {
            left = index + 1;
        }
        else {
            tmp = str.substr(left, len);
            if (!(tmp[0] >= '0' && tmp[0] <= '9'))
                list[tmp]++;

            left = index + 1;
            len = 0;

        }
        index++;
    }
    int max = 0;
    string key;
    for (auto i : list) {
        if (i.second > max) {
            key = i.first;
            max = i.second;
        } else if (i.second == max) {
            if (key < i.first) {
                key = i.first;
            } else
                continue;
        }
    }
    cout << key << " " << max;
    return 0;
}
