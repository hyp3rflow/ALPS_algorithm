#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000000;

int main(){
    char W[MAX + 1], S[MAX + 1];
    int M, N;
    gets(S);
    gets(W);
    N = strlen(S);
    M - strlen(W);

    int fail[MAX] = {0};
    for (int i = 1, j = 0; i < M; i++){
        while (j > 0 && W[i] != W[j]) j = fail[j - 1];
        if(W[])
    }

    vector<int> result;
    for (int i = 0, j = 0; i < N; i++){
        while (j > 0 && S[i] != W[j]) j = fail[j- 1];
        if(S[i] == W[j]){
            if(j == M-1){
                result.push_back(i - M + 1);
                j = fail[j];
            }
            else
                j++;
        }
    }
}