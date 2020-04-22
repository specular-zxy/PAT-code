#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int l = 35;
int r = 2;
bool error = false;
int charge(char a[], int radix) {
    int num = 0;
    int len = strlen(a);
    char c;
    for (int i = 0; i < len; i++) {
        c = a[len - i - 1];
        if (c >= '0' && c <= '9') {
            num += (c - '0') * pow(radix, i);
        }else if (c >= 'a' && c <= 'z') {
            if (radix < (c - 'a' + 10)){error  = true; return -1;}
            num += (c - 'a' + 10) * pow(radix, i);
        }
    }
    return num;
}
int binarysearch(int key, char b[]){
    int mid = (l + r) / 2;
    int ret = charge(b, mid);

    while (ret != key) {
        if (ret > mid) l = mid - 1;
        else if (ret < mid) r = mid + 1;
        mid = (l + r) / 2;
        ret = charge(b, mid);
        if (ret == -1)
            return -1;
    }

    return mid;
}

int main() {
    char n1[12] = "0";
    char n2[12] = "0";
    int tag, radix;
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    int num;
    int result;
    if (tag == 1) {                  // radix is for n1
        num = charge(n1, radix);
        result = binarysearch(num, n2);
    } else if (tag == 2) {           // radix is for n2
        num = charge(n2, radix);
        result = binarysearch(num, n1);
    }

    if (result == -1 && error) {
        printf("Impossible\n");
    } else
        printf("%d", result);

    return 0;
}
