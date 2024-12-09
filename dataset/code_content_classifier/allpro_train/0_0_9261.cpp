#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    vector<vector<char>> labyrinth(H, vector<char>(W));
    int start_x, start_y, goal_x, goal_y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 's') {
                start_x = j;
                start_y = i;
            }
            if (labyrinth[i][j] == 'g') {
                goal_x = j;
                goal_y = i;
            }
        }
    }

    vector<vector<double>> dp(H, vector<double>(W, 1e9));
    dp[start_y][start_x] = 0;

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    bool changed = true;

    while (changed) {
        changed = false;
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (labyrinth[y][x] == '#') continue;

                double expected_moves = 0;
                int valid_moves = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < W && ny >= 0 && ny < H && labyrinth[ny][nx] != '#') {
                        valid_moves++;
                        expected_moves += dp[ny][nx];
                    }
                }
                if (labyrinth[y][x] == '*') {
                    dp[y][x] = min(dp[y][x], (expected_moves + 1) / valid_moves);
                } else {
                    dp[y][x] = min(dp[y][x], expected_moves / valid_moves);
                }
                if (dp[y][x] < 1e9) changed = true;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[goal_y][goal_x] << endl;

    return 0;
}