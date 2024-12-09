#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_M = 100005;
const int MAX_N = 100005;

int M, N, K;
bool switches[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];

struct Room {
    int x, y;
    int steps;
};

bool isValid(int x, int y) {
    return x >= 1 && x <= M && y >= 1 && y <= N;
}

int bfs() {
    queue<Room> q;
    q.push({1, 1, 0});
    visited[1][1] = true;

    while (!q.empty()) {
        Room curr = q.front();
        q.pop();

        if (curr.x == M && curr.y == N) {
            return curr.steps;
        }

        // Move to the east room
        int x = curr.x + 1;
        int y = curr.y;
        if (isValid(x, y) && !visited[x][y]) {
            q.push({x, y, curr.steps + 1});
            visited[x][y] = true;
        }

        // Move to the west room
        x = curr.x - 1;
        if (isValid(x, y) && !visited[x][y]) {
            q.push({x, y, curr.steps + 1});
            visited[x][y] = true;
        }

        // Move to the north room
        x = curr.x;
        y = curr.y + 1;
        if (isValid(x, y) && !visited[x][y] && !switches[curr.x][curr.y]) {
            q.push({x, y, curr.steps + 1});
            visited[x][y] = true;
        }

        // Move to the south room
        y = curr.y - 1;
        if (isValid(x, y) && !visited[x][y] && !switches[x][y]) {
            q.push({x, y, curr.steps + 1});
            visited[x][y] = true;
        }
    }

    return -1;
}

int main() {
    cin >> M >> N >> K;

    memset(switches, false, sizeof(switches));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        switches[x][y] = true;
    }

    int result = bfs();

    cout << result << endl;

    return 0;
}