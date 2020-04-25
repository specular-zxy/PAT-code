#include <iostream>
#include <algorithm>
using namespace std;
int origin[111], tempOri[111], changed[111];
int n;

bool issame(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void showArray(int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
}
bool insersort() {
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (i != 1 && issame(tempOri, changed)) {
            flag = true;
        }

        int tmp = tempOri[i], j = 1;
        while (j > 0 && tempOri[j - 1] > tmp) {
            tempOri[j] = tempOri[j - 1];
            j--;
        }
        tempOri[j] = tmp;
        if (flag == true)
            return true;
    }
    return false;
}

void mergesort() {
    bool flag = false;
    for (int step = 2; step /2 <= n; step *= 2) {
        if (step != 2 && issame(tempOri, changed)) {
            flag = true;
        }

        for (int i = 0; i < n; i += step) {
            sort(tempOri + i, tempOri + min(i + step, n));
        }

        if (flag) {
            showArray(tempOri);
            return;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &changed[i]);
    }

    if (insersort()) {
        printf("Insertion Sort\n");
        showArray(tempOri);
    } else {
        printf("Merge Sort\n");
        for (int i = 0; i < n; i++)
            tempOri[i] = origin[i];
        mergesort();
    }
}