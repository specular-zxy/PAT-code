/* read the str
 * using array to build the tree
 * then for print the level order, then the in-order
 * todo can't find the right answer
 * */
#include <iostream>
#include <queue>
#define MAXN 10
using namespace std;
int levelo[MAXN], ino[MAXN], n;
struct node {
    int left = -1, right = -1;
}no[MAXN];
int flag[MAXN];
// something wrong with this
void init() {
    char n1, n2;
    string ci;
    for (int i = 0; i < MAXN; i++) {
        flag[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        getline(cin, ci);
        n1 = ci[0];
        n2 = ci[2];
        if (n1 != '-') {
            no[i].left = n1 - '0';
            flag[n1 - '0'] = 0;
        }
        if (n2 != '-') {
            no[i].right = n2 - '0';
            flag[n2 - '0'] = 0;
        }
    }
}
int findroot() {
    for (int i = 0; i < n; i++) {
        if(flag[i] == -1)
            return i;
    }
}
void level(int root) { // level
    queue<int> list;
    int k = 0;
    list.push(root);
    levelo[k++] = root;
    while (!list.empty()) {
        root = list.front();
        list.pop();
        if (no[root].left != -1) {
            list.push(no[root].left);
            levelo[k++] = no[root].left;
        }
        if (no[root].right != -1){
            list.push(no[root].right);
            levelo[k++] = no[root].right;
        }
    }
    printf("%d", levelo[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", levelo[i]);
    }
    printf("\n");
}
int count = 0;
void inor(int root) {
    if (root == -1) {
        return;
    }
    inor(no[root].left);
    ino[count++] = root;
    inor(no[root].right);
}
int main() {
    scanf("%d\n", &n);
    init();
    int root;
    root = findroot();
    level(root);
    inor(root);
    printf("%d", ino[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", ino[i]);
    }
    return 0;
}
