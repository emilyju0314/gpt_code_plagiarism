#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findParent(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<string> ans(m);

    unordered_map<int, int> edgeCount;

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu != pv) {
            unionSets(u, v, parent, rank);
            edgeCount[edges[i].weight]++;
        }
    }

    for (int i = 0; i < m; i++) {
        int weight = edges[i].weight;
        if (edgeCount[weight] == 1) {
            ans[i] = "any";
        } else if (edgeCount[weight] > 1) {
            ans[i] = "at least one";
        } else {
            ans[i] = "none";
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}