#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Cell {
    int x, y, cost;
};

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    priority_queue<Cell, vector<Cell>, function<bool(Cell, Cell)>> pq([](Cell a, Cell b) {
        return a.cost > b.cost;
    });
    pq.push({0, 0, 0});

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();

        for (auto dir : directions) {
            int nx = curr.x + dir.first;
            int ny = curr.y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != -1) {
                int new_cost = curr.cost + (grid[nx][ny] == 0 ? w : grid[nx][ny]);
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({nx, ny, new_cost});
                }
            }
        }
    }

    int min_time = dist[n-1][m-1];
    if (min_time == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_time << endl;
    }

    return 0;
}