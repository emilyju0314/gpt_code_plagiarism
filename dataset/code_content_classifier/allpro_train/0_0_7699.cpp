#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
    int x, y, dir, dist;
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main() {
    int H, W, L;
    cin >> H >> W >> L;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(4, false)));

    int start_x, start_y;
    char start_dir;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
                start_dir = 'N'; // initially upright position
            }
        }
    }

    queue<State> q;
    q.push({start_x, start_y, 0, 0});
    q.push({start_x, start_y, 1, 0});
    q.push({start_x, start_y, 2, 0});
    q.push({start_x, start_y, 3, 0});

    int goal_x, goal_y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'G') {
                goal_x = i;
                goal_y = j;
            }
        }
    }

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == goal_x && curr.y == goal_y && curr.dir == 0) {
            cout << curr.dist << endl;
            return 0;
        }

        if (visited[curr.x][curr.y][curr.dir]) {
            continue;
        }
        visited[curr.x][curr.y][curr.dir] = true;

        for (int k = 0; k < 4; k++) {
            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '#' || visited[nx][ny][curr.dir]) {
                continue;
            }

            if (grid[nx][ny] == '^' && curr.dir != 0) {
                continue;
            }

            int ndist = curr.dist + 1;
            if (k != curr.dir) {
                ndist += L - 1;
            }

            q.push({nx, ny, k, ndist});
        }
    }

    cout << -1 << endl;

    return 0;
}