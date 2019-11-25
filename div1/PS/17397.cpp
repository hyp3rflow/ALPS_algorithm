// n번째 날에 얼마를 추가해야 하는지는 2차원 dp만으로는 알 수 없다.
// 전날 사용한 금액을 추가해서 3차원 dp로 해결한다.

// dp(n, m, c) -> n번째 날자에 c만원을 지출하고 m만원이 남았을 때 1~n 가능한 최소 박탈감
// dp(n, m, c) = dp(n-1, m+c, i : 0 ~ 10-a[n])

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, dp[1010][200][200];
int arr[1010];

int main(){
    scanf("%d %d%*c", &N, &M);

    for(int i=0; i<N; i++){
        scanf(" %d", arr[i]);
    }
}