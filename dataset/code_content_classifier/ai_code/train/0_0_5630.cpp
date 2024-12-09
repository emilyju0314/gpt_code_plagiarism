#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int dice_i = 0, dice_j = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '6') {
                dice_i = i;
                dice_j = j;
            }
        }
    }

    vector<int> di = {0, 0, -1, 1}; // directions in rows
    vector<int> dj = {1, -1, 0, 0}; // directions in columns
    vector<int> bottom = {6, 2, 5, 1}; // bottom number after each roll

    visited[dice_i][dice_j] = true;

    bool possible = false;

    for (int k = 0; k < 4; k++) {
        int new_i = dice_i + di[k];
        int new_j = dice_j + dj[k];

        if (new_i >= 0 && new_i < H && new_j >= 0 && new_j < W && grid[new_i][new_j] != '#') {
            int roll = 0;

            for (int l = 0; l < 4; l++) {
                if (grid[new_i][new_j] == bottom[l]) {
                    roll = l;
                }
            }

            dice_i = new_i;
            dice_j = new_j;

            bottom = {
                7 - grid[dice_i][dice_j], // opposite number
                bottom[roll], // front number
                grid[dice_i][dice_j], // right number
                bottom[3 - roll] // top number
            };

            visited[dice_i][dice_j] = true;

            if (dice_i == H - 1 && dice_j == W - 1) {
                possible = true;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}