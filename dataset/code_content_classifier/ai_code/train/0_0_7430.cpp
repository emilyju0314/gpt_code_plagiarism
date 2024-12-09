#include <iostream>
#include <string>

using namespace std;

char checkWinner(string board) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i*3] == board[i*3+1] && board[i*3] == board[i*3+2]) {
            if (board[i*3] == 'o') {
                return 'o';
            } else if (board[i*3] == 'x') {
                return 'x';
            }
        }
        // Check columns
        if (board[i] == board[i+3] && board[i] == board[i+6]) {
            if (board[i] == 'o') {
                return 'o';
            } else if (board[i] == 'x') {
                return 'x';
            }
        }
    }
    // Check diagonals
    if ((board[0] == board[4] && board[0] == board[8]) ||
        (board[2] == board[4] && board[2] == board[6])) {
        if (board[4] == 'o') {
            return 'o';
        } else if (board[4] == 'x') {
            return 'x';
        }
    }
    // If no winner found, it's a draw
    return 'd';
}

int main() {
    string board;
    while (cin >> board) {
        char result = checkWinner(board);
        cout << result << endl;
    }
    return 0;
}