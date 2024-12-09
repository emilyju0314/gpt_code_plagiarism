#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> maze(H, vector<char>(W));
    vector<vector<int>> dist(H, vector<int>(W, -1));

    int C_h, C_w, D_h, D_w;
    cin >> C_h >> C_w >> D_h >> D_w;
    C_h--, C_w--, D_h--, D_w--;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> maze[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({C_h, C_w});
    dist[C_h][C_w] = 0;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto move : moves) {
            int ni = i + move.first;
            int nj = j + move.second;

            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (maze[ni][nj] == '#') continue;
            if (dist[ni][nj] != -1) continue;

            dist[ni][nj] = dist[i][j];
            q.push({ni, nj});
        }

        for (int x = i - 2; x <= i + 2; x++) {
            for (int y = j - 2; y <= j + 2; y++) {
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (maze[x][y] == '#') continue;
                if (dist[x][y] != -1) continue;

                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    cout << dist[D_h][D_w] << endl;

    return 0;
}