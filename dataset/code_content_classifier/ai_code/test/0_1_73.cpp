#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find(parent[node], parent);
}

void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        rank[u] += rank[v];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    unordered_set<int> cycles;
    long long total_pairs = 0;
    long long current_pairs = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        if (find(u, parent) == find(v, parent)) {
            cycles.insert(find(u, parent));
        } else {
            unite(u, v, parent, rank);
        }

        current_pairs += i + 1 - cycles.size();
        total_pairs += current_pairs;
    }

    cout << total_pairs << endl;

    return 0;
}