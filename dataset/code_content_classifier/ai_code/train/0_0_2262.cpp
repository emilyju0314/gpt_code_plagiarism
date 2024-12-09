#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canTileBoard(vector<string>& board) {
    int n = board.size();

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                count++;
                if (count % 5 == 0) {
                    board[i][j] = '#';
                    continue;
                }
                if (i < n - 2 && j < n - 1 && board[i + 1][j] == '.' && board[i + 1][j + 1] == '.' && board[i + 2][j] == '.' && board[i + 2][j + 1] == '.') {
                    board[i][j] = board[i + 1][j] = board[i + 1][j + 1] = board[i + 2][j] = board[i + 2][j + 1] = '#';
                    count += 4;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    if (canTileBoard(board)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}