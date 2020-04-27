// 自己写的，总有一个测试点通不过
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    return a > b;
}
int main() {
    int n1,n2;
    int length = 0;
    cin >> n1;
    string str1, str2;
    while (n1 != 6174 && n1 != 0){
        str1 = to_string(n1);
        length = str1.length();
        if (length < 4){
            str1.clear();
            for (int i = 0; i < 4 - length; i++) {
                str1 += '0';
            }
            str1 += to_string(n1);
        }

        str2 = str1;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end(), cmp);
        n1 = stoi(str1);
        n2 = stoi(str2);
        n1 = n2 - n1;
        printf("%s - %s = %04d\n", str2.c_str(), str1.c_str(), n1);
    }

    return 0;
}
