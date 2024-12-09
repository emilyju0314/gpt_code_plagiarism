#include <iostream>
#include <vector>
#include <cstring>
#define MOD 998244353
using namespace std;

vector<int> adj[200005];
long long dp[200005];

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void dfs(int v, int p) {
    dp[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            dp[v] = (dp[v] * dp[u]) % MOD;
        }
    }
    dp[v] = (dp[v] * power(2, adj[v].size() - (v != 1))) % MOD;
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

    dfs(1, 0);
    cout << dp[1] << endl;

    return 0;
}