#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 2000 + 10;
int N, M, S, E, arr[MAX], dp[MAX][MAX];

void constructDP() {
    for (int i = 0; i < N; i++){
        dp[i][i] = 1;
    }

    for (int i = 0; i < N - 1; i++){
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }

    for (int size = 2; size < N; size++){
        for (int j = 0; j+size < N; j++){
            dp[j][j + size] = dp[j + 1][j + size - 1] && (arr[j+size] == arr[j]);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf(" %d", &arr[i]);

    // dp
    // initialize
    constructDP();

/*
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
*/

    scanf("%d", &M);
    for (int j = 0; j < M; j++) {
        scanf(" %d %d", &S, &E);
        printf("%d\n", dp[S - 1][E - 1]);
    }
}