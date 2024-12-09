#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
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

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY]) {
                    rank[rootY]++;
                }
            }
        }
    }
};

bool sortByWeight(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), sortByWeight);
    DisjointSet ds(V);

    int MSTweight = 0;
    for (Edge& edge : edges) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        if (srcRoot != destRoot) {
            ds.Union(srcRoot, destRoot);
            MSTweight += edge.weight;
        }
    }

    return MSTweight;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int minSpanningTreeWeight = kruskalMST(V, edges);

    cout << minSpanningTreeWeight << endl;

    return 0;
}