#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 105;

vector<int> adj[MAXN];
int dp[MAXN][MAXN][2];
int fact[MAXN];

void dfs(int u, int p) {
    dp[u][0][0] = 1;
    dp[u][1][1] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs(v, u);

        int tmp[MAXN][2];
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < i + 1; j++) {
                tmp[i][0] = (tmp[i][0] + 1LL * dp[u][i][0] * dp[v][j][0] % MOD * fact[j] % MOD) % MOD;
                tmp[i][0] = (tmp[i][0] + 1LL * dp[u][i][0] * dp[v][j][1] % MOD * fact[j] % MOD) % MOD;
                if (j < i) {
                    tmp[i][1] = (tmp[i][1] + 1LL * dp[u][i][1] * dp[v][j][0] % MOD * fact[j] % MOD) % MOD;
                }
                if (j < i - 1) {
                    tmp[i][1] = (tmp[i][1] + 1LL * dp[u][i][1] * dp[v][j][1] % MOD * fact[j] % MOD) % MOD;
                }
            }
        }

        memcpy(dp[u], tmp, sizeof(tmp));
    }
}

int main() {
    int n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 0; i < n; i++) {
        cout << dp[1][i][0] << " ";
    }
    cout << endl;

    return 0;
}