#include <bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5;
int dp[N], p[N], x[N];
vector <int> g[N];

void dfs(int v) {
    if (g[v].empty()) {dp[v] = x[v]; return ;}
    vector <int> vec;
    bitset <N> bt = 0;
    int res = 0;
    for (int u : g[v]) {
        dfs(u);
        if (x[u] < dp[u] - x[u]) res += x[u];
        else res += dp[u] - x[u];
        vec.push_back(abs(2 * x[u] - dp[u]));
        dp[v] += dp[u];
    }
    bt[res] = 1;
    for (int i : vec) bt |= bt<<i;
    for (int i = x[v]; i >= 0; i--) if (bt[i] == 1) {
        dp[v] += x[v] - i;
        return ;
    }
    cout << "IMPOSSIBLE\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) cin >> p[i], g[p[i]].push_back(i);
    for (int i = 1; i <= n; i++) cin >> x[i];
    dfs(1);
    cout << "POSSIBLE\n";

    return 0;
}
