#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> dp(N + 1, 0);
    int result = 0;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            dp[i] = 1; // Base case for nodes with no incoming edges
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    for (int i = 1; i <= N; i++) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}