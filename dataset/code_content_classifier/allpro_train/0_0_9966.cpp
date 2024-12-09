#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 300005;
vector<int> adj[MAXN];
int values[MAXN];
int subtree_values[MAXN];

void dfs(int u, int p, int d, int x) {
    if (d == 0) {
        values[u] += x;
    }
    subtree_values[u] += x;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d-1, x);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int v, d, x;
        cin >> v >> d >> x;
        dfs(v, -1, d, x);
    }

    for(int i = 1; i <= n; i++) {
        cout << values[i] + subtree_values[i] << " ";
    }

    return 0;
}