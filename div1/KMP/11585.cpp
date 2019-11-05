#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2000100;

char T[MAX], S[MAX];
int M, N, fail[MAX];

void constructFail(){
    int p = 0;
    for (int i = 1; i < M; i++) {
        while (p > 0 && T[i] != T[p]) p = fail[p];
        if (T[i] == T[p]) p++;
        fail[i + 1] = p;
    }
}

void KMPalgorithm(int* match){
    int p = 0;
    for (int i = 0; i < N; i++){
        while (p > 0 && S[i] != T[p]) p = fail[p];
        if (S[i] == T[p]) p++;
        if (p == M) (*match)++;
    }
}

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int cnt;
    scanf("%d%*c", &cnt);

    for (int i = 0; i < cnt; i++){
        scanf("%c%*c", &S[i]);
    }
    for (int i = 0; i < cnt; i++){
        scanf("%c%*c", &T[i]);
    }

    M = strlen(T);
    strncat(S, S, M - 1);

    N = strlen(S);

    int match = 0;
    constructFail();
    KMPalgorithm(&match);

    int a = match, b = cnt;
    int tmpgcd = gcd(a, b);

    //for (int i = 0; i < N; i++) printf("%c", S[i]);
    //printf("\n");

    printf("%d/%d", a/tmpgcd, b/tmpgcd);

    return 0;
}