#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> subtreeSize;
vector<long long> distSum;

void dfs(int u, int p) {
    subtreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
            distSum[u] += distSum[v] + subtreeSize[v];
        }
    }
}

void solve(int n) {
    adj.resize(n);
    subtreeSize.resize(n);
    distSum.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += distSum[i];
    }

    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    solve(n);

    return 0;
}