#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int row = a; row <= c; row++) {
            for (int col = b; col <= d; col++) {
                board[row][col] = true;
            }
        }
    }

    // Determine the winner
    if ((n / k) % 2 == 0) {
        cout << "Malek" << endl;
    } else {
        int whiteCells = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i + j) % 2 == 1 && board[i][j]) {
                    whiteCells++;
                }
            }
        }

        if (whiteCells % 2 == 0) {
            cout << "Malek" << endl;
        } else {
            cout << "Hamed" << endl;
        }
    }

    return 0;
}