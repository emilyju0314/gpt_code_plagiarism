#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int n1, n2, k;
vector<int> adj1[4005], adj2[4005];
int dp[4005][4005][76][2];

void dfs1(int u, int p) {
    for (int v : adj1[u]) {
        if (v != p) {
            dfs1(v, u);
            for (int i = 1; i <= k; i++) {
                dp[u][i][0][0] = (dp[u][i][0][0] + dp[v][i][0][1]) % MOD;
                dp[u][i][0][1] = (dp[u][i][0][1] + dp[v][i][0][1]) % MOD;
            }
        }
    }
    dp[u][1][1][0] = 1;
    dp[u][1][1][1] = 1;
    for(int i = 2; i <= k; i++){
        dp[u][i][i][1] = 1;
    }
}

void dfs2(int u, int p) {
    for (int v : adj2[u]) {
        if (v != p) {
            dfs2(v, u);
            for (int i = 1; i <= k; i++) {
                dp[u][i][0][0] = (dp[u][i][0][0] + dp[v][i][0][1]) % MOD;
                dp[u][i][0][1] = (dp[u][i][0][1] + dp[v][i][0][1]) % MOD;
            }
        }
    }
    dp[u][1][1][0] = 1;
    dp[u][1][1][1] = 1;
    for(int i = 2; i <= k; i++){
        dp[u][i][i][1] = 1;
    }
}

int main() {
    cin >> n1 >> n2 >> k;

    for (int i = 1; i < n1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    for (int i = 1; i < n2; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    long long ans = 0;
    for (int u1 = 1; u1 <= n1; u1++) {
        for (int u2 = 1; u2 <= n2; u2++) {
            ans = (ans + (long long)dp[u1][k][u2][0] * dp[u2][k][u1][1]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}