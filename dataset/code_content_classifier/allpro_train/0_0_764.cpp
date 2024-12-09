#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Road {
    int city1, city2, length;
};

vector<vector<int>> tree;
vector<int> subtree_size;
vector<int> parent;
vector<int> depth;
vector<int> dist;

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    subtree_size[node] = 1;
    for (int child : tree[node]) {
        if (child == par) continue;
        dfs(child, node, d + 1);
        subtree_size[node] += subtree_size[child];
    }
}

int getLCA(int u, int v) {
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    while (depth[v] > depth[u]) {
        v = parent[v];
    }
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int getDistance(int u, int v) {
    int lca = getLCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main() {
    int N, Q;
    cin >> N >> Q;

    tree.resize(N);
    parent.resize(N);
    dist.resize(N);
    depth.resize(N);
    subtree_size.resize(N);

    vector<Road> roads(N-1);
    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        roads[i] = {u, v, w};
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1, 0);

    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;

        int minCost = INT_MAX;
        for (int city1 : {a, b, c}) {
            for (int city2 : {a, b, c}) {
                if (city1 == city2) continue;
                int city3 = a + b + c - city1 - city2;
                int cost = getDistance(city1, city2) + getDistance(city2, city3);
                minCost = min(minCost, cost);
            }
        }

        cout << minCost << endl;
    }

    return 0;
}