#include <cstdio>
#include <algorithm>
#include <utility>
#define ll long long

using namespace std;

int a[1010][2];
ll dp[1010][1010];

int main(){
    int c;
    scanf("%d", &c);
    for(int i=0; i<c; i++) scanf(" %d %d", &a[i][0], &a[i][1]);
    for(ll s=1; s < c; s++){
        for(ll i=0; i + s < c; i++){
            ll m, t=-1;
            for(int j=i+1; j<=i+s; j++){
                m = dp[i][j-1] + dp[j][i+s] + a[i][0] * a[j][0] * a[i+s][1];
                if(t==-1) t = m;
                else t = min(m, t);
            }
            dp[i][i+s] = t;
        }
    }
    printf("%lld", dp[0][c-1]);
}