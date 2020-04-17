#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    for (string::iterator i = s1.begin(); i != s1.end(); i++){
        if (s2.find(*i) == string::npos) {
            printf("%c", *i);
        }
    }

    return 0;
}
