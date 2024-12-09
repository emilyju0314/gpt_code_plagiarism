#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> labyrinth(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
        }
    }

    int xT, yT, xM, yM;
    cin >> xT >> yT >> xM >> yM;

    xT--, yT--, xM--, yM;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, -1));
    queue<tuple<int, int, int>> q;
    q.push({xT, yT, 0});
    dist[xT][yT][0] = 0;

    while (!q.empty()) {
        int x, y, rot;
        tie(x, y, rot) = q.front();
        q.pop();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        if (x == xM && y == yM) {
            cout << dist[x][y][rot] << endl;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && labyrinth[x][y] != '*' && labyrinth[nx][ny] != '*') {
                int nrot = (rot + 1) % 4;
                if (labyrinth[x][y] == '+' || labyrinth[x][y] == "LRUD"[rot]) {
                    if (dist[nx][ny][nrot] == -1) {
                        dist[nx][ny][nrot] = dist[x][y][rot] + 1;
                        q.push({nx, ny, nrot});
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    
    return 0;
}