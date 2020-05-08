#include <iostream>
#include <string>
#include <map>
using namespace std;
string sma[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string hig[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> sm;
map<string, int> hi;
void initate() {
    sm["jan"] = 1; sm["feb"] = 2; sm["mar"] = 3;
    sm["apr"] = 4; sm["may"] = 5; sm["jun"] = 6;
    sm["jly"] = 7; sm["aug"] = 8; sm["sep"] = 9;
    sm["oct"] = 10; sm["nov"] = 11; sm["dec"] = 12;
    hi["tam"] = 1; hi["hel"] = 2; hi["maa"] = 3; hi["huh"] = 4;
    hi["tou"] = 5; hi["kes"] = 6; hi["hei"] = 7; hi["elo"] = 8;
    hi["syy"] = 9; hi["lok"] = 10; hi["mer"] = 11; hi["jou"] = 12;

}
void etom(string a) {
    int tmp, flag = 0;
    string str;
    tmp = stoi(a);
    if (tmp == 0) {
        printf("tret\n");
        return;
    } else if (tmp % 13 == 0) {
        cout << hig[tmp / 13 - 1] << endl;
        return;
    }
    while(tmp != 0) {
        if (flag == 0){
            str.insert(0, sma[tmp % 13 - 1]);
            flag = 1;
        } else {
            str.insert(0, hig[tmp % 13 - 1]);
            flag = 1;
        }
        tmp = tmp / 13;
        if (tmp != 0)
            str.insert(0, " ");
    }
    cout << str << endl;
}
void mtoe(string a) {
    string tmp;
    if (a.length() > 4) {
        tmp = a.substr(0, 3);
        int t1 = hi[tmp];
        tmp = a.substr(4, 3);
        int t2 = sm[tmp];
        printf("%d\n", t1 * 13 + t2);
    } else {
        if (hi.find(a) == hi.end()) {
            printf("%d\n", sm[a]);
        } else {
            printf("%d\n", hi[a] * 13);
        }
    }
}
int main() {
    initate();
    int n;
    string tmp;
    cin >> n;
    getchar();
    tmp = "29";
    for (int i = 0; i < n; i++) {
        getline(cin, tmp);
        if (tmp[0] >= '0' && tmp[0] <= '9') etom(tmp);
        else mtoe(tmp);
    }

    return 0;
}
