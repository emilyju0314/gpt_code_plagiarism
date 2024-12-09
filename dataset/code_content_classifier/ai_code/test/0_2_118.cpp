#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 998244353;
const int MAXN = 250005;

vector<int> tree[MAXN];
int dp[MAXN][2]; // dp[i][0] -> number of beautiful colorings in subtree of i if i is colored j
int dp_sum[MAXN][2]; // dp_sum[i][0] -> sum of number of beautiful colorings in subtree of i if i is colored j

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;

    for (int v : tree[u]) {
        if (v == p) continue;

        dfs(v, u);

        // Calculate the number of beautiful colorings for each node
        dp[u][0] = (1LL * dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (1LL * dp[u][1] * dp[v][0]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);

    int ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}