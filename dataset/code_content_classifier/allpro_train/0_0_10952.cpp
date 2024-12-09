#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight, index;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int find(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v], parent);
}

void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].index = i + 1;
    }

    int u;
    cin >> u;

    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int totalWeight = 0;
    vector<int> includedEdges;
    
    for (int i = 0; i < m; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int weight = edges[i].weight;
        
        if (find(from, parent) != find(to, parent)) {
            totalWeight += weight;
            includedEdges.push_back(edges[i].index);
            unite(from, to, parent, rank);
        }
    }

    cout << totalWeight << endl;
    for (int edge : includedEdges) {
        cout << edge << " ";
    }
    
    return 0;
}