#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> board(n);
        for(int i = 0; i < n; i++) {
            cin >> board[i];
        }
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int max_steps = 0, start_x = 1, start_y = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    int curr_x = i, curr_y = j, steps = 0;
                    unordered_map<char, pair<int, int>> dirs = {{'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};
                    
                    while(!visited[curr_x][curr_y]) {
                        visited[curr_x][curr_y] = true;
                        steps++;
                        char direction = board[curr_x][curr_y];
                        int new_x = curr_x + dirs[direction].first;
                        int new_y = curr_y + dirs[direction].second;
                        
                        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
                            break;
                        }
                        curr_x = new_x;
                        curr_y = new_y;
                    }
                    
                    if(steps > max_steps) {
                        max_steps = steps;
                        start_x = i + 1;
                        start_y = j + 1;
                    }
                }
            }
        }
        
        cout << start_x << " " << start_y << " " << max_steps << endl;
    }
    
    return 0;
}