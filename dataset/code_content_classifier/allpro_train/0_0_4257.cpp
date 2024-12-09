#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxScore(vector<int>& scores, vector<vector<int>>& adjList, vector<int>& dp, int city) {
    if(dp[city] != -1) {
        return dp[city];
    }
    
    int maxScore = scores[city];
    for(int nextCity : adjList[city]) {
        maxScore = max(maxScore, scores[city] + maxScore(scores, adjList, dp, nextCity));
    }
    
    dp[city] = maxScore;
    return maxScore;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> scores(n);
    for(int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    vector<vector<int>> adjList(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }
    
    int s;
    cin >> s;
    
    vector<int> dp(n, -1);
    int maxTotalScore = maxScore(scores, adjList, dp, s - 1);
    
    cout << maxTotalScore << endl;
    
    return 0;
}