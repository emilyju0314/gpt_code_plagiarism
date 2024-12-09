#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> w(N);
    for(int i = 0; i < N; i++) {
        cin >> w[i];
    }

    unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(N+1, false);
    vector<int> dp(N+1, 0);

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dp[i] = w[i-1];
            for(auto neighbor : adjList[i]) {
                dp[neighbor] = max(dp[neighbor], dp[i]);
            }
        }
    }

    int maxSum = 0;
    for(int i = 1; i <= N; i++) {
        maxSum += dp[i];
    }

    cout << maxSum << endl;

    return 0;
}