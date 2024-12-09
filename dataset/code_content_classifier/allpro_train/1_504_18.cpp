#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int n, m;

ll adj[40];
int c[40];

void outbin(ll b) {
    for (int i = n - 1; i >= 0; --i) {
        cout << ((b >> i) & 1LL ? 1 : 0);
    }
    cout << endl;
}

int dfs(int k, ll f) {
    if (k == n - 1) {
        f = ~adj[k] & f;
        int cost = 0;
        for (int i = 0; i < n; ++i)
            if (~f >> i & 1LL) cost += c[i];
        return cost;
    }

    int mincost = 1000000;
    for (int i = 0; i < n; ++i) {
        if ((adj[k] >> i & 1LL) & (f >> i & 1LL)) {
            int res = dfs(i, ~adj[k] & f);
            if (res < mincost) mincost = res;
        }
    }

    return mincost;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) adj[i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        //cout << u << ", " << v << endl;
        adj[u] |= 1LL << v;
        adj[v] |= 1LL << u;
    }

    cout << dfs(0, ~1LL) << endl;
    return 0;
}