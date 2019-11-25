/*
세그먼트 트리
dp로 접근했을 때 공간복잡도를 초과하는 경우에 사용할 수 있다.
지속적으로 update되어야 하는 경우에 시간을 줄일 수 있다.

PBT -> 완벽 이진 트리
2의 거듭제곱 수가 되도록 0을 추가하여 PBT를 만들 수도 있다.

교환 법칙이 성립하고 항등원이 존재해야 한다. -> 덧셈의 0과 곱셈의 1
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#define BASE 1048576 // 2^20

using namespace std;

typedef struct {
    int value;
    int L, R;
} node;

node segTree[BASE * 2];

void constructSegTree(){
    for(int i=BASE-1; i>0; i--){
        segTree[i].value = segTree[i*2].value + segTree[i*2+1].value;

        // L, R update
        segTree[i].L = segTree[i*2].L;
        segTree[i].R = segTree[i*2+1].R;
    }
    return;
}

void update(int index, int value){
    // zero-base index
    index += BASE;

    segTree[index].value = value;
    
    index /= 2;
    while(index){ // 1st node일 때도 갱신을 해줘야 하기 때문에
        // 필요한 부분만(parent node만) update하는 식으로 진행.
        segTree[index].value = segTree[index * 2].value + segTree[index * 2 + 1].value;
        index /= 2;
    }
}

int sum(int t, int L, int R){
    // L, R should be inputed with sum of BASE
    // t == 1 at the first time
    if(R < segTree[t].L || segTree[t].R < L) return 0;    
    if(L <= segTree[t].L && segTree[t].R <= R) return segTree[t].value;
    
    return sum(t*2, L, R) + sum(t*2 + 1, L, R);
}

int main(){
    int n;
    scanf("%d", &n);

    // segTree initialize
    for(int i=0; i<n; i++){
        scanf(" %d", &segTree[BASE+i].value);

        // L, R initialize
        segTree[BASE+i].L = BASE+i;
        segTree[BASE+i].R = BASE+i;
    }
    
    for(int i=n; i<BASE; i++){
        segTree[BASE+i].L = BASE+i;
        segTree[BASE+i].R = BASE+i;
    }

    constructSegTree();

    printf("%d\n", segTree[1].value);
    printf("%d\n", sum(1, 0 + BASE, 5 + BASE));
}
