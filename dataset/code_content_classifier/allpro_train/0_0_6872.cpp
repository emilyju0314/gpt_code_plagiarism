#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

bool canMeet(vector<string>& board) {
    Point knight1, knight2;
    
    // Find positions of the two semiknights
    bool found1 = false, found2 = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'K') {
                if (!found1) {
                    knight1 = {i, j};
                    found1 = true;
                } else {
                    knight2 = {i, j};
                    found2 = true;
                    break;
                }
            }
        }
        if (found2) break;
    }
    
    // Check if the knights can meet
    for (int i = 0; i < 4; i++) {
        int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
        
        if (i == 0) {
            dx1 = 2; dy1 = 2;
            dx2 = -2; dy2 = -2;
        } else if (i == 1) {
            dx1 = 2; dy1 = -2;
            dx2 = -2; dy2 = 2;
        } else if (i == 2) {
            dx1 = -2; dy1 = 2;
            dx2 = 2; dy2 = -2;
        } else if (i == 3) {
            dx1 = -2; dy1 = -2;
            dx2 = 2; dy2 = 2;
        }
        
        int new_x1 = knight1.x + dx1;
        int new_y1 = knight1.y + dy1;
        int new_x2 = knight2.x + dx2;
        int new_y2 = knight2.y + dy2;
        
        // Check if the new positions are within bounds and are good squares
        if (new_x1 >= 0 && new_y1 >= 0 && new_x1 < 8 && new_y1 < 8 && board[new_x1][new_y1] != '#'
            && new_x2 >= 0 && new_y2 >= 0 && new_x2 < 8 && new_y2 < 8 && board[new_x2][new_y2] != '#') {
            return true;
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<string> board(8);
        
        for (int i = 0; i < 8; i++) {
            cin >> board[i];
        }
        
        cout << (canMeet(board) ? "YES" : "NO") << endl;
    }
    
    return 0;
}