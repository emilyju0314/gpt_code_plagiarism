#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int a, b, cost;
};

bool cmp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

int findRoot(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent[x], parent);
    }
    return parent[x];
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int numEdges = 0;

    for (int i = 0; i < M; i++) {
        int rootA = findRoot(edges[i].a, parent);
        int rootB = findRoot(edges[i].b, parent);

        if (rootA != rootB) {
            parent[rootA] = rootB;
            totalCost += edges[i].cost;
            numEdges++;
        }

        if (numEdges == N-1) {
            // We have found a minimum spanning tree
            break;
        }
    }

    cout << totalCost << endl;

    return 0;
}