#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(y)] = find(x);
}

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    int total_cost = 0;
    int max_cost = 0;

    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            total_cost += edge.w;

            if (edge.w > max_cost) {
                max_cost = edge.w;
            }

            merge(edge.u, edge.v);
        }
    }

    int ans = total_cost + C * (max_cost - C);
    cout << ans << endl;

    return 0;
}