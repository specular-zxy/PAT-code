#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

typedef struct {
    char name[12];
    char ID[12];
    int grade = 0;
}node;

bool cmp(node a, node b){
    return a.grade > b.grade;
}

int main() {
    vector<node> list;
    int n,min,max;
    scanf("%d", &n);

    list.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%s %s %d", list[i].name, list[i].ID, &list[i].grade);
    }
    scanf("%d %d", &min, &max);

    bool flag = false;
    sort(list.begin(), list.end(), cmp);

    for (auto i: list){
        if (i.grade >= min && i.grade <= max){
            printf("%s %s\n", i.name, i.ID);
            flag = true;
        }
    }

    if(!flag) printf("NONE\n");

    return 0;
}
