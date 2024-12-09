#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Advertisement {
    int points;
    int time;
    int max_watch;
};

int dfs(int node, int time_left, vector<vector<int>>& graph, vector<Advertisement>& ads, vector<vector<int>>& dp) {
    if (time_left <= 0) return 0;
    if (dp[node][time_left] != -1) return dp[node][time_left];
    
    int max_points = 0;
    
    for (int i = 0; i < ads[node].max_watch; ++i) {
        int cur_points = i * ads[node].points;
        int cur_time = i * ads[node].time;
        
        if (time_left - cur_time >= 0) {
            max_points = max(max_points, cur_points + dfs(node, time_left - cur_time, graph, ads, dp));
        } else {
            break;
        }
    }
    
    for(int neighbor : graph[node]) {
        max_points = max(max_points, dfs(neighbor, time_left, graph, ads, dp));
    }
    
    return dp[node][time_left] = max_points;
}

int main() {
    int N, M, T;
    
    while (true) {
        cin >> N >> M >> T;
        
        if (N == 0 && M == 0 && T == 0) {
            break;
        }
        
        vector<Advertisement> ads(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> ads[i].points >> ads[i].time >> ads[i].max_watch;
        }
        
        vector<vector<int>> graph(N);
        
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
        }
        
        vector<vector<int>> dp(N, vector<int>(T + 1, -1));
        
        int max_points = 0;
        
        for (int i = 0; i < N; ++i) {
            max_points = max(max_points, dfs(i, T, graph, ads, dp));
        }
        
        cout << max_points << endl;
    }
    
    return 0;
}