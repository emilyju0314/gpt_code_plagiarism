#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int q = 0; q < Q; q++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            unite(u, v);
        } else {
            if (find(u) == find(v)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}