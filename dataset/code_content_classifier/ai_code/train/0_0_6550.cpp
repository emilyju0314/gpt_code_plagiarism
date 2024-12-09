#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[300005];
int dp1[300005], dp2[300005];

void dfs(int u, int parent) {
    dp1[u] = 1;
    dp2[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            dp1[u] += dp1[v];
            dp2[u] += dp2[v];
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        long long ans = 1LL * dp2[l] * dp1[r];
        cout << 1LL * (r - l + 1) * (r - l) / 2 - ans << endl;
    }

    return 0;
}