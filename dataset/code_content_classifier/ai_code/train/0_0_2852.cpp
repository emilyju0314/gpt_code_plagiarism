#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<int>> grid;
vector<vector<int>> dist;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && dist[x][y] == -1;
}

int bfs() {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (isValid(nx, ny)) {
                dist[nx][ny] = dist[x][y];
                q.push({nx, ny});
            }
        }
    }

    return dist[n-1][m-1];
}

int main() {
    cin >> n >> m >> k;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    dist = vector<vector<int>>(n, vector<int>(m, -1));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    int min_rocks = bfs();
    cout << min_rocks << endl;

    return 0;
}