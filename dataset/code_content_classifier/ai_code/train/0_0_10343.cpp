#include <iostream>
#include <vector>

using namespace std;

bool checkWinner(vector<string>& board, char player) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

string getGameState(vector<string>& board) {
    int countX = 0, countO = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'X') {
                countX++;
            } else if(board[i][j] == '0') {
                countO++;
            }
        }
    }
    
    if(countO > countX || countX > countO + 1) {
        return "illegal";
    }
    
    bool xWins = checkWinner(board, 'X');
    bool oWins = checkWinner(board, '0');
    
    if(xWins && oWins || xWins && countX <= countO || oWins && countX > countO) {
        return "illegal";
    }
    
    if(xWins) {
        return "the first player won";
    }
    
    if(oWins) {
        return "the second player won";
    }
    
    if(countX + countO == 9) {
        return "draw";
    }
    
    if(countX == countO) {
        return "first";
    } else {
        return "second";
    }
}

int main() {
    vector<string> board(3);
    for(int i = 0;i < 3; i++) {
        cin >> board[i];
    }
    
    cout << getGameState(board) << endl;
    
    return 0;
}