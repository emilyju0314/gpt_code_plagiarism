#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> subtreeSize;
vector<int> dp;
int N, M;

void dfs(int u, int p) {
    subtreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

void dfs2(int u, int p) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs2(v, u);
            dp[u] = (1LL * dp[u] * dp[v]) % M;
        }
    }
}

void solve() {
    cin >> N >> M;
    adj.resize(N);
    subtreeSize.resize(N);
    dp.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < N; i++) {
        int ans = dp[i];
        for (int v : adj[i]) {
            if (v < i) {
                ans = (1LL * ans * (N - subtreeSize[v])) % M;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}