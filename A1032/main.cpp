#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct {
    char value = ' ';
    int next = -1;
}letter[100005];

int main() {
    int f1, f2, num;
    int ti, tn;
    char tv;
    scanf("%d %d %d", &f1, &f2, &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %c %d", &ti, &tv, &tn);
        letter[ti].value = tv;
        letter[ti].next = tn;
    }
    // find sublist, using string to find
    string s1, s2;
    vector<int> in1, in2;
    // convert link to string
    while (f1 != -1) {
        s1 += letter[f1].value;
        in1.push_back(f1);
        f1 = letter[f1].next;
    }
    while (f2 != -1) {
        s2 += letter[f2].value;
        in2.push_back(f2);
        f2 = letter[f2].next;
    }
    // to find
    int index1 = s1.length() - 1;
    int index2 = s2.length() - 1;
    while(index1 >= 0 && index2 >= 0) {
        if (s1[index1] == s2[index2]) {
            index1--; index2--;
        } else {
            index1++; index2++;
            break;
        }
    }

    if (index1 == s1.length()) {
        cout << -1;
    } else {
        printf("%05d", in1[index1]);
    }

    return 0;
}
