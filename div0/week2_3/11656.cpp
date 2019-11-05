#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 10000;

int main(){
    string str[MAX];
    cin >> str[0];

    int len = str[0].size();

    for (int i = 1; i < len; i++){
        str[i] = str[0].substr(i);
    }
    sort(str, str + len);
    for (int i = 0; i < len; i++){
        cout << str[i] << endl;
    }
}
