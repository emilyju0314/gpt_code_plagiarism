#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m, k;
vector<string> grid;
vector<vector<vector<int>>> dist;

struct Node {
    int x, y, mask;
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int startX, int startY) {
    dist.assign(n, vector<vector<int>>(m, vector<int>(1 << k, INT_MAX)));
    queue<Node> q;
    q.push({startX, startY, 0});
    dist[startX][startY][0] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curMask = q.front().mask;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (isValid(newX, newY)) {
                int newMask = curMask | (1 << (grid[newX][newY] - 'a'));
                int newDist = dist[curX][curY][curMask] + 1;

                if (newDist < dist[newX][newY][newMask] && __builtin_popcount(newMask) <= k) {
                    dist[newX][newY][newMask] = newDist;
                    q.push({newX, newY, newMask});
                }
            }
        }
    }
}

string findPath(int endX, int endY) {
    string path = "";
    int curX = endX, curY = endY, curMask = 0;

    while (!(curX == 0 && curY == 0)) {
        int minDist = INT_MAX;
        int nextX, nextY, nextMask;

        for (int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (isValid(newX, newY) && dist[newX][newY][curMask] < minDist) {
                minDist = dist[newX][newY][curMask];
                nextX = newX;
                nextY = newY;
                nextMask = curMask;
            }
        }

        curX = nextX;
        curY = nextY;
        curMask = nextMask;
        if (grid[curX][curY] != 'S' && grid[curX][curY] != 'T') {
            path = grid[curX][curY] + path;
        }
    }

    return path;
}

int main() {
    cin >> n >> m >> k;

    grid.resize(n);
    int startX, startY, endX, endY;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'T') {
                endX = i;
                endY = j;
            }
        }
    }

    bfs(startX, startY);

    string path = findPath(endX, endY);

    if (path.empty()) {
        cout << "-1" << endl;
    } else {
        cout << path << endl;
    }

    return 0;
}