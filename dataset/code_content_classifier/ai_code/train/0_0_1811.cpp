#include <iostream>
#include <vector>

using namespace std;

void rotateBlocks(vector<vector<char>>& board, int x, int y) {
    char temp = board[y][x];
    // Perform rotation clockwise
    board[y][x] = board[y+1][x];
    board[y+1][x] = board[y+1][x+1];
    board[y+1][x+1] = board[y][x+1];
    board[y][x+1] = board[y][x];
}

void performFall(vector<vector<char>>& board) {
    int H = board.size();
    int W = board[0].size();
    for (int i = H - 2; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            if (board[i+1][j] == 'E') {
                board[i+1][j] = board[i][j];
                board[i][j] = 'E';
            }
        }
    }
}

void clearConnectedColors(vector<vector<char>>& board) {
    int H = board.size();
    int W = board[0].size();
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] != 'E') {
                    int count = 1;
                    char color = board[i][j];
                    int di[] = {-1, 1, 0, 0};
                    int dj[] = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W && board[ni][nj] == color) {
                            count++;
                        }
                    }
                    if (count >= 3) {
                        changed = true;
                        board[i][j] = 'E';
                        for (int k = 0; k < 4; k++) {
                            int ni = i + di[k];
                            int nj = j + dj[k];
                            if (ni >= 0 && ni < H && nj >= 0 && nj < W && board[ni][nj] == color) {
                                board[ni][nj] = 'E';
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> board(H, vector<char>(W, 'E'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        rotateBlocks(board, x-1, y-1);
        performFall(board);
        clearConnectedColors(board);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 'E') {
                cout << ".";
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}