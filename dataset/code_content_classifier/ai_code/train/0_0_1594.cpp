#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

int r, c;
char forest[1005][1005];
int visited[1005][1005];
int numBreeder = 0;

bool isValid(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c && forest[x][y] != 'T');
}

int bfs(int startX, int startY) {
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = 1;
    int battles = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (forest[current.x][current.y] != 'S' && forest[current.x][current.y] != 'E' && forest[current.x][current.y] != '0') {
            battles += forest[current.x][current.y] - '0';
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = 1;
            }
        }
    }

    return battles;
}

int main() {
    cin >> r >> c;

    int startX, startY;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> forest[i][j];
            if (forest[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }

    int battles = bfs(startX, startY);

    cout << battles << endl;

    return 0;
}