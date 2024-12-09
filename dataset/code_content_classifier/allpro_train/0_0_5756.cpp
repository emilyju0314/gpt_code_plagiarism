#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<pair<int,long long>>> tree;
vector<int> parent;
vector<long long> edgeValues;
vector<int> depth;
vector<int> tin, tout;
int timer;
int n;

void dfs(int v, int p, int d) {
    tin[v] = ++timer;
    depth[v] = d;
    parent[v] = p;
    for(auto u : tree[v]) {
        if(u.first != p) {
            edgeValues[u.first] = u.second;
            dfs(u.first, v, d+1);
        }
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    while(!isAncestor(u,v)) {
        u = parent[u];
    }
    return u;
}

long long processQuery1(int ai, int bi, long long yi) {
    int anc = lca(ai, bi);
    while(ai != anc) {
        yi /= edgeValues[ai];
        ai = parent[ai];
    }
    while(bi != anc) {
        yi /= edgeValues[bi];
        bi = parent[bi];
    }
    return yi;
}

int main() {
    int m;
    cin >> n >> m;

    tree.resize(n);
    parent.resize(n);
    depth.resize(n);
    edgeValues.resize(n);
    tin.resize(n);
    tout.resize(n);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        tree[u-1].push_back({v-1, x});
        tree[v-1].push_back({u-1, x});
    }

    dfs(0, -1, 0);

    while(m--) {
        int type;
        cin >> type;

        if(type == 1) {
            int ai, bi;
            long long yi;
            cin >> ai >> bi >> yi;
            cout << processQuery1(ai-1, bi-1, yi) << endl;
        } else {
            int pi, ci;
            cin >> pi >> ci;
            edgeValues[pi-1] = ci;
        }
    }

    return 0;
}