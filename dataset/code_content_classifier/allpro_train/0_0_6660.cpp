#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    double weight;

    Edge(int _u, int _v, double w) : u(_u), v(_v), weight(w) {}
};

struct DisjointSet {
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        parent[find(u)] = find(v);
    }
};

double calculateDistance(pair<int, int>& a, pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> piles(N);
    for(int i = 0; i < N; i++) {
        cin >> piles[i].first >> piles[i].second;
    }

    vector<Edge> edges;
    for(int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--; // 0-based indexing
        edges.push_back(Edge(p, q, calculateDistance(piles[p], piles[q])));
    }

    sort(edges.begin(), edges.end(), compareEdges);

    double total_water = 0.0;
    DisjointSet ds(N);
    for(Edge& edge : edges) {
        if(ds.find(edge.u) != ds.find(edge.v)) {
            total_water += edge.weight;
            ds.merge(edge.u, edge.v);
        }
    }

    cout << total_water << endl;

    return 0;
}