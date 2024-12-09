#include <iostream>
#include <vector>

using namespace std;

vector<int> salaries;
vector<int> dislikes;
vector<int> brag_count;

int find(int x) {
    if (x != dislikes[x]) {
        dislikes[x] = find(dislikes[x]); // path compression
    }
    return dislikes[x];
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        brag_count[a] += brag_count[b];
        dislikes[b] = a;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    salaries.resize(n + 1, 1);
    dislikes.resize(n + 1);
    brag_count.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dislikes[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }

    int q;
    cin >> q;

    for (int i = 0; i <= q; i++) {
        int v;
        if (i > 0) {
            cin >> v;
            v = find(v);

            for (int j = 1; j <= n; j++) {
                if (find(j) == v && salaries[j] < salaries[v]) {
                    brag_count[v]++;
                }
            }

            salaries[v] = n + i;
        }

        cout << brag_count[v] << endl;
    }

    return 0;
}