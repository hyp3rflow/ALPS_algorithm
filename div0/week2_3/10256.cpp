#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int GO_MAX = 4;

struct Trie {
    Trie *go[GO_MAX];
    Trie *fail;
    bool output;
    bool goexist;
    Trie() {
        fill(go, go + GO_MAX, nullptr);
        output = goexist = false;
    }
    ~Trie() {
        for (int i = 0; i < GO_MAX; i++)
            if (go[i])
                delete go[i];
    }
    void insert(const char *key) {
        if (*key == '\0')
            output = true;
        else {
            int next = *key - 'a';
            if (!go[next])
                go[next] = new Trie;
            goexist = true;
            go[next]->insert(key + 1);
        }
    }
};

//goexist true -> output true 면 일관성 없다는 것

int main() {
    int N;
    scanf("%d%*c", &N);

    Trie *a = new Trie();

    for (int i = 0; i < N; i++) {
        char arr[101];
        scanf("%s", arr);

        (*a).insert(arr);
    }

    queue<Trie *> Q;
    a->fail = a;
    Q.push(a);
    while (!Q.empty()) {
        Trie *current = Q.front();
        Q.pop();
        for (int i = 0; i < GO_MAX; i++) {
            Trie *next = current->go[i];
            if (!next)
                continue;
            if (current == a)
                next->fail = a;
            else {
                Trie *dest = current->fail;
                while (dest != a && !dest->go[i])
                    dest = dest->fail;
                if (dest->go[i])
                    dest = dest->go[i];
                next->fail = dest;
            }
            if (next->fail->output)
                next->output = true;

            Q.push(next);
        }
    }

    return 0;
}