#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    pair<int, int> start;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'P') {
                start = make_pair(i, j);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int icebergsSmashed = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        if (grid[x][y] == '+') {
            if ((x > 0 && grid[x-1][y] == '#') || (x < H-1 && grid[x+1][y] == '#') || 
                (y > 0 && grid[x][y-1] == '#') || (y < W-1 && grid[x][y+1] == '#')) {
                icebergsSmashed++;
                grid[x][y] = '#';
            }
        }

        if (x > 0 && !visited[x-1][y] && grid[x-1][y] != '#') {
            visited[x-1][y] = true;
            q.push(make_pair(x-1, y));
        }
        if (x < H-1 && !visited[x+1][y] && grid[x+1][y] != '#') {
            visited[x+1][y] = true;
            q.push(make_pair(x+1, y));
        }
        if (y > 0 && !visited[x][y-1] && grid[x][y-1] != '#') {
            visited[x][y-1] = true;
            q.push(make_pair(x, y-1));
        }
        if (y < W-1 && !visited[x][y+1] && grid[x][y+1] != '#') {
            visited[x][y+1] = true;
            q.push(make_pair(x, y+1));
        }
    }

    cout << icebergsSmashed << endl;

    return 0;
}