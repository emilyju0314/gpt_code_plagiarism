#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<bool>> vis;

bool isValid(int x, int y, char dir, vector<string>& grid, vector<string>& prohibit) {
    if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == '#' || vis[x][y]) return false;

    for (string& p : prohibit) {
        int px = x, py = y;
        for (char c : p) {
            px += moves[c - 'L'][0];
            py += moves[c - 'L'][1];

            if (px == x && py == y) return false;
        }
    }

    return true;
}

int bfs(vector<string>& grid, vector<string>& prohibit, pii start, pii end) {
    queue<pair<pii, int>> q;
    q.push({start, 0});
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first.first + moves[i][0];
            int ny = curr.first.second + moves[i][1];

            if (isValid(nx, ny, i, grid, prohibit)) {
                if (nx == end.first && ny == end.second) {
                    return curr.second + 1;
                }
                q.push({{nx, ny}, curr.second + 1});
                vis[nx][ny] = true;
            }
        }
    }

    return -1;
}

int main() {
    while (cin >> N >> M && N != 0 && M != 0) {
        vector<string> grid(N);
        int sX, sY, gX, gY;

        for (int i = 0; i < N; i++) {
            cin >> grid[i];
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'S') {
                    sX = i;
                    sY = j;
                } else if (grid[i][j] == 'G') {
                    gX = i;
                    gY = j;
                }
            }
        }

        int P;
        cin >> P;
        vector<string> prohibit(P);

        for (int i = 0; i < P; i++) {
            cin >> prohibit[i];
        }

        vis = vector<vector<bool>>(N, vector<bool>(M, false));
        int res = bfs(grid, prohibit, {sX, sY}, {gX, gY});
        cout << res << endl;
    }

    return 0;
}