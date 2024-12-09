#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int findParent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int uParent = findParent(parent, u);
    int vParent = findParent(parent, v);

    if (rank[uParent] < rank[vParent]) {
        parent[uParent] = vParent;
    } else if (rank[uParent] > rank[vParent]) {
        parent[vParent] = uParent;
    } else {
        parent[vParent] = uParent;
        rank[uParent]++;
    }
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }

    sort(edges.begin(), edges.end(), compareEdges);

    long long ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> parent(N+1);
        vector<int> rank(N+1, 0);

        for (int j = 1; j <= N; j++) {
            parent[j] = j;
        }

        long long totalWeight = 0;
        bool hasWhite = false, hasBlack = false;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                int u = edges[j].u;
                int v = edges[j].v;
                int weight = edges[j].weight;

                if (findParent(parent, u) != findParent(parent, v)) {
                    unionSets(parent, rank, u, v);
                    totalWeight += weight;

                    if (weight == X) {
                        hasBlack = true;
                    }
                }
            }
        }

        if (totalWeight == X && hasBlack) {
            ans++;
        }
    }

    cout << ans % mod << endl;

    return 0;
}