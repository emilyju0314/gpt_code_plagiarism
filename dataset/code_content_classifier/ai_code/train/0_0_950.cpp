#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 150001;
vector<int> adj[MAXN];
int parent[MAXN], heavyChild[MAXN], depth[MAXN], subtreeSize[MAXN], chainHead[MAXN], chainPos[MAXN], chainInd[MAXN], chainSize[MAXN];
int chainNo, pos;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    subtreeSize[u] = 1;
    heavyChild[u] = -1;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            subtreeSize[u] += subtreeSize[v];
            if (heavyChild[u] == -1 || subtreeSize[v] > subtreeSize[heavyChild[u]]) {
                heavyChild[u] = v;
            }
        }
    }
}

void hld(int u, int h) {
    chainHead[u] = h;
    chainPos[u] = pos;
    chainInd[u] = chainNo;
    pos++;
    
    if (chainSize[chainNo] == 0) {
        chainSize[chainNo] = pos - 1;
    }

    if (heavyChild[u] != -1) {
        hld(heavyChild[u], h);
    }

    for (int v : adj[u]) {
        if (v != parent[u] && v != heavyChild[u]) {
            chainNo++;
            pos = 0;
            hld(v, v);
        }
    }
}

int lca(int u, int v) {
    while (chainInd[u] != chainInd[v]) {
        if (depth[chainHead[u]] < depth[chainHead[v]]) {
            v = parent[chainHead[v]];
        } else {
            u = parent[chainHead[u]];
        }
    }

    return (depth[u] < depth[v]) ? u : v;
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void updateDescendants(int u, int x) {
    // TODO: Implement updating the weights of edges connecting to descendants of vertex u by x
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, 0);
    chainNo = 0;
    pos = 0;
    hld(0, 0);

    for (int i = 0; i < Q; i++) {
        int type, u, v, x;
        cin >> type;

        if (type == 0) {
            cin >> u >> v;
            cout << dist(u, v) << endl;
        } else {
            cin >> u >> x;
            updateDescendants(u, x);
        }
    }

    return 0;
}