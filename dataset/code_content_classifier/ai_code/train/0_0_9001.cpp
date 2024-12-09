#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int n;
    cin >> n;
    
    vector<Edge> edges;
    
    for (int i = 0; i < n; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        
        edges.push_back({i, i+1, p});
    }
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    parent.resize(n+1);
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    int cost = 0;
    int numEdges = 0;
    
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.w;
            unite(e.u, e.v);
            numEdges++;
        }
    }
    
    if (numEdges != n-1) {
        cout << "-1" << endl;
    } else {
        cout << cost << endl;
    }
    
    return 0;
}