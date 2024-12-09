#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> rooms(H, vector<char>(W));
    int sx, sy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> rooms[i][j];
            if (rooms[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (rooms[x][y] == 'E') {
            cout << dist[x][y] << endl;
            return 0;
        }

        int moves = 0;
        while (x + moves > 0 && rooms[x + moves][y] == '.' && dist[x + moves][y] > dist[x][y]) {
            dist[x + moves][y] = dist[x][y];
            q.push({x + moves, y});
            moves++;
        }

        moves = 0;
        while (x - moves < H && rooms[x - moves][y] == '.' && dist[x - moves][y] > dist[x][y]) {
            dist[x - moves][y] = dist[x][y];
            q.push({x - moves, y});
            moves++;
        }

        moves = 0;
        while (y + moves > 0 && rooms[x][y + moves] == '.' && dist[x][y + moves] > dist[x][y]) {
            dist[x][y + moves] = dist[x][y];
            q.push({x, y + moves});
            moves++;
        }

        moves = 0;
        while (y - moves < W && rooms[x][y - moves] == '.' && dist[x][y - moves] > dist[x][y]) {
            dist[x][y - moves] = dist[x][y];
            q.push({x, y - moves});
            moves++;
        }
    }

    return 0;
}