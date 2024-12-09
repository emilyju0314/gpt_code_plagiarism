#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 305;

vector<int> adj[MAXN];
int dp[MAXN][MAXN];

int add(int a, int b) {
    return (a + b) % MOD;
}

int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

int modPow(int base, int exp) {
    int result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % MOD;
        }
        exp = exp / 2;
        base = (1LL * base * base) % MOD;
    }
    return result;
}


void dfs(int u, int parent, int n) {
    dp[u][0] = 1;

    for(int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, n);

        for(int j = 0; j < n; j++) {
            dp[u][j + 1] = add(dp[u][j + 1], dp[v][j]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, n);

    int ans = 0;
    for(int root = 1; root <= n; root++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = add(sum, mult(i, dp[root][i]));
        }
        ans = add(ans, sum);
    }

    int inv = modPow(2, n);
    ans = mult(ans, inv);

    cout << ans << endl;

    return 0;
}