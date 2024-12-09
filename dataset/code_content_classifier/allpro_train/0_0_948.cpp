#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    vector<string> grid(n);
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(a + 1, vector<bool>(4, false)));

    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; i++) {
        q.push({sx, sy, a, i});
        visited[sx][sy][a][i] = true;
    }

    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int mirrors = 0;

    while (!q.empty()) {
        auto [x, y, k, d] = q.front();
        q.pop();

        if (x == ex && y == ey) {
            cout << mirrors << endl;
            return 0;
        }

        int nx = x + dirs[d][0];
        int ny = y + dirs[d][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
            if (k > 0) {
                for (int i = 0; i < 4; i++) {
                    if (i != d && !visited[x][y][k - 1][i]) {
                        q.push({x, y, k - 1, i});
                        visited[x][y][k - 1][i] = true;
                    }
                }
            }
        } else {
            if (!visited[nx][ny][k][d]) {
                q.push({nx, ny, k, d});
                visited[nx][ny][k][d] = true;
            }
        }

        mirrors++;
    }

    cout << -1 << endl;

    return 0;
}