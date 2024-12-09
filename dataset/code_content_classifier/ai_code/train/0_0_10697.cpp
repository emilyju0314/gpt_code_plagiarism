#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
vector<int> a;
int n, k;
int ans;

int dfs(int u, int p) {
    vector<int> children;
    for (int v : adj[u]) {
        if (v != p) {
            children.push_back(dfs(v, u));
        }
    }
    sort(children.begin(), children.end());

    int cnt = 1;
    for (int i = 0; i < (int)children.size() && cnt < k; ++i) {
        ans = max(ans, a[u]);
        a[u] = max(a[u], children[i]);
        ++cnt;
    }

    return a[u];
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs(0, -1);

    cout << ans << endl;

    return 0;
}