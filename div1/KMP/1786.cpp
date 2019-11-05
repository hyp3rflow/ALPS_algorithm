#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000100;

char T[MAX], S[MAX];
int M, N, fail[MAX], arr[MAX];

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
        if (p == M){
            arr[(*match)] = i - p + 2;
            (*match)++;
        }
    }
}

int main(){
    scanf("%[^\n]%*c", S);
    scanf("%[^\n]%*c", T);

    N = strlen(S);
    M = strlen(T);

    int count = 0;
    constructFail();
    KMPalgorithm(&count);

    printf("%d\n", count);

    for (int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}