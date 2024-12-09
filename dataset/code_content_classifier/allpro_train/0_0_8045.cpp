#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int H_block, W_block;
        cin >> H_block >> W_block;

        vector<string> block(H_block);
        for (int j = 0; j < H_block; j++) {
            cin >> block[j];
        }

        int H_board, W_board;
        cin >> H_board >> W_board;

        vector<string> board(H_board);
        for (int j = 0; j < H_board; j++) {
            cin >> board[j];
        }

        int max_score = -1;

        for (int r = 0; r < 4; r++) {
            for (int i = 0; i <= H_board - H_block; i++) {
                for (int j = 0; j <= W_board - W_block; j++) {
                    bool valid_placement = true;
                    for (int k = 0; k < H_block; k++) {
                        for (int l = 0; l < W_block; l++) {
                            if (block[k][l] == '#' && board[i+k][j+l] == '#') {
                                valid_placement = false;
                                break;
                            }
                        }
                        if (!valid_placement) {
                            break;
                        }
                    }

                    if (valid_placement) {
                        int score = 0;
                        for (int k = 0; k < H_board; k++) {
                            bool filled = true;
                            for (int l = 0; l < W_board; l++) {
                                if (board[k][l] == '.') {
                                    filled = false;
                                    break;
                                }
                            }
                            if (filled) {
                                score++;
                            }
                        }
                        max_score = max(max_score, score);
                    }
                }
            }

            // Rotate the block clockwise
            vector<string> new_block(W_block, string(H_block, '.'));
            for (int k = 0; k < H_block; k++) {
                for (int l = 0; l < W_block; l++) {
                    new_block[l][H_block-1-k] = block[k][l];
                }
            }
            block = new_block;
            swap(H_block, W_block);
        }

        cout << max_score << endl;
    }

    return 0;
}