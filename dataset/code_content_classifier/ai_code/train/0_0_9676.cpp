#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 5;

vector<int> adj[MAXN];
int dp[MAXN][3]; // dp[i][j] represents the maximum depth of j-ary heap rooted at node i

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        for(int j = 0; j < 3; j++) {
            dp[u][j] = max(dp[u][j], dp[v][j]);
        }
    }
    sort(dp[u], dp[u]+3, greater<int>());
    dp[u][0]++;
    dp[u][2] = max(dp[u][2], dp[u][1]);
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int result = 0;
    for(int i = 1; i <= n; i++) {
        result += dp[i][0] + dp[i][1] + dp[i][2];
    }

    cout << result << endl;

    return 0;
}