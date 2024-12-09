#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define MOD 1000000007

using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    long long totalCost = 0;
    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    int ways = 1;
    for (int i = 0; i < M; ++i) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
        } else {
            totalCost ^= edges[i].w;
            ways = (ways * 2) % MOD;
        }
    }

    cout << totalCost << " " << ways << endl;

    return 0;
}