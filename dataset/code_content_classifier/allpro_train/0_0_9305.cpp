#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<int>> prefixRow(n, vector<int>(m));
    vector<vector<int>> prefixCol(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // Pre-calculate prefix sums for rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefixRow[i][j] = (j == 0 ? board[i][j] : prefixRow[i][j - 1] + board[i][j]);
        }
    }

    // Pre-calculate prefix sums for columns
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            prefixCol[i][j] = (i == 0 ? board[i][j] : prefixCol[i - 1][j] + board[i][j]);
        }
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        
        if (op == 1) {
            board[x - 1][y - 1] = 1 - board[x - 1][y - 1];
            // Update prefix sums for rows
            for (int j = 0; j < m; j++) {
                prefixRow[x - 1][j] = (j == 0 ? board[x - 1][j] : prefixRow[x - 1][j - 1] + board[x - 1][j]);
            }
            // Update prefix sums for columns
            for (int i = 0; i < n; i++) {
                prefixCol[i][y - 1] = (i == 0 ? board[i][y - 1] : prefixCol[i - 1][y - 1] + board[i][y - 1]);
            }
        } else if (op == 2) {
            int ans = 0;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (board[i][j]) {
                        int rowSum = prefixRow[i][j];
                        int colSum = prefixCol[i][j];

                        int area = (i + 1) * (j + 1 - colSum);
                        area = max(area, (i + 1 - rowSum) * (j + 1));

                        ans = max(ans, area);
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}