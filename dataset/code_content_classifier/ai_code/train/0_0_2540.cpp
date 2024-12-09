#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> size, inv, cnt;

int dfs(int node, int parent) {
    size[node] = 1;
    int total_inv = 0;

    for (int child : adj[node]) {
        if (child == parent) continue;
        total_inv += dfs(child, node);
        size[node] += size[child];
    }

    inv[node] = size[node] * (size[node] - 1) / 2;
    
    for (int child : adj[node]) {
        if (child == parent) continue;
        int child_inv = size[child] * (size[child] - 1) / 2;
        inv[node] += child_inv;

        int common_inv = size[node] - size[child];
        common_inv *= size[child];
        common_inv += (size[child] * (size[child] - 1) / 2) * (size[node] - size[child]);
        common_inv /= 2;

        cnt[node] += cnt[child] + child_inv + common_inv;
    }

    return total_inv + inv[node];
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    size.resize(n+1);
    inv.resize(n+1);
    cnt.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}