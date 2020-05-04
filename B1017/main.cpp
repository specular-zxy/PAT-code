#include <iostream>
using namespace std;
typedef struct {
    int d[1000] = {0};
    int len = 0;
}bign;
void div(bign a, int b) {
    int bediv = 0;
    int r = 0;
    bign c;
    for (int i = 0; i < a.len; i++) {
        if (bediv == 0) {
            bediv = a.d[i];
        } else  {
            bediv = bediv * 10 + a.d[i];
        }

        r = bediv /b;
        bediv = bediv % b;
        c.d[c.len++] = r;
    }

    int index = 0;
    for (int i = 0; i < c.len; i++) {
        if (c.d[i] != 0 ){
            index = i;
            break;
        }
    }
    for (index; index < c.len; index++) {
        printf("%d", c.d[index]);
    }
    printf(" %d", bediv);
}
int main() {
    bign inp;
    string str;
    int t;
    cin >> str >> t;
    for (char i : str) {
        inp.d[inp.len++] = i - '0';
    }
    div(inp, t);
    return 0;
}
