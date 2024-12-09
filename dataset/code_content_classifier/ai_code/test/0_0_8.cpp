#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e5+5;
const int LOGN = 20;

vector<int> adj[MAXN];
vector<int> illusion_rate(MAXN);
vector<vector<int>> dp(MAXN, vector<int>(LOGN));
vector<int> depth(MAXN);

void dfs(int u, int p, int d) {
    dp[u][0] = p;
    depth[u] = d;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, d+1);
        }
    }
}

void preprocess(int n) {
    for(int j = 1; j < LOGN; j++) {
        for(int i = 1; i <= n; i++) {
            if(dp[i][j-1] != -1) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    for(int i = LOGN-1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            u = dp[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i = LOGN-1; i >= 0; i--) {
        if(dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int calculate_energy(int u, int v) {
    int lca_uv = lca(u, v);
    int energy = 0;
    while(u != lca_uv) {
        energy = max(energy, abs(illusion_rate[u] + illusion_rate[dp[u][0]]));
        u = dp[u][0];
    }
    while(v != lca_uv) {
        energy = max(energy, abs(illusion_rate[v] + illusion_rate[dp[v][0]]));
        v = dp[v][0];
    }
    return energy;
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> illusion_rate[i];
    }

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    preprocess(n);

    for(int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            illusion_rate[u] = v;
        } else {
            int energy = calculate_energy(u, v);
            cout << energy << endl;
        }
    }

    return 0;
}