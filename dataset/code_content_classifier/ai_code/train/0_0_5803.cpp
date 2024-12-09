#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 505;

int n, x, y;
int a[MAXN];
vector<int> adj[MAXN], adj2[MAXN];
int dp[MAXN][MAXN][MAXN];
int q1, q2;
vector<pair<int, int>> demands1, demands2;

void build_tree(int u, vector<int> adj[MAXN], int root) {
    for (int v : adj[u]) {
        if (v != root) {
            adj2[u].push_back(v);
            build_tree(v, adj, u);
        }
    }
}

int solve(int u, int k1, int k2) {
    if (k1 == 0 && k2 == 0) return 0;
    if (u == 0) return -1e9;
    if (dp[u][k1][k2] != -1) return dp[u][k1][k2];

    int ans = -1e9;
    for (int i = 0; i <= k1; i++) {
        int j = k1 - i;
        if (i <= adj2[u].size() && j <= adj[u].size()) {
            ans = max(ans, a[u] + solve(adj2[u][i], i, j) + solve(adj[u][j], k1 - i, k2 - j));
        }
    }

    return dp[u][k1][k2] = ans;
}

int main() {
    cin >> n >> x >> y;
    x--; y--;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build_tree(x, adj, -1);
    build_tree(y, adj, -1);

    cin >> q1;
    for (int i = 0; i < q1; i++) {
        int k, x;
        cin >> k >> x;
        k--;
        demands1.push_back({k, x});
    }

    cin >> q2;
    for (int i = 0; i < q2; i++) {
        int k, x;
        cin >> k >> x;
        k--;
        demands2.push_back({k, x});
    }

    int revenue = 0;
    for (auto& d : demands1) {
        revenue += a[d.first];
    }
    for (auto& d : demands2) {
        revenue += a[d.first];
    }

    memset(dp, -1, sizeof(dp));
    int ans = solve(x, q1, q2);
    cout << (ans < 0 ? -1 : revenue + ans) << endl;

    return 0;
}