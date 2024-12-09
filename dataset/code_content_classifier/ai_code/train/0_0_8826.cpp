#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>

using namespace std;

const int MAX = 51;
const int INF = 1e9;

int W, H;
char maze[MAX][MAX];
int switchState[MAX][MAX][26];
int dist[MAX][MAX][2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y, int floor) {
    return x >= 0 && x < W && y >= 0 && y < H && maze[y][x] != '#';
}

int bfs() {
    queue<tuple<int, int, int>> q;

    // Initialize distances
    memset(dist, INF, sizeof(dist));

    // Start grid
    int startX, startY;
    bool startFloor = false;

    // Find start grid
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (maze[y][x] == '%') {
                startX = x;
                startY = y;
            }
        }
    }

    q.push(make_tuple(startX, startY, startFloor));
    dist[startY][startX][startFloor] = 0;

    while (!q.empty()) {
        int x, y, floor;
        tie(x, y, floor) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, floor)) {
                if (maze[newY][newX] == '&') {
                    return dist[y][x][floor] + 1;
                } else if (maze[newY][newX] == '|' && maze[y][x] == '|') {
                    if (dist[newY][newX][!floor] == INF) {
                        dist[newY][newX][!floor] = dist[y][x][floor] + 1;
                        q.push(make_tuple(newX, newY, !floor));
                    }
                } else if (islower(maze[newY][newX]) || isupper(maze[newY][newX])) {
                    char switchChar = tolower(maze[newY][newX]);
                    int nextState = switchState[y][x][switchChar];
                    
                    if (nextState == !floor) {
                        if (dist[newY][newX][nextState] == INF) {
                            dist[newY][newX][nextState] = dist[y][x][floor] + 1;
                            q.push(make_tuple(newX, newY, nextState));
                        }
                    }
                } else {
                    if (dist[newY][newX][floor] == INF) {
                        dist[newY][newX][floor] = dist[y][x][floor] + 1;
                        q.push(make_tuple(newX, newY, floor));
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> W >> H;

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> maze[y][x];
        }
    }

    int numSwitches;
    cin >> numSwitches;

    for (int k = 0; k < numSwitches; k++) {
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                cin >> switchState[y][x][k];
            }
        }
    }

    int result = bfs();

    cout << result << endl;

    return 0;
}