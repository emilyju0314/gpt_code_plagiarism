#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

vector<int> adj[MAXN];
vector<int> illusionRate(MAXN);
vector<int> depth(MAXN);
vector<long long> fenwickTree(2 * MAXN, 0);

// DFS function to traversal the tree
void dfs(int node, int parent, int d) {
    depth[node] = d;
    fenwickTree[d] = fenwickTree[d - 1] + abs(illusionRate[node] - illusionRate[parent]);
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, d + 1); // increment depth by 1
        }
    }
}

// Update the Fenwick Tree to change illusion rate
void update(int node, int newRate) {
    int d = depth[node];
    long long diff = newRate - illusionRate[node];
    illusionRate[node] = newRate;
    for (int i = d; i < 2 * MAXN; i++) {
        fenwickTree[i] += diff;
    }
}

// Query function to calculate the minimum sum of energy needed
long long query(int u, int v) {
    long long ans = 0;
    int d = depth[v] - depth[u];
    ans = fenwickTree[depth[u]] - fenwickTree[depth[v]];
    ans += abs(illusionRate[u] - illusionRate[v]);
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> illusionRate[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 1); // start DFS traversal from node 1

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            update(u, v);
        } else {
            cout << query(u, v) << endl;
        }
    }

    return 0;
}