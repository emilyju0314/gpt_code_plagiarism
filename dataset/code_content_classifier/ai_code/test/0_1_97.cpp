#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<int> numChildren;
vector<int> maxChild;
vector<int> dp;
vector<int> ans;

void dfs(int u, int parent) {
    numChildren[u] = 1;
    maxChild[u] = 0;

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            numChildren[u] += numChildren[v];
            maxChild[u] = max(maxChild[u], numChildren[v]);
        }
    }
}

void dfs2(int u, int parent) {
    dp[u] = maxChild[u];

    for (int v : adj[u]) {
        if (v != parent) {
            dp[u] = max(dp[u], dp[v]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    numChildren.resize(n + 1);
    maxChild.resize(n + 1);
    dp.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    dfs2(1, 0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        int c = numChildren[v] - 1;
        int m = min(c, k);

        int result = max(0, c - m);

        ans.push_back(result + dp[v]);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}