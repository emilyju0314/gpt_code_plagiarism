#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // North, South, West, East

bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(vector<string>& grid, vector<vector<int>>& windInfo, int days, int n, int m, int k) {
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'P') {
                dp[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = currX + dirs[i][0];
            int newY = currY + dirs[i][1];
            
            if (isValid(newX, newY, n, m) && grid[newX][newY] != 'L' && dp[currX][currY] + 1 < dp[newX][newY]) {
                if (dp[currX][currY] + 1 <= k || (windInfo[newX][newY] == i && dp[currX][currY] < k)) {
                    dp[newX][newY] = dp[currX][currY] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    
    return dp;
}

int main() {
    int n, m, k, t, w;
    cin >> n >> m >> k >> t >> w;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<vector<int>> windInfo(n, vector<int>(m));
    string wind;
    cin >> wind;
    for (int i = 0; i < w; i++) {
        if (wind[i] == 'N') windInfo[i/w][i%w] = 0;
        else if (wind[i] == 'S') windInfo[i/w][i%w] = 1;
        else if (wind[i] == 'W') windInfo[i/w][i%w] = 2;
        else if (wind[i] == 'E') windInfo[i/w][i%w] = 3;
        else windInfo[i/w][i%w] = -1;
    }
    
    vector<int> shopX, shopY, shopDay;
    for (int i = 0; i < t; i++) {
        int x, y, day;
        cin >> x >> y >> day;
        shopX.push_back(x);
        shopY.push_back(y);
        shopDay.push_back(day);
    }
    
    int minDays = INT_MAX;
    for (int i = 0; i < t; i++) {
        vector<vector<int>> dp = bfs(grid, windInfo, w, n, m, k+shopDay[i]);
        if (dp[shopY[i]][shopX[i]] != INT_MAX) {
            minDays = min(minDays, dp[shopY[i]][shopX[i]]);
        }
    }
    
    if (minDays == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minDays << endl;
    }
    
    return 0;
}