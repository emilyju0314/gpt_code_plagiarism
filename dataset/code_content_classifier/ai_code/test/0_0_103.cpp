#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        int max_steps = 0, start_row = 1, start_col = 1;

        // Simulate movement starting from each cell
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int row = r, col = c, steps = 1;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                
                while (!visited[row][col]) {
                    visited[row][col] = true;

                    if (board[row][col] == 'L') {
                        if (col == 0) break;
                        col--;
                    } else if (board[row][col] == 'R') {
                        if (col == m - 1) break;
                        col++;
                    } else if (board[row][col] == 'U') {
                        if (row == 0) break;
                        row--;
                    } else {
                        if (row == n - 1) break;
                        row++;
                    }

                    steps++;
                }

                if (steps > max_steps) {
                    max_steps = steps;
                    start_row = r + 1;
                    start_col = c + 1;
                }
            }
        }

        cout << start_row << " " << start_col << " " << max_steps << endl;
    }

    return 0;
}