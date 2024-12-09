#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = (int)1e5 + 5;

int n;
vector<pair<int, int>> tree[MAXN];
vector<long long> weights(MAXN);
vector<long long> ans(MAXN - 1);

long long dfs(int v, int p, int k) {
    long long sum = weights[v];
    for (pair<int, int> u : tree[v]) {
        if (u.first == p) continue;
        sum += dfs(u.first, v, k);
    }

    if (p != -1 && k > 0) {
        ans[k - 1] = max(ans[k - 1], sum);
    }

    return sum;
}

void solve() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        tree[i].clear();
    }
    ans.assign(n - 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back({v, i});
        tree[v].push_back({u, i});
    }

    dfs(1, -1, 0);

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}