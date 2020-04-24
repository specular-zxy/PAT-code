#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

// 进制转换
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}

// 查找
long long find_radix(string n, long long num) {    //num -> radix
    char it = *max_element(n.begin(), n.end());
    // low 和 high 的确定十分重要，low为字符串里最大的那个数，而 high 为 num(radix) 与 low 中较大的那个值。
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {                         // 二分查找
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;    // t = convert number        // t < 0 是什么情况？
        else if (t == num) return mid;           // 找到了
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag , radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = (tag == 1) ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }
    return 0;
}