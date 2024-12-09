#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int score = 0;
    bool visited[505][505];
    memset(visited, false, sizeof(visited)); 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.' && !visited[i][j]) {
                char color = board[i][j];

                int up = i, down = i, left = j, right = j; 
                while (up >= 0 && board[up][j] == board[i][j]) up--;
                while (down < m && board[down][j] == board[i][j]) down++;
                while (left >= 0 && board[i][left] == board[i][j]) left--;
                while (right < n && board[i][right] == board[i][j]) right++;

                bool canRemove = false;
                for (int k = up + 1; k < down; k++) {
                    for (int l = left + 1; l < right; l++) {
                        if (board[k][l] == color) {
                            canRemove = true;
                            visited[k][l] = true;
                        }
                    }
                }

                if (canRemove) {
                    score += 2;
                }
            }
        }
    }

    cout << score << endl;

    return 0;
}