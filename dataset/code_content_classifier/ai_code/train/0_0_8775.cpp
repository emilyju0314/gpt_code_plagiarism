#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 80005;

vector<int> adj[MAXN];
int cnt[MAXN];
long long ans;

void dfs(int u, int p) {
    cnt[u] = 1;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }

    ans += (long long)cnt[u] * (cnt[u] - 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs(1, -1);

    cout << ans << endl;

    return 0;
}