#include <iostream>
#include <vector>

using namespace std;

bool isReachable(int x, int y, vector<vector<char>>& labyrinth, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[x][y] = true;

    for (int i = 1; i <= x; i++) {
        if (labyrinth[x - i][y] == '*') break;  // Obstacle found
        visited[x - i][y] = true;
    }

    for (int i = 1; i <= y; i++) {
        if (labyrinth[x][y - i] == '*') break;  // Obstacle found
        visited[x][y - i] = true;
    }

    for (int i = 1; i <= m - y; i++) {
        if (labyrinth[x][y + i] == '*') break;  // Obstacle found
        visited[x][y + i] = true;
    }

    return visited;
}

int main() {
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;

    vector<vector<char>> labyrinth(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
        }
    }

    vector<vector<bool>> reachableCells(n, vector<bool>(m, false));

    reachableCells = isReachable(r - 1, c - 1, labyrinth, n, m);

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (reachableCells[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}