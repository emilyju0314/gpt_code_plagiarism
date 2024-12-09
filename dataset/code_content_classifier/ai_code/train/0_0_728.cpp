#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dp;

int dfs(int node) {
    if(dp[node] != -1) {
        return dp[node];
    }

    int ans = 0;
    for(auto edge : graph[node]) {
        ans = max(ans, 1 + dfs(edge.first));
    }

    return dp[node] = ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    dp.assign(n + 1, -1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;

    return 0;
}