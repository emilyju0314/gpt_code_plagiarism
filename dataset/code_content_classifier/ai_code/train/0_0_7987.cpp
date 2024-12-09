#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100005];
int dist[100005];
int matched[100005];
int k;

void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
}

void solve(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        solve(v, u);
        if (dist[u] + dist[v] == k/2 && matched[u] == 0 && matched[v] == 0) {
            matched[u] = v;
            matched[v] = u;
        }
    }
}

int main() {
    int n;
    cin >> n >> k;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    solve(1, 0);

    if (k % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            if (matched[i] && i < matched[i]) {
                cout << i << " " << matched[i] << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}