#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    string a;
    getline(cin,a);
    map<char,int> an;
    string b = "PATest";

    int length = 0;
    for (char i : a) {
        if (b.find(i) != string::npos)
            an[i] += 1;
            length += 1;
    }

    for (int i = 0; i < length; i++){
        if (an['P']-- > 0) cout << 'P';
        if (an['A']-- > 0) cout << 'A';
        if (an['T']-- > 0) cout << 'T';
        if (an['e']-- > 0) cout << 'e';
        if (an['s']-- > 0) cout << 's';
        if (an['t']-- > 0) cout << 't';
    }

    return 0;
}
