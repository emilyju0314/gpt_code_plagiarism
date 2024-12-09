#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x1 - 1, y1 - 1, 0));
    visited[x1 - 1][y1 - 1] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x, y, steps;
        tie(x, y, steps) = q.front();
        q.pop();

        if (x == x2 - 1 && y == y2 - 1) {
            cout << steps << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            for (int k = 1; k <= K; k++) {
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;

                if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '@') {
                    break;
                }

                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(make_tuple(nx, ny, steps + 1));
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}