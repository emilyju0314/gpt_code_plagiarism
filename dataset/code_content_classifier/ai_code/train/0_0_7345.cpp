#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<vector<int>> board(5, vector<int>(5, 0));

        for (int i = 0; i < n; i++) {
            int d, p, q;
            cin >> d >> p >> q;

            if (d == 1) {
                int row = 0;
                while (row < 5 && board[row][q-1] == 0) {
                    row++;
                }
                row--;

                for (int j = 0; j < p; j++) {
                    board[row][q-1+j] = 1;
                }
            } else {
                int col = 0;
                while (col < 5 && board[col][q-1] == 0) {
                    col++;
                }
                col--;

                for (int j = 0; j < p; j++) {
                    board[col+j][q-1] = 1;
                }
            }

            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                bool full = true;
                for (int k = 0; k < 5; k++) {
                    if (board[k][j] == 0) {
                        full = false;
                        break;
                    }
                }
                if (full) {
                    cnt++;
                    for (int k = 0; k < 5; k++) {
                        board[k][j] = 0;
                    }
                }
            }

            for (int j = 0; j < 5; j++) {
                for (int k = 4; k >= 0; k--) {
                    if (board[k][j] == 1) {
                        int row = k+cnt;
                        while (row < 5 && board[row][j] == 0) {
                            board[row][j] = 1;
                            board[row-cnt][j] = 0;
                            row++;
                        }
                    }
                }
            }
        }

        int remaining = 0;
        for (int i = 0; i < 5; i++) {
            if (board[4][i] == 1) {
                remaining++;
            }
        }

        cout << remaining << endl;
    }

    return 0;
}