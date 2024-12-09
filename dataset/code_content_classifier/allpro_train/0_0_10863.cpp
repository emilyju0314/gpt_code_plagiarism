#include <iostream>
#include <vector>

using namespace std;

bool isValidTrimino(char color, char currentColor) {
    if (currentColor == '.') {
        return true;
    }
    if (currentColor == color) {
        return true;
    }
    return false;
}

bool canTilingBeDone(vector<vector<char>>& board, int i, int j, int n, int m) {
    char color1, color2;
    if ((i + j) % 2 == 0) {
        color1 = 'w';
        color2 = 'b';
    } else {
        color1 = 'b';
        color2 = 'w';
    }

    for (int k = i; k < i + 3; k++) {
        for (int l = j; l < j + 3; l++) {
            if (k >= n || l >= m) {
                return false;
            }
            char currentColor = board[k][l];
            if (k == i + 1 && l == j + 1) {
                if (currentColor != 'b') {
                    return false;
                }
            } else if ((k + l) % 2 == 0) {
                if (!isValidTrimino(color2, currentColor)) {
                    return false;
                }
            } else {
                if (!isValidTrimino(color1, currentColor)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (canTilingBeDone(board, i, j, n, m)) {
                possible = true;
                cout << "YES" << endl;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        if (k >= i && k < i + 3 && l >= j && l < j + 3) {
                            if (l == j + 1) {
                                cout << "b";
                            } else {
                                cout << "a";
                            }
                        } else {
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }

    if (!possible) {
        cout << "NO" << endl;
    }

    return 0;
}