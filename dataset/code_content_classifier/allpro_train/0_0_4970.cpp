#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> maze(2);
    cin >> maze[0] >> maze[1];

    vector<vector<int>> dist(2, vector<int>(2 * n, INF));
    
    // Breadth-first search to find the shortest path from start to end
    auto bfs = [&](int start, int end) {
        queue<int> q;
        q.push(start);
        dist[start / n][start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int x = u / n;
            int y = u % n;

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    if (abs(dx) + abs(dy) == 2) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= 2 || ny < 0 || ny >= n) continue;
                    if (maze[nx][ny] == 'X') continue;

                    int v = nx * n + ny;
                    if (dist[nx][v] == INF) {
                        dist[nx][v] = dist[x][u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        // If the end cell is not reachable, return -1
        if (dist[end / n][end] == INF) {
            return -1;
        }

        return dist[end / n][end];
    };

    // Process each query
    for (int i = 0; i < m; ++i) {
        int vi, ui;
        cin >> vi >> ui;
        cout << bfs(vi - 1, ui - 1) << endl;
    }

    return 0;
}