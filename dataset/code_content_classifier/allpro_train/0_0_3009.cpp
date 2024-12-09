#include <iostream>
#include <vector>
#include <queue>
#define MOD 1000000007

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<bool>> black(H, vector<bool>(W, false));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        black[x][y] = true;
    }

    long long ans = 0;
    for (int x1 = 0; x1 < H; x1++) {
        for (int y1 = 0; y1 < W; y1++) {
            if (black[x1][y1]) continue;

            vector<vector<int>> dist(H, vector<int>(W, -1));
            queue<pair<int, int>> q;
            q.push({x1, y1});
            dist[x1][y1] = 0;

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !black[nx][ny] && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }

            for (int x2 = 0; x2 < H; x2++) {
                for (int y2 = 0; y2 < W; y2++) {
                    if (!black[x2][y2] && dist[x2][y2] != -1) {
                        ans = (ans + dist[x2][y2]) % MOD;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}