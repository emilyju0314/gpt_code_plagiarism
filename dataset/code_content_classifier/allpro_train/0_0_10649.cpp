#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int i, int j, int H, int W) {
    return (i >= 0 && i < H && j >= 0 && j < W);
}

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (auto dir : directions) {
            int new_i = i + dir.first;
            int new_j = j + dir.second;

            if (isValid(new_i, new_j, grid.size(), grid[0].size()) && grid[new_i][new_j] != '#' && !visited[new_i][new_j]) {
                visited[new_i][new_j] = true;
                q.push({new_i, new_j});
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<pair<int, int>> cities;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                cities.push_back({i, j});
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(cities[0]);

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited[cities[0].first][cities[0].second] = true;

    bfs(grid, visited, q);

    grid[cities[1].first][cities[1].second] = '*';

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                grid[i][j] = '.';
            }
        }
    }

    for (auto row : grid) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}