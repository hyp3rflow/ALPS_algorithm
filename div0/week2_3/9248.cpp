#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1<<19;
char str[MAX];

// SA array -> SA 정렬된 상태로 저장되는 배열, Suffix의 정보를 담고 있다.
// pos array -> 그룹 배열, pos[SA[i]] -> i번째 SA의 그룹
// temp array -> 그룹들 임시로 저장해둔 배열, 마찬가지로 i번째의 임시 그룹 
int N, d, SA[MAX], pos[MAX], lcp[MAX];

bool compare(int i, int j){
    if(pos[i] != pos[j])
        return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void makeSA(){
    N = strlen(str);

    // 초기에는 제자리 문자들로 비교한다.
    for (int i = 0; i < N; i++){
        SA[i] = i;
        pos[i] = str[i];
    }

    for (d = 1; ; d*=2){
        // d 이용해서 SA sorting
        sort(SA, SA + N, compare);

        int temp[MAX] = {0};

        // 다른 그룹번호끼리는 증가하도록 그룹명 재배열
        for (int i = 0; i < N - 1; i++){
            temp[i + 1] = temp[i] + compare(SA[i], SA[i + 1]);
        }

        // temp 배열의 그룹번호는 정렬된 순서일 것이므로,
        // 정렬된 순서대로 pos 배열에 갱신시켜준다.
        for (int i = 0; i < N; i++){
            pos[SA[i]] = temp[i];
        }

        // 만약 재배열된 그룹명에 중복되는 것이 없다면,
        // 즉 모든 Suffix들이 다른 그룹에 속해있다면 중단.
        if(temp[N-1] == N-1)
            break;
    }
}

void makeLCP(){
    for (int i = 0, k = 0; i < N; i++, k=max(k-1, 0)){
        if(pos[i] == N-1)
            continue;
        // pos 마지막까지 정렬된 상태에서는 Suffix i가 몇 번째인지 알려줌. (그룹이니까)
        for (int j = SA[pos[i] + 1]; str[i + k] == str[j + k]; k++);
        lcp[pos[i]] = k;
    }
}

int main() {
    scanf("%s", str);
    makeSA();
    makeLCP();
    for (int i = 0; i < N; i++) {
        printf("%d ", SA[i] + 1);
    }
    printf("\nx ");
    for (int i = 0; i < N-1; i++){
        printf("%d ", lcp[i]);

    }
}
