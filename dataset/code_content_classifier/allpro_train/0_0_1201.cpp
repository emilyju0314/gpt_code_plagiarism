#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct Vertex {
    int index, X;
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        rank[v]++;
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<Vertex> vertices(N);
    for (int i = 0; i < N; i++) {
        cin >> vertices[i].X;
        vertices[i].index = i;
    }
    
    int M = N - 1;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }
    
    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<int> parent(N);
    vector<int> rank(N, 0);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    long long int totalCost = 0;
    for (int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (findParent(u, parent) != findParent(v, parent)) {
            totalCost += (long long int)weight + vertices[u].X + vertices[v].X;
            unionSets(u, v, parent, rank);
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}