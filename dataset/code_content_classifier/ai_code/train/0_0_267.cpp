#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int depth[MAXN];

void dfs(int u, int parent, int d) {
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, d + 1);
        }
    }
}

bool isPossible(int x, int y, int a, int b, int k) {
    if (depth[a] + depth[b] <= k && (k - depth[a] - depth[b]) % 2 == 0) {
        return true;
    } else if (depth[a] + depth[x] + depth[y] <= k && (k - depth[a] - depth[x] - depth[y]) % 2 == 0) {
        return true;
    } else if (depth[b] + depth[x] + depth[y] <= k && (k - depth[b] - depth[x] - depth[y]) % 2 == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    int q;
    cin >> q;

    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        if (isPossible(x, y, a, b, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}