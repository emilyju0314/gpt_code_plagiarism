#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));
    pair<int, int> start, target;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'G') {
                target = {i, j};
            }
        }
    }

    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == '#' || dist[nx][ny] != -1) {
                continue;
            }

            if (grid[nx][ny] == '.' || grid[nx][ny] == 'G') {
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                q.push({nx, ny});
            } else if (grid[nx][ny] == 'o' || grid[nx][ny] == 'x') {
                dist[nx][ny] = dist[curr.first][curr.second] + 2;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[target.first][target.second] << endl;

    return 0;
}