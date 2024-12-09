#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100000;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer = 0;
int parent[MAXN][MAXLOG];
int depth[MAXN];
vector<int> euler;
vector<int> values;

void dfs(int v, int p, int d) {
    tin[v] = timer++;
    parent[v][0] = p;
    depth[v] = d;
    for (int i = 1; i < MAXLOG; i++) {
        parent[v][i] = parent[parent[v][i - 1]][i - 1];
    }
    euler.push_back(v);
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            euler.push_back(v);
        }
    }
    tout[v] = timer++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (!isAncestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

double calculateExpectedValue(int u, int v) {
    int ancestor = lca(u, v);
    int dist = depth[u] + depth[v] - 2 * depth[ancestor];
    return (double)(values[ancestor] + dist);
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    values.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    dfs(1, 0, 0);

    int q;
    cin >> q;

    cout << "0.000000000" << endl; // Initial expected value
    
    for (int i = 0; i < q; i++) {
        char type;
        int u, v, t;
        cin >> type >> u >> v;
        
        if (type == 'P') {
            int origin = u;
            int ancestor = lca(u, v);
            while (u != ancestor) {
                int newParent = parent[u][0];
                if (!isAncestor(v, newParent)) {
                    parent[u][0] = v;
                } else {
                    parent[v][0] = u;
                }
                u = newParent;
            }
            while (origin != ancestor) {
                int newParent = parent[origin][0];
                if (!isAncestor(v, newParent)) {
                    parent[origin][0] = v;
                } else {
                    parent[v][0] = origin;
                }
                origin = newParent;
            }
        } else if (type == 'V') {
            values[u] = t;
        }
        
        cout << calculateExpectedValue(u, v) << endl;
    }

    return 0;
}