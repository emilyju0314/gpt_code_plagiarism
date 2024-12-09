#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int i, j, top, south, east, penalty;
};

int main() {
    int h, w;
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        
        vector<vector<int>> grid(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        
        int start_i, start_j, goal_i, goal_j;
        cin >> start_i >> start_j >> goal_i >> goal_j;
        
        vector<vector<vector<vector<int>>> dp(h, vector<vector<vector<int>>>(w, vector<vector<int>>(6, vector<int>(6, -1))));
        queue<State> q;
        q.push({start_i, start_j, 1, 2, 3, 0});
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            if (dp[curr.i][curr.j][curr.top][curr.south][curr.east] != -1) {
                continue;
            }
            dp[curr.i][curr.j][curr.top][curr.south][curr.east] = curr.penalty;
            
            int di[] = {-1, 0, 1, 0};
            int dj[] = {0, 1, 0, -1};
            
            for (int k = 0; k < 4; k++) {
                int new_i = curr.i + di[k];
                int new_j = curr.j + dj[k];
                if (new_i < 0 || new_i >= h || new_j < 0 || new_j >= w) {
                    continue;
                }
                
                int new_penalty = curr.penalty + grid[new_i][new_j] * (7 - curr.top);
                int new_top = curr.south;
                int new_south = 7 - curr.top;
                int new_east = curr.east;
                
                if (dp[new_i][new_j][new_top][new_south][new_east] == -1) {
                    q.push({new_i, new_j, new_top, new_south, new_east, new_penalty});
                }
            }
        }
        
        cout << dp[goal_i][goal_j][1][2][3] << endl;
    }
    
    return 0;
}