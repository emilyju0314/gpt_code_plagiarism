#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<pair<int, char>>> adj;
vector<vector<int>> dp;

int max_path(int i, int j) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int result = 0;
    for(auto neighbor : adj[i]) {
        if(neighbor.second >= j) {
            result = max(result, max_path(neighbor.first, neighbor.second) ^ 1);
        }
    }

    dp[i][j] = result;
    return result;
}

int main() {
    cin >> n >> m;
    adj.resize(n+1);
    dp.resize(n+1, vector<int>(128, -1));

    for(int i = 0; i < m; i++) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        adj[v].push_back({u, c});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 97; j <= 122; j++) {
            int result = max_path(i, j);
            if(result == 1) {
                cout << 'A';
            } else {
                cout << 'B';
            }
        }
        cout << endl;
    }

    return 0;
}