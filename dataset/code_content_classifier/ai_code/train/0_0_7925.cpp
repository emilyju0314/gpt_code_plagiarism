#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_K = 10;
const int MAX_N = 10;
const int MAX_M = 10;

int k, n, m;
char plate[MAX_K][MAX_N][MAX_M];
int visited[MAX_K][MAX_N][MAX_M];

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool isValid(int x, int y, int z) {
    if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= k) {
        return false;
    }
    if (plate[z][x][y] == '#' || visited[z][x][y] == 1) {
        return false;
    }
    return true;
}

int bfs(int x, int y, int z) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, z});
    visited[z][x][y] = 1;
    int minutes = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur_x = q.front().first.first;
            int cur_y = q.front().first.second;
            int cur_z = q.front().second;
            q.pop();

            for (int j = 0; j < 6; j++) {
                int new_x = cur_x + dx[j];
                int new_y = cur_y + dy[j];
                int new_z = cur_z + dz[j];

                if (isValid(new_x, new_y, new_z)) {
                    q.push({{new_x, new_y}, new_z});
                    visited[new_z][new_x][new_y] = 1;
                }
            }
        }
        minutes++;
    }

    return minutes;
}

int main() {
    cin >> k >> n >> m;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin >> plate[i][j][l];
            }
        }
    }

    int x, y;
    cin >> x >> y;
    x--;
    y--;

    memset(visited, 0, sizeof(visited));

    int minutes = bfs(x, y, 0);
    cout << minutes << endl;

    return 0;
}