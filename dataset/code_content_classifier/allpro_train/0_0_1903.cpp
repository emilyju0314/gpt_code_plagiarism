#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<char>> grid;
vector<vector<bool>> visited;

bool isValid(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j] == '#';
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (isValid(x-1, y) && !visited[x-1][y]) {
            q.push({x-1, y});
            visited[x-1][y] = true;
        }
        if (isValid(x+1, y) && !visited[x+1][y]) {
            q.push({x+1, y});
            visited[x+1][y] = true;
        }
        if (isValid(x, y-1) && !visited[x][y-1]) {
            q.push({x, y-1});
            visited[x][y-1] = true;
        }
        if (isValid(x, y+1) && !visited[x][y+1]) {
            q.push({x, y+1});
            visited[x][y+1] = true;
        }
    }
}

int main() {
    cin >> R >> C;
    grid.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int tiles = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                bfs(i, j);
                tiles++;
            }
        }
    }

    cout << tiles << endl;

    return 0;
}