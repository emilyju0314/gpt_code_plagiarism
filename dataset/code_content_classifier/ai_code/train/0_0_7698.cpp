#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct State {
    int x, y, mask;
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<char>> grid(n, vector<char>(n));
        int startX = -1, startY = -1;
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }

        queue<tuple<int, int, int>> q;
        q.emplace(startX, startY, 0);

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(1 << 9, false)));

        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();

            if (mask == (1 << 9) - 1) {
                cout << visited[x][y][mask] - 1 << endl;
                break;
            }

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }

                int nmask = mask;
                int newInfected = 0;

                if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                    for (int dd = 0; dd < 8; dd++) {
                        int nnx = nx + dx[dd];
                        int nny = ny + dy[dd];

                        if (nnx < 0 || nny < 0 || nnx >= n || nny >= n) {
                            continue;
                        }

                        if (grid[nnx][nny] == '#') {
                            newInfected++;
                        }
                    }

                    if (newInfected == 3) {
                        nmask |= (1 << d);
                    }
                }

                if (!visited[nx][ny][nmask] && newInfected != 3) {
                    visited[nx][ny][nmask] = visited[x][y][mask] + 1;
                    q.emplace(nx, ny, nmask);
                }
            }
        }

        if (q.empty()) {
            cout << -1 << endl;
        }
    }

    return 0;
}