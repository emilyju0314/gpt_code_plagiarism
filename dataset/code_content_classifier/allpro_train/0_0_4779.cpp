#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int subtract(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) 
            result = mult(result, a);
        a = mult(a, a);
        b >>= 1;
    }
    return result;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

vector<vector<int>> adj;
vector<pair<int, int>> points;
vector<vector<vector<int>>> dp;

int dfs(int u, int parent, int m) {
    dp[u][1] = 1;

    for (int v : adj[u]) {
        if (v == parent) 
            continue;
        
        int curM = dfs(v, u, m);
        vector<vector<int>> nxt(m + curM + 1, vector<int>(m + curM + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= curM; j++) {
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        int combine = mult(dp[u][i], dp[v][j]);
                        int divide = mult(dp[u][k], dp[v][l]);
                        divide = mult(divide, power(subtract(inverse(mult(dp[u][i], dp[v][j])), 1), MOD - 2));

                        nxt[i + j][k + l] = add(nxt[i + j][k + l], mult(combine, divide));
                    }
                }
            }
        }

        dp[u] = nxt;
    }

    return m;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    points.resize(n);
    dp.resize(n, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    for (int i = 0; i < n - 1; i++) {
        int s, f;
        cin >> s >> f;
        s--; f--;
        adj[s].push_back(f);
        adj[f].push_back(s);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, dfs(i, -1, 1));
    }

    cout << ans << endl;

    return 0;
}