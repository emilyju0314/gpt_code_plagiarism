#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(vector<vector<char>>& board, int n, int m, int i, int j, vector<vector<bool>>& visited, char target, int prevX, int prevY) {
    visited[i][j] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nextX = i + dx[k];
        int nextY = j + dy[k];

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && board[nextX][nextY] == target && !(nextX == prevX && nextY == prevY)) {
            if (visited[nextX][nextY] || hasCycle(board, n, m, nextX, nextY, visited, target, i, j)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (hasCycle(board, n, m, i, j, visited, board[i][j], -1, -1)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}