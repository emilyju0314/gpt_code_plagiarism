#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> cells(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j += 2) {
            cin >> cells[i][j/2].first >> cells[i][j/2].second;
        }
    }

    vector<vector<char>> board(n, vector<char>(n, 'X'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto [x, y] = cells[i][j];
            if (x == -1) {
                board[i][j] = 'X';
            } else {
                int newX = x - 1;
                int newY = y - 1;

                if (board[newX][newY] == 'X' || board[newX][newY] == 'U') {
                    board[i][j] = 'D';
                } else if (board[newX][newY] == 'D') {
                    board[i][j] = 'U';
                } else if (board[newX][newY] == 'L') {
                    board[i][j] = 'R';
                } else if (board[newX][newY] == 'R') {
                    board[i][j] = 'L';
                } else {
                    board[i][j] = 'U';
                }
            }
        }
    }

    cout << "VALID" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}