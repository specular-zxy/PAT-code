#include <iostream>
#include <cstdio>
using namespace::std;

int main() {
    int n,shift;
    int N[100];

    cin >>n >> shift;
    shift = shift%n;

    for(int i = 0 ; i < n ; i++){
        cin >> N[i];
    }

    for(int i = 0; i<shift; i++){
        printf("%d ",N[n - shift + i]);
    }

    for(int i = 0; i < n-shift; i++){
        if(i== n-shift-1){
            printf("%d",N[i]);
        }else printf("%d ",N[i]);
    }
    return 0;
}
