#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int parent[MAXN*MAXN];

int find(int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N*N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        for (int j = 0; j < N; j++) {
            merge(u + j*N, v + j*N);
            merge(u*N + j, v*N + j);
        }
    }

    set<int> connectedComponents;
    for (int i = 1; i <= N*N; i++) {
        connectedComponents.insert(find(i));
    }

    cout << connectedComponents.size() << endl;

    return 0;
}