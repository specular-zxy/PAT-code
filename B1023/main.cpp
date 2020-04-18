#include <iostream>
using namespace std;

int number[10] = {0};

int main() {
    int sum = 0,tmp;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &tmp);
        number[i] = tmp;
        sum += tmp;
    }
    int count = 0;
    while (sum > 0) {
        if (count == 0) {
            for (int i = 1; i < 10; i++) {
                if (number[i] != 0) {
                    printf("%d", i);
                    number[i]--;
                    break;
                }
            }
        } else {
            for (int i = 0; i < 10; i++) {
                if (number[i] != 0) {
                    printf("%d", i);
                    number[i]--;
                    break;
                }
            }
        }
        count++;
        sum--;
    }
    return 0;
}
