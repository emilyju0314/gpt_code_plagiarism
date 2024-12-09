#include <iostream>
using namespace std;

int main() {
    char board[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }

    bool possible = false;

    // Horizontal check
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            if(board[i][j] == '.' && board[i][j+1] == 'x' && board[i][j+2] == 'x') {
                possible = true;
            }
        }
    }

    // Vertical check
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] == '.' && board[i+1][j] == 'x' && board[i+2][j] == 'x') {
                possible = true;
            }
        }
    }

    // Diagonal check
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(board[i][j] == '.' && board[i+1][j+1] == 'x' && board[i+2][j+2] == 'x') {
                possible = true;
            }
        }
    }

    // Anti-diagonal check
    for(int i = 0; i < 2; i++) {
        for(int j = 2; j < 4; j++) {
            if(board[i][j] == '.' && board[i+1][j-1] == 'x' && board[i+2][j-2] == 'x') {
                possible = true;
            }
        }
    }

    if(possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}