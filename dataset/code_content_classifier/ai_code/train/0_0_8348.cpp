#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1605;

int n, m;
int grid[MAXN][MAXN];
int visited[MAXN][MAXN] = {0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y, int& rays) {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (auto dir : directions) {
            int nx = curr.first + dir.first;
            int ny = curr.second + dir.second;

            if (isValid(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }

        rays++;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int suns = 0;
    vector<int> rayCounts;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int rays = 0;
                bfs(i, j, rays);
                suns++;
                rayCounts.push_back(rays);
            }
        }
    }

    cout << suns << endl;
    sort(rayCounts.begin(), rayCounts.end());

    for (int count : rayCounts) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}