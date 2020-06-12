#include <iostream>
#include <queue>
#define MAXN 30
using namespace std;
struct node{
    int value;
    node *left;
    node *right;
};
typedef struct node Node ;
int postorder[MAXN];
int inorder[MAXN];
int n;
node* convert(int postl, int postr, int inl, int inr) {
    if (postl > postr) {
        return nullptr;
    }
    node* root = new node;
    root->value = postorder[postr];
    int k;
    for (k = inl; k <= inr; k++) {
        if (inorder[k] == postorder[postr])
            break;
    }
    int numleft = k - inl;
    root->left = convert(postl, postl + numleft - 1, inl, k - 1);
    root->right = convert(postl + numleft, postr - 1, k + 1, inr);
    return root;
}
void bfs(node* root) {
    queue<node*> list;
    int level[MAXN];
    node* tmp = root;
    int k = 0;
    level[k++] = tmp->value;
    list.push(tmp);
    while (!list.empty()) {
        tmp = list.front();
        list.pop();
        if (tmp->left != nullptr) {
            level[k++] = tmp->left->value;
            list.push(tmp->left);
        }
        if (tmp->right != nullptr) {
            level[k++] = tmp->right->value;
            list.push(tmp->right);
        }
    }
    printf("%d", level[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", level[i]);
    }
}
int main() {
    node *root = (node*)malloc(sizeof(node));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    root = convert(0, n - 1 , 0, n - 1);
    bfs(root);
    return 0;
}
