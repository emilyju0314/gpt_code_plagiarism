#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];
vector<int> x, y, a;
int ans = 0;

void dfs(int u, int p, int xor_val) {
    xor_val ^= a[u];
    if (u != p && adj[u].size() == 1) {
        ans += xor_val;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, xor_val);
        }
    }
}

int main() {
    cin >> N;
    x.resize(N - 1);
    y.resize(N - 1);
    a.resize(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> x[i] >> y[i] >> a[i];
        adj[x[i]].push_back(y[i]);
        adj[y[i]].push_back(x[i]);
    }

    dfs(0, -1, 0);

    cout << ans << endl;

    return 0;
}