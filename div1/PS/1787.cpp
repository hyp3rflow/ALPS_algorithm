#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1e9;
int N, M, check;

int fail[MAX];
char S[MAX], T[MAX];

void constructFail(){
    int p = 0;
    for(int i=1; i<M; i++){
        while(p > 0 && T[i] != T[p]) p = fail[p];
        if(T[i] == T[p]) p++;
        fail[i+1] = p;
    }
}

void KMPalgorithm(){
    int p = 0;
    for(int i=0; i<N; i++){
        while(p > 0 && S[i] != T[p]) p = fail[p];
        if(S[i] == T[p]) p++;
        if(p == N) check++;
    }
}

int main(){
    /*
    while(true){
        scanf("%[^\n]%*c", T);
        M = strlen(T);
        constructFail();
        for(int i=0; i<=M; i++) printf("%d ", fail[i]);
        printf("\n");
    }
    */
}
