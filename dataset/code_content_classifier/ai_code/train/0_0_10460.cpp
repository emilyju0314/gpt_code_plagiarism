#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> marbles;
vector<long long> dp;

void dfs(int node) {
    dp[node] = marbles[node];
    for (int child : adj[node]) {
        dfs(child);
        dp[node] += dp[child];
    }
}

long long solve(int node) {
    long long ans = dp[0] - dp[node];
    for (int child : adj[node]) {
        ans += solve(child);
        ans %= MOD;
    }
    ans = (ans + 1) % MOD;
    ans = (ans * (ans + 1)) / 2;
    return ans % MOD;
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    marbles.resize(N + 1);
    dp.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for (int i = 0; i <= N; i++) {
        marbles[i] = pow(2, N - i);
    }

    dfs(0);

    long long answer = solve(0) % MOD;
    
    cout << answer << endl;

    return 0;
}