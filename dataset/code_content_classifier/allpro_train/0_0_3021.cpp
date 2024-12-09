#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

int W, H;
char map[30][30];
int visited[30][30][30][30]; // to keep track of visited cells with specific rock/carpet configurations

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int bfs(Point start) {
    queue<pair<Point, int>> q;
    q.push({start, 0});

    while (!q.empty()) {
        Point curr = q.front().first;
        int time = q.front().second;
        q.pop();

        if (map[curr.x][curr.y] == '<') {
            return time;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny) && map[nx][ny] != '#' && visited[curr.x][curr.y][nx][ny] == 0) {
                if (islower(map[nx][ny])) {
                    visited[curr.x][curr.y][nx][ny] = 1; // mark current cell as visited with this carpet
                    visited[nx][ny][nx][ny] = 1; // mark carpet cell as visited

                    // Remove all rocks with same label as this carpet
                    for (int x = 0; x < H; x++) {
                        for (int y = 0; y < W; y++) {
                            if (map[x][y] == toupper(map[nx][ny])) {
                                visited[nx][ny][x][y] = 1; // mark these rocks as visited
                            }
                        }
                    }
                }

                if (map[nx][ny] != '#') {
                    visited[curr.x][curr.y][nx][ny] = 1; // mark current and next cell as visited
                    q.push({{nx, ny}, time + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    while (true) {
        cin >> W >> H;

        if (W == 0 && H == 0) {
            break;
        }

        Point start;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    start = {i, j};
                }
            }
        }

        int result = bfs(start);
        
        cout << result << endl;
    }

    return 0;
}