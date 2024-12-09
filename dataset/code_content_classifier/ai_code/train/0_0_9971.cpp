#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, energy;
};

bool cmp(Edge a, Edge b) {
    return a.energy > b.energy;
}

int find(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

void merge(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) {
            rank[rootY]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].energy;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<int> maxEnergy(m-n+1, 0);
    int idx = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int energy = edges[i].energy;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            merge(parent, rank, rootU, rootV);
        } else {
            maxEnergy[idx] = energy;
            idx++;
        }
    }

    for (int i = 0; i < m-n+1; i++) {
        cout << maxEnergy[i] << endl;
    }

    return 0;
}