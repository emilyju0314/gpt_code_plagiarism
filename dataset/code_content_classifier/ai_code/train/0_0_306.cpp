#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 50;
const int INF = 1e9;

int n, m, k;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN][5];
pair<int, int> parent[MAXN][MAXN][5];

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m >> k;

    int start_x, start_y, end_x, end_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'T') {
                end_x = i;
                end_y = j;
            }
            for (int l = 0; l <= k; l++) {
                dist[i][j][l] = INF;
            }
        }
    }

    dist[start_x][start_y][0] = 0;

    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (isValid(new_x, new_y)) {
                int new_type = grid[new_x][new_y] == grid[x][y] ? 0 : 1;

                if (dist[new_x][new_y][new_type] == INF) {
                    dist[new_x][new_y][new_type] = dist[x][y][grid[new_x][new_y] == grid[x][y] ? 0 : 1] + 1;
                    parent[new_x][new_y][new_type] = {x, y};
                    q.push({new_x, new_y});
                }
            }
        }
    }

    if (dist[end_x][end_y][0] == INF && dist[end_x][end_y][1] == INF) {
        cout << "-1" << endl;
    } else {
        int min_dist = min(dist[end_x][end_y][0], dist[end_x][end_y][1]);
        string path = "";
        int x = end_x, y = end_y, type = dist[end_x][end_y][0] < dist[end_x][end_y][1] ? 0 : 1;

        while (x != start_x || y != start_y) {
            pair<int, int> next = parent[x][y][type];
            if (next.first == x) {
                path += grid[x][y];
            }
            x = next.first;
            y = next.second;
            type = grid[x][y] == grid[next.first][next.second] ? 0 : 1;
        }

        reverse(path.begin(), path.end());
        cout << path << endl;
    }

    return 0;
}