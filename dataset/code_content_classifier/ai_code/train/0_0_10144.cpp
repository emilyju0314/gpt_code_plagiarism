#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, e;
};

int findParent(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);

    if (parentU != parentV) {
        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].e;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.e > b.e; });

    int parent[n + 1];
    int rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<int> emax(m, 0);
    for (int i = 0; i < m; i++) {
        int parentU = findParent(parent, edges[i].u);
        int parentV = findParent(parent, edges[i].v);
        emax[i] = max(emax[i], max(edges[i].e, max(emax[parentU], emax[parentV])));
        unionSets(parent, rank, parentU, parentV);
    }

    for (int i = 0; i < m; i++) {
        cout << emax[i] << endl;
    }

    return 0;
}