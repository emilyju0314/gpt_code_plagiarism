#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool checkRow(const vector<vector<int>> &board, int row) {
    set<int> seen;
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == 0) continue;
        if (seen.count(board[row][col]) == 1) return false;
        seen.insert(board[row][col]);
    }
    return true;
}

bool checkColumn(const vector<vector<int>> &board, int col) {
    set<int> seen;
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == 0) continue;
        if (seen.count(board[row][col]) == 1) return false;
        seen.insert(board[row][col]);
    }
    return true;
}

bool checkBlock(const vector<vector<int>> &board, int startRow, int startCol) {
    set<int> seen;
    for (int row = startRow; row < startRow + 3; row++) {
        for (int col = startCol; col < startCol + 3; col++) {
            if (board[row][col] == 0) continue;
            if (seen.count(board[row][col]) == 1) return false;
            seen.insert(board[row][col]);
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        vector<vector<int>> board(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!checkRow(board, i) || !checkColumn(board, j) || !checkBlock(board, i - i % 3, j - j % 3)) {
                    if (j != 0) {
                        cout << " ";
                    }
                    cout << (board[i][j] == 0 ? " " : "*") << board[i][j];
                } else {
                    if (j != 0) {
                        cout << " ";
                    }
                    cout << " " << board[i][j];
                }
            }
            cout << endl;
        }
        if (n > 0) {
            cout << endl;
        }
    }

    return 0;
}