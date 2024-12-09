#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, cost;
};

bool compareEdges(Edge a, Edge b) {
    return a.cost < b.cost;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    if (rootA == rootB)
        return;

    if (rank[rootA] < rank[rootB])
        parent[rootA] = rootB;
    else if (rank[rootA] > rank[rootB])
        parent[rootB] = rootA;
    else {
        parent[rootA] = rootB;
        rank[rootB]++;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        totalCost += c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    int parent[n + 1];
    int rank[n + 1];

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int minCost = 0;

    for (Edge edge : edges) {
        if (find(parent, edge.from) != find(parent, edge.to)) {
            unionSets(parent, rank, edge.from, edge.to);
            minCost += edge.cost;
        }
    }

    cout << totalCost - minCost << endl;

    return 0;
}