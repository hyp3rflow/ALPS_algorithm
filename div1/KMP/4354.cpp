#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000000;

char T[MAX], S[MAX];
int M, N, fail[MAX];

void constructFail() {
    int p = 0;
    for (int i = 1; i < M; i++) {
        while (p > 0 && T[i] != T[p]) p = fail[p];
        if (T[i] == T[p]) p++;
        fail[i + 1] = p;
    }
}

void KMPalgorithm(int* match) {
    int p = 0;
    for (int i = 0; i < N; i++) {
        while (p > 0 && S[i] != T[p]) p = fail[p];
        if (S[i] == T[p]) p++;
        if (p == M) (*match)++;
    }
}

int main() {
    // scanf("%[^\n]%*c", S);
    // N = strlen(S);

    while (true) {
        scanf("%[^\n]%*c", T);
    
        if (T[0] == '.') break;

        M = strlen(T);

        constructFail();
        
        // fail function traversal
        int cnt = 1;
        int ind = M;
        int size = M - fail[M];

        if(fail[M] && !(fail[M]%size)){
            cnt = fail[M] / size + 1;
        }

        printf("%d\n", cnt);
    }

    return 0;
}