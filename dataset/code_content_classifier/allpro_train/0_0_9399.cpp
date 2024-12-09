#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<vector<char>> museum;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int pictures = 0;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && museum[new_x][new_y] == '*' && !visited[new_x][new_y]) {
                pictures++;
            }
        }

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && museum[new_x][new_y] == '.' && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }

    return pictures;
}

int main() {
    cin >> n >> m >> k;
    museum.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> museum[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        visited.assign(n, vector<bool>(m, false));
        cout << bfs(x, y) << endl;
    }

    return 0;
}