#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, males, females;
vector<string> grid;
vector<vector<vector<int>>> dist;
vector<vector<vector<int>>> visited;

struct Scayger {
    int x, y, time;
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfs(int sx, int sy, int scaygers) {
    dist.assign(n, vector<vector<int>>(m, vector<int>(scaygers, INF)));
    visited.assign(n, vector<vector<int>>(m, vector<int>(scaygers, false));

    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < scaygers; i++) {
        q.push({0, {sx, sy}});
        dist[sx][sy][i] = 0;
    }

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int scaygerIdx = q.front().first;
        q.pop();

        if (visited[x][y][scaygerIdx]) continue;
        visited[x][y][scaygerIdx] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny) && dist[nx][ny][scaygerIdx] > dist[x][y][scaygerIdx] + 1) {
                dist[nx][ny][scaygerIdx] = dist[x][y][scaygerIdx] + 1;
                q.push({scaygerIdx, {nx, ny}});
            }
        }
    }
}

int main() {
    cin >> n >> m >> males >> females;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx, sy, st;
    cin >> sx >> sy >> st;

    vector<Scayger> maleScaygers(males);
    vector<Scayger> femaleScaygers(females);

    for (int i = 0; i < males; i++) {
        cin >> maleScaygers[i].x >> maleScaygers[i].y >> maleScaygers[i].time;
    }

    for (int i = 0; i < females; i++) {
        cin >> femaleScaygers[i].x >> femaleScaygers[i].y >> femaleScaygers[i].time;
    }

    int minTime = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                bfs(i, j, males + females);
                int totalTime = 0;
                for (int k = 0; k < males; k++) {
                    totalTime = max(totalTime, dist[femaleScaygers[k].x][femaleScaygers[k].y][k]);
                }
                for (int k = 0; k < females; k++) {
                    totalTime = max(totalTime, dist[maleScaygers[k].x][maleScaygers[k].y][males + k]);
                }
                totalTime = max(totalTime, dist[sx][sy][males + females - 1]);
                minTime = min(minTime, totalTime);
            }
        }
    }

    if (minTime == INF) {
        cout << -1 << endl;
    } else {
        cout << minTime << endl;
    }

    return 0;
}