#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<vector<int>>> dist;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '*';
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int turns = dist[x][y][0];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;

            if (isValid(newX, newY) && dist[newX][newY][turns] == -1) {
                dist[newX][newY][turns] = dist[x][y][turns] + 1;
                q.push({newX, newY});
            }
        }

        if (turns + 1 <= 2) {
            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i].first;
                int newY = y + directions[i].second;

                if (isValid(newX, newY) && dist[newX][newY][turns + 1] == -1) {
                    dist[newX][newY][turns + 1] = dist[x][y][turns] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    dist.resize(n, vector<vector<int>>(m, vector<int>(3, -1));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'T') {
                end = {i, j};
            }
        }
    }

    bfs(start);

    if (dist[end.first][end.second][0] != -1 || dist[end.first][end.second][1] != -1 || dist[end.first][end.second][2] != -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}