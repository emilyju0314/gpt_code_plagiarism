#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 19;
const int M = 15;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Point {
    int x, y, jump;
};

int main() {
    char board[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    queue<Point> q;
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(31, false)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'O') {
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (board[p.x][p.y] == 'X' || visited[p.x][p.y][p.jump]) {
            continue;
        }

        visited[p.x][p.y][p.jump] = true;

        if (p.x == N - 1) {
            cout << p.jump << endl;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int njump = p.jump + (board[nx][ny] == 'X');

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && njump <= 30) {
                q.push({nx, ny, njump});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}