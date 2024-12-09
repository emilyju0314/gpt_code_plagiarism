#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 17;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m;
string s, t;
int z[6 * N];
vector<int> g[N];
int dp[N], state[N];

bool read() {
    if (!(cin >> s >> t))
        return false;

    return true;
}

bool dfs(int v) {
    state[v] = 1;

    for (auto to : g[v]) {
        if (state[to] == 0) {
            if (!dfs(to))
                return false;
        } else if (state[to] == 1) {
            return false;
        }

        dp[v] = max(dp[v], dp[to] + 1);
    }

    state[v] = 2;
    return true;
}

void solve() {
    n = s.size();
    m = t.size();

    for (t += "#"; t.size() - m - 1 <= n + m; t += s) { }
    swap(t, s);

    for (int i = 1, l = 0, r = -1; i < m + n + n; ++i) {
        for (z[i] = i < r ? min(z[i - l], r - i) : 0; i + z[i] < s.size() && s[z[i]] == s[i + z[i]]; ++z[i])
            if (i + z[i] > r)
                l = i, r = i + z[i];

        if (i > m && i <= m + n && z[i] == m)
            g[i - m - 1].emplace_back((i - 1) % n);
    }

    auto flag = 1;

    for (int i = 0; i < n; ++i)
        if (state[i] == 0)
            flag &= dfs(i);

    if (!flag)
        cout << "-1\n";
    else
        cout << *max_element(dp, dp + n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (read())
        solve();

    return 0;
}

