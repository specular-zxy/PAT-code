#include <iostream>
#include <string>
using namespace std;
typedef struct {
    int d[30] = {0};
    int len = 0;
}bign;
bign a;
int ca[10] = {0};
int cb[10] = {0};
int main() {
    string sa, sb;
    cin >> sa;
    for (char i : sa) {a.d[a.len++] = i - '0';  ca[i - '0']++;}
    // multiply
    int index, catchin = 0, r;
    for (int i = a.len - 1; i >= 0; i--) {
        r = a.d[i] * 2 + catchin;
        if (r >= 10) {catchin = 1; r = r - 10;}
        else {catchin = 0;}
        cb[r]++;
        sb.append(to_string(r));
    }
    while(catchin != 0) {   // 注意考虑多位进位的情况。
        sb.append(to_string(catchin % 10));
        catchin /= 10;
    }
    //cmp
    for (index = 0; index < 10; index++) {
        if (ca[index] != cb[index]) break;
    }
    if (index == 10)    printf("Yes\n");
    else printf("No\n");
    for (index = sb.length() - 1; index >= 0; index--) {
        if (sb[index] != '0')   break;
    }
    for (index; index >= 0; index--) {
        printf("%c", sb[index]);
    }
    return 0;
}
