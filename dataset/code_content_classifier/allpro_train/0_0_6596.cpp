#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    vector<string> board(8);
    
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    bool mariaWins = false;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'M') {
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if (isValid(x, y) && board[x][y] == 'A') {
                        mariaWins = true;
                        break;
                    }
                }
            }
        }
    }
    
    if (mariaWins) {
        cout << "WIN" << endl;
    } else {
        cout << "LOSE" << endl;
    }
    
    return 0;
}