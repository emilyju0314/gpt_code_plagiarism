#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subtree_size, depth_sum, ans;

void dfs(int u, int p, int d) {
    subtree_size[u] = 1;
    depth_sum[u] = d;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        subtree_size[u] += subtree_size[v];
        depth_sum[u] += depth_sum[v];
    }
}

int get_ans(int u, int p) {
    ans[u] = depth_sum[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        int prev_u = depth_sum[u], prev_v = depth_sum[v];
        int sz_u = subtree_size[u], sz_v = subtree_size[v];

        depth_sum[u] -= depth_sum[v] + subtree_size[v];
        subtree_size[u] -= subtree_size[v];
        depth_sum[v] += depth_sum[u] + subtree_size[u];
        subtree_size[v] += subtree_size[u];

        ans[u] = max(ans[u], get_ans(u, v));
        
        depth_sum[u] = prev_u;
        depth_sum[v] = prev_v;
        subtree_size[u] = sz_u;
        subtree_size[v] = sz_v;
    }

    return ans[u];
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    subtree_size.resize(n + 1);
    depth_sum.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 0);
    int res = get_ans(1, 0);

    cout << res << endl;

    return 0;
}