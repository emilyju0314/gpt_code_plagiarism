#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y, dist;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> room(n);
    for (int i = 0; i < n; i++) {
        cin >> room[i];
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<Point> q;
    q.push({x1, y1, 0});
    visited[x1][y1] = true;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == x2 && p.y == y2) {
            cout << p.dist << endl;
            return 0;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = p.x + dx[j] * i;
                int ny = p.y + dy[j] * i;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || room[nx][ny] == '#' || visited[nx][ny]) {
                    break;
                }

                visited[nx][ny] = true;
                q.push({nx, ny, p.dist + 1});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}