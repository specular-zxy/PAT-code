#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

typedef struct {
    char id[10];
    int time, flag = 0;
    // flag = 1, 表示in; flag = -1, 表示 off, 有助于计算某一时刻的车数量
}node;

vector<node> list;

bool cmp1(node a, node b){
    if (strcmp(a.id, b.id) != 0) return strcmp(a.id, b.id) < 0;
    else return a.time < b.time;
}

bool cmp2(node a, node b){
    return a.time < b.time;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    node tmp;
    int h,m,s;
    char state[5];

    // 处理输入内容
    for (int i = 0; i < n; i++){
        scanf("%s %d:%d:%d %s\n",tmp.id, &h, &m, &s, state);
        tmp.time = h * 3600 + m * 60 + s;
        tmp.flag = strcmp(state, "in") == 0 ? 1 : -1;
        list.push_back(tmp);
    }

    sort(list.begin(), list.end(), cmp1);

    vector<node> fixed;
    map<string, int> timemap;
    int maxtime = -1;

    // 完成 in and off 的配对工作
    for (int i = 0; i < n; i++){
        if(strcmp(list[i].id, list[i+1].id)== 0 && list[i].flag == 1 && list[i+1].flag == -1){
            fixed.push_back(list[i]);
            fixed.push_back(list[i+1]);
            timemap[list[i].id] += list[i+1].time - list[i].time;
            if(maxtime < timemap[list[i].id]){
                maxtime = timemap[list[i].id];
            }
        }
    }


    sort(fixed.begin(), fixed.end(), cmp2);
    vector<int> timesum(n);
    // counting time pre
    for (int i = 0; i < n; i++){
        if (i == 0){
            timesum[i] += fixed[i].flag;
        }
        else{
            timesum[i] += timesum[i-1] + fixed[i].flag;
        }
    }


    int index = 0;
    for (int i = 0; i < k; i++){
        scanf("%d:%d:%d", &h, &m, &s);
        int tmptime = h * 3600 + m * 60 + s;
        int j;
        for (j = index; j < fixed.size(); j++){
            if (fixed[j].time > tmptime){
                printf("%d\n", timesum[j - 1]);
                break;
            } else if (j == fixed.size() - 1){
                printf("%d\n", timesum[j]);
                break;
            }
        }
        index = j;
    }


    auto in = timemap.begin();
    for (in; in != timemap.end(); in++){
        if (in->second == maxtime){
            printf("%s ",in->first.c_str());
        }
    }

    printf("%d:%d:%d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}