#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> industrial;
int n, k;

int dfs(int u, int p) {
    int total = industrial[u];
    for (int v : adj[u]) {
        if (v != p) {
            total += dfs(v, u);
        }
    }
    return max(0, total);
}

int main() {
    cin >> n >> k;
    adj.resize(n);
    industrial.resize(n);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < k; i++) {
        int city;
        cin >> city;
        city--;
        industrial[city] = 1;
    }

    cout << dfs(0, -1) << endl;

    return 0;
}