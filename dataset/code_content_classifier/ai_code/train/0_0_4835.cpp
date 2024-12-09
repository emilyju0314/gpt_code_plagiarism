#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    while(true) {
        int X, Y;
        cin >> X >> Y;
        
        if (X == 0 && Y == 0) {
            break;
        }
        
        vector<string> maze(Y);
        pair<int, int> start, goal;
        
        for (int i = 0; i < Y; i++) {
            cin >> maze[i];
            for (int j = 0; j < X; j++) {
                if (maze[i][j] == 'S') {
                    start = make_pair(i, j);
                } else if (maze[i][j] == 'G') {
                    goal = make_pair(i, j);
                }
            }
        }
        
        vector<vector<vector<bool>>> visited(Y, vector<vector<bool>>(X, vector<bool>(64, false)));
        
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(start.first, start.second, 0));
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                int x, y, mask;
                tie(x, y, mask) = q.front();
                q.pop();
                
                if (make_pair(x, y) == goal) {
                    cout << steps << endl;
                    goto END;
                }
                
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    int nmask = mask;
                    
                    if (nx < 0 || nx >= Y || ny < 0 || ny >= X) {
                        continue;
                    }
                    
                    if (visited[nx][ny][nmask]) {
                        continue;
                    }
                    
                    visited[nx][ny][nmask] = true;
                    
                    if (maze[nx][ny] == '.') {
                        q.push(make_tuple(nx, ny, nmask));
                    } else if (maze[nx][ny] == 'X' && (nmask & (1 << 0)) == 0) {
                        nmask |= (1 << 0);
                        q.push(make_tuple(nx, ny, nmask));
                    } else if (maze[nx][ny] == '#' || maze[nx][ny] == 'G') {
                        q.push(make_tuple(nx, ny, nmask));
                    }
                }
            }
            
            steps++;
        }

        END: continue;
    }

    return 0;
}