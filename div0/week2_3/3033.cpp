#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1 << 19;
char str[MAX];

int N, d, pos[MAX], sa[MAX], lcp[MAX];

bool cmp(int i, int j){
    if(pos[i] != pos[j])
        return pos[i] < pos[j];

    i += d;
    j += d;

    // compare 기준 : 그룹번호 크거나, 더 길거나.
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void constructSA(){
    N = strlen(str);

    for (int i = 0; i < N; i++){
        sa[i] = i;
        pos[i] = str[i];
    }

    for (d = 1;;d*=2){
        sort(sa, sa + N, cmp);

        int tmp[MAX] = {0};

        for (int i = 0; i < N - 1; i++){
            tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
        }

        for (int i = 0; i < N; i++){
            pos[sa[i]] = tmp[i];
        }

        if(tmp[N-1] == N-1)
            break;
    }
}

void constructLCP(){
    for (int i = 0, k = 0; i < N; i++, k = max(k-1, 0)){
        if(pos[i] == N-1)
            continue;
        for (int j = sa[pos[i] + 1]; str[i + k] == str[j + k]; k++);
        lcp[pos[i]] = k;
    }
}

int main(){
    char tmp1[MAX];
    char tmp2[MAX];
    char tmpchr = '$';

    scanf("%s %s", tmp1, tmp2);
    strcat(str, tmp1);
    strcat(str, &tmpchr);
    strcat(str, tmp2);
    constructSA();
    constructLCP();

    int MAXoutput = -1;
    int MAXindex = -1;
    for (int i = 0; i < N - 1; i++) {
        int currentSfx = sa[i];
        int nextSfx = sa[i + 1];

        if (currentSfx < strlen(tmp1) && nextSfx > strlen(tmp1)){
            if(MAXoutput < lcp[i]){
                MAXoutput = lcp[i];
                MAXindex = sa[i];
            }
        }
        else if(currentSfx > strlen(tmp1) && nextSfx < strlen(tmp1)){
            if(MAXoutput < lcp[i]){
                MAXoutput = lcp[i];
                MAXindex = sa[i];
            }
        }
    }

    printf("%d\n", MAXoutput);

    for (int i = 0; i < MAXoutput; i++) {
        printf("%c", str[MAXindex + i]);
    }
}