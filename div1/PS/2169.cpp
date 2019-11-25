// 로봇 조종하기
// dp(i, j) -> i, j 칸에서 n, n까지 갈 때 최대 가치의 합

#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1e6;
int N, M, arr[1010][1010], dp[1010][1010][3];

int x_diff[3] = {1, -1, 0};
int y_diff[3] = {0, 0, 1};

int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf(" %d", &arr[i][j]);
    
}