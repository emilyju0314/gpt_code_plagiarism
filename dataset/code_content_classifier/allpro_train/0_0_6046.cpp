#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    double weight;
};

struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

bool compareEdges(Edge& e1, Edge& e2) {
    return e1.weight < e2.weight;
}

double calculateDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int V, R;
    cin >> V >> R;
    
    vector<Point> settlements(V);
    for (int i = 0; i < V; i++) {
        cin >> settlements[i].x >> settlements[i].y; 
    }
    
    vector<Edge> roads(R);
    for (int i = 0; i < R; i++) {
        cin >> roads[i].u >> roads[i].v;
        roads[i].u--;
        roads[i].v--;
        roads[i].weight = calculateDistance(settlements[roads[i].u], settlements[roads[i].v]);
    }
    
    sort(roads.begin(), roads.end(), compareEdges);
    
    DisjointSet ds(V);
    double totalLength = 0;
    
    for (Edge e : roads) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ds.merge(e.u, e.v);
            totalLength += e.weight;
        }
    }
    
    cout << fixed << setprecision(4) << totalLength << endl;
    
    return 0;
}