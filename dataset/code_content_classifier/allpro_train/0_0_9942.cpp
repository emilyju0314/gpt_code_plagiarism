#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> ranks;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;
    
    if (ranks[pu] < ranks[pv]) {
        swap(pu, pv);
    }
    parent[pv] = pu;
    ranks[pu] += ranks[pv];
}

int main() {
    int N, M;
    cin >> N >> M;
    
    parent.resize(N);
    ranks.resize(N);

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        parent[i] = i;
        ranks[i] = 1;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int xi, yi;
        cin >> xi >> yi;
        edges.push_back({a[xi] + a[yi], {xi, yi}});
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) != find(v)) {
            merge(u, v);
            cost += edge.first;
        }
    }

    if (ranks[find(0)] == N) {
        cout << cost << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}