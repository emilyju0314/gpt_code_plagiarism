#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_CLICKS = 5;
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    vector<vector<int>> grid(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    int clicks = 0;
    bool updated = true;
    while (updated) {
        updated = false;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(4, vector<bool>(4, false));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] >= 5) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (auto dir : directions) {
                int nextX = x + dir.first;
                int nextY = y + dir.second;
                if (nextX >= 0 && nextX < 4 && nextY >= 0 && nextY < 4 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    if (grid[nextX][nextY] < 5) {
                        clicks++;
                        grid[nextX][nextY]++;
                        if (grid[nextX][nextY] >= 5) {
                            q.push({nextX, nextY});
                            updated = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] < 5) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << clicks << endl;

    return 0;
}