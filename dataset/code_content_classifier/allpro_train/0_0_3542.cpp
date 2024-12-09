#include <iostream>
#include <vector>

using namespace std;

bool canWin(int r, int c, int k, vector<vector<char>>& board) {
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (board[i][j] == '#') continue;
            for (int x = 1; x <= k && i + x < r; x++) {
                for (int y = 1; y <= k && j + y < c; y++) {
                    int nxt = dp[i + x][j + y];
                    if (i + x <= i && j + y <= j && (i - (i + x) + j - (j + y) <= k)) {
                        if (nxt == 0) dp[i][j] = 1;
                    }
                }
            }
        }
    }
    return dp[0][0] == 1;
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<char>> board(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    
    if (canWin(r, c, k, board)) {
        cout << "Chieno" << endl;
    } else {
        cout << "Cacao" << endl;
    }
    
    return 0;
}