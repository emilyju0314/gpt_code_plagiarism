#include <iostream>
using namespace std;

int main() {
    char board[8][8];
    
    // Reading the board configuration
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    
    bool whiteWins = false;
    bool blackWins = false;
    
    // Checking for winning condition for player A (white)
    for(int j = 0; j < 8; j++) {
        if(board[0][j] == 'W') {
            whiteWins = true;
            break;
        }
    }
    
    // Checking for winning condition for player B (black)
    for(int j = 0; j < 8; j++) {
        if(board[7][j] == 'B') {
            blackWins = true;
            break;
        }
    }
    
    // Determining the winner
    if(whiteWins) {
        cout << "A" << endl;
    } else if(blackWins) {
        cout << "B" << endl;
    }
    
    return 0;
}