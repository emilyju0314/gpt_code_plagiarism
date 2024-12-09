#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> in, out;

int dfs(int u, int p) {
    int ans = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        ans += dfs(v, u);
        in[u] = max(in[u], in[v]);
    }
    if (ans == 0) in[u] = 1;
    return ans + 1;
}

void solve() {
    int n;
    cin >> n;

    adj.resize(n);
    in.resize(n, 0);
    out.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        out[a]++;
        in[b]++;
    }

    vector<int> leafs;
    for (int i = 0; i < n; i++) {
        if (out[i] == 0) leafs.push_back(i);
    }

    int root = leafs[0];
    dfs(root, -1);

    int ans = n;
    for (int leaf : leafs) {
        ans = min(ans, in[leaf]);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}