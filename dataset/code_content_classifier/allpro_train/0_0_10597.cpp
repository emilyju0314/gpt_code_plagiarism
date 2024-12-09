#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    subtree_size.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    double ans = 0.0;
    for (int i = 1; i < n; i++) {
        ans += 1.0 / subtree_size[i];
    }

    cout << fixed << setprecision(9) << ans + 1.0 << endl;

    return 0;
}