#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> subtreeSize;

void dfs(int v, int p) {
    subtreeSize[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            subtreeSize[v] += subtreeSize[u];
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N);
    subtreeSize.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    vector<int> ans(N, 0);

    for (int v = 0; v < N; v++) {
        ans[subtreeSize[v] - 1] = max(ans[subtreeSize[v] - 1], subtreeSize[v]);
    }

    for (int k = 1; k <= N; k++) {
        cout << ans[k - 1] << " ";
    }

    return 0;
}