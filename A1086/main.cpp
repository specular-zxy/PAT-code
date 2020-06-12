/* preorder: push func
 * inorder: pop func
 * using both to build the tree
 * and then postoutput it
 * or: just using the stack, haven't find the right method
 * */
#include <iostream>
#include <stack>
#include <string>
#define MAXN 30
using namespace std;
struct node {
    int value;
    node* left;
    node* right;
};
int pre[MAXN], in[MAXN], post[MAXN];
int n;
stack<int> list;
void init() {
    string ci, check;
    int len, num, n2, k1 = 0, k2 = 0;
    n2 = n * 2;
    for (int i = 0; i < n2; i++) {
//        cin >> ci;
        getline(cin, ci);
        if (ci.length() == 3) {
            in[k2++] = list.top();
            list.pop();
        } else {
            len = ci.length() - 4;
            check = ci.substr(5, len);
            num = stoi(check);
            list.push(num);
            pre[k1++] = num;
        }
    }
}
node* convert(int prel, int prer, int inl, int inr) {
    if (prel > prer) {
        return nullptr;
    }
    node* root = (node *)malloc(sizeof(node));
    root->value = pre[prel];
    int k;
    for (k = inl; k < inr; k++) {
        if (pre[prel] == in[k])
            break;
    }
    int numleft = k - inl; // mean
    root->left = convert(prel + 1, prel + numleft, inl, k - 1);
    root->right = convert(prel + numleft + 1, prer, k + 1, inr);
    return root;
}
int k3 = 0;
void posto(node* root) {
    if (root == nullptr)
        return;
    posto(root->left);
    posto(root->right);
    post[k3++] = root->value;
    return;
}
int main() {
    node* root = (node *)malloc(sizeof(node));
    scanf("%d\n", &n);
    init();
    root = convert(0, n - 1, 0, n - 1);
    posto(root);
    printf("%d", post[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", post[i]);
    }
    return 0;
}
