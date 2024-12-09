#include <iostream>
#include <vector>

using namespace std;

bool checkWin(vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    
    while (true) {
        for (int i = 0; i < 3; ++i) {
            string line;
            cin >> line;
            if (line == "0") {
                return 0;
            }
            for (int j = 0; j < 3; ++j) {
                board[i][j] = line[j];
            }
        }
        
        bool blackWin = checkWin(board, 'b');
        bool whiteWin = checkWin(board, 'w');
        
        if (blackWin && !whiteWin) {
            cout << "b" << endl;
        } else if (!blackWin && whiteWin) {
            cout << "w" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    
    return 0;
}