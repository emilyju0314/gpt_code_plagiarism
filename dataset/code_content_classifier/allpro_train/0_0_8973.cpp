#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<int> adjList[100001];
long long dp[100001][2];

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = 1;

    for(int v : adjList[u]) {
        if(v != parent) {
            dfs(v, u);
            dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
            dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, 0);

    long long ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;

    return 0;
}