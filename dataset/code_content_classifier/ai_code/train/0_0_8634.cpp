#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, int parent, vector<vector<int>>& adj_list, vector<int>& values, vector<int>& dp) {
    dp[node] = 1;
    for (int child : adj_list[node]) {
        if (child != parent && values[child] > values[node]) {
            dp[node] = max(dp[node], 1 + dfs(child, node, adj_list, values, dp));
        }
    }
    return dp[node];
}

int main() {
    int N;
    cin >> N;

    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj_list(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> dp(N, 0);
    dp[0] = 1;
    dfs(0, -1, adj_list, values, dp);

    for (int i = 0; i < N; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}