#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int maxSteps = 0;
        int startX = 0, startY = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = i, y = j;
                int steps = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                while (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    if (board[x][y] == 'L') y--;
                    else if (board[x][y] == 'R') y++;
                    else if (board[x][y] == 'U') x--;
                    else x++;

                    steps++;
                }

                if (steps > maxSteps) {
                    maxSteps = steps;
                    startX = i + 1;
                    startY = j + 1;
                }
            }
        }

        cout << startX << " " << startY << " " << maxSteps << endl;
    }

    return 0;
}