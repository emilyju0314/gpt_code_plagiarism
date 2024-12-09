#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_H = 11;
const int MAX_W = 11;
const int INF = 1e9;

int H, W;
char lab[MAX_H][MAX_W];
int dist[MAX_H][MAX_W][1 << 6];

// Struct to represent Dr. Nakamura's position
struct pos {
    int x, y, mask;
    pos(int x, int y, int mask) : x(x), y(y), mask(mask) {}
};

// Possible movements
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// BFS to find the minimum number of movements for Dr. Nakamura to escape
int bfs(int sx, int sy) {
    memset(dist, INF, sizeof(dist));
    queue<pos> q;
    q.push(pos(sx, sy, 0));
    dist[sx][sy][0] = 0;

    while (!q.empty()) {
        pos curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || lab[nx][ny] == '#') {
                continue;
            }

            char cell = lab[nx][ny];
            int mask = curr.mask;

            if (cell == 'E' && mask == 0) {
                return dist[curr.x][curr.y][mask] + 1;
            }

            if (cell == 'w') {
                mask |= (1 << (lab[nx][ny] - 'a'));
            }

            if (cell == 'c' && (lab[nx + dx[i]][ny + dy[i]] == '#' || lab[nx + dx[i]][ny + dy[i]] == 'c')) {
                continue;
            }

            if (dist[nx][ny][mask] == INF) {
                dist[nx][ny][mask] = dist[curr.x][curr.y][mask] + 1;
                q.push(pos(nx, ny, mask));
            }
        }
    }

    return -1;
}

int main() {
    while (cin >> H >> W && (H != 0 || W != 0)) {
        int sx, sy;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> lab[i][j];
                if (lab[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }

        int ans = bfs(sx, sy);
        cout << ans << endl;
    }

    return 0;
}