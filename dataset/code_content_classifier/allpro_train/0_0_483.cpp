#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subtreeSize;
long long ans = 0;

void dfs(int v, int p) {
    subtreeSize[v] = 1;
    for(int u : adj[v]) {
        if(u != p) {
            dfs(u, v);
            subtreeSize[v] += subtreeSize[u];
            if(subtreeSize[u] % 2 == 0) {
                ans += 1LL * (n - subtreeSize[u]) * subtreeSize[u];
            }
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    subtreeSize.resize(n);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << ans << endl;

    return 0;
}