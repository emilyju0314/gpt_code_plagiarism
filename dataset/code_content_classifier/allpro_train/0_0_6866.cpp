#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200005];
int in[200005], out[200005], n;

void dfs(int v, int p) {
    in[v] = out[v] = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        in[v] = max(in[v], in[u] + 1);
    }
    for (int u : adj[v]) {
        if (u == p) continue;
        out[v] = max(out[v], out[u] + 1);
        out[v] = max(out[v], in[u] + 2);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, in[i]);
    }

    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (in[i] == ans) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}