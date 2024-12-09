#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<Point> q;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j];
            if (grid[i][j] == '.') {
                dist[i][j] = 0;
                q.push(Point(i, j));
            }
        }
    }

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (isValid(newX, newY, n, m) && dist[newX][newY] > dist[x][y] + 1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push(Point(newX, newY));
            }
        }
    }

    int minCost = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= '1' && grid[i][j] <= '3') {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        if (grid[k][l] >= '1' && grid[k][l] <= '3' && dist[k][l] != INT_MAX) {
                            minCost = min(minCost, dist[k][l]);
                        }
                    }
                }
            }
        }
    }

    if (minCost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCost - 2 << endl;
    }

    return 0;
}