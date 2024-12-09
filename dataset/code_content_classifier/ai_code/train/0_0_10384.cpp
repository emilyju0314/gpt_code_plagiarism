#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_N = 7;
int n, m, p;
char board[MAX_N][MAX_N][MAX_N];

bool checkWin(int x, int y, int z, char player) {
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};
    int dz[] = {0, 0, 1, 1};

    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        int cx = x, cy = y, cz = z;
        while (cx >= 1 && cx <= n && cy >= 1 && cy <= n && cz >= 1 && cz <= n) {
            if (board[cx][cy][cz] == player) {
                cnt++;
                if (cnt >= m) {
                    return true;
                }
            } else {
                break;
            }
            cx += dx[i];
            cy += dy[i];
            cz += dz[i];
        }
    }

    return false;
}

string playGame() {
    int moves = 0;
    char currentPlayer = 'B';

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;

        int z = 1;
        while (z <= n && board[x][y][z] != '.') {
            z++;
        }

        if (z <= n) {
            board[x][y][z] = currentPlayer;
            moves++;

            if (checkWin(x, y, z, currentPlayer)) {
                if (currentPlayer == 'B') {
                    return "Black " + to_string(moves);
                } else {
                    return "White " + to_string(moves);
                }
            }

            currentPlayer = (currentPlayer == 'B') ? 'W' : 'B';
        }
    }

    return "Draw";
}

int main() {
    while (true) {
        cin >> n >> m >> p;

        if (n == 0 && m == 0 && p == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    board[i][j][k] = '.';
                }
            }
        }

        string result = playGame();
        cout << result << endl;
    }

    return 0;
}