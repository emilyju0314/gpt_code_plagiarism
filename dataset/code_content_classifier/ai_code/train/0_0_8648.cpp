#include <iostream>
#include <vector>

using namespace std;

int score = 0;

void disappearStones(vector<vector<int>>& board, int h) {
    bool disappeared = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = j + 1; k <= j + 2; k++) {
                if (board[i][j] == board[i][k] && board[i][j] == board[i][k + 1]) {
                    int tempScore = 0;
                    while (k + 1 < 5 && board[i][j] == board[i][k + 1]) {
                        tempScore += board[i][k + 1];
                        board[i][k + 1] = 0;
                        k++;
                        disappeared = true;
                    }
                    score += tempScore + board[i][j];
                    board[i][j] = 0;
                    board[i][k] = 0;
                }
            }
        }
    }
    if (disappeared) {
        for (int i = 0; i < 5; i++) {
            for (int j = h - 1; j > 0; j--) {
                for (int k = j; k >= 0; k--) {
                    if (board[j][i] == 0) {
                        swap(board[j][i], board[k][i]);
                    }
                }
            }
        }
        disappearStones(board, h);
    }
}

int main() {
    int h;
    while (true) {
        cin >> h;
        if (h == 0) {
            break;
        }
        vector<vector<int>> board(h, vector<int>(5));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[i][j];
            }
        }

        score = 0;
        disappearStones(board, h);
        cout << score << endl;
    }
    
    return 0;
}