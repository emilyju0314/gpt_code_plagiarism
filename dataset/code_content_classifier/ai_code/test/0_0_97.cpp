#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int children[MAXN];
int ans[MAXN];
int n, q;

void dfs(int v, int parent) {
    children[v] = 1;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            children[v] += children[u];
        }
    }
}

void solve(int v, int parent, int m, int k) {
    ans[v] = children[v] - m*k;
    for (int u : adj[v]) {
        if (u != parent) {
            solve(u, v, m + children[v] - children[u], k);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        solve(v, 0, 0, k);
        cout << ans[v] << endl;
    }

    return 0;
}