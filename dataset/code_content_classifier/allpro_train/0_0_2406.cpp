#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 998244353;

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> grid(H);

    for (int i = 0; i < H; i++) {
        std::cin >> grid[i];
    }

    int white_rows = 0;
    int white_cols = 0;

    for (int i = 0; i < H; i++) {
        if (grid[i].find('#') == std::string::npos) {
            white_rows++;
        }
    }

    for (int j = 0; j < W; j++) {
        bool has_black = false;
        for (int i = 0; i < H; i++) {
            if (grid[i][j] == '#') {
                has_black = true;
                break;
            }
        }
        if (!has_black) {
            white_cols++;
        }
    }

    long long ans = 1;
    for (int i = 0; i < (H-W); i++) {
        ans = (ans * 2) % MOD;
    }

    for (int i = 0; i < (W-H); i++) {
        ans = (ans * 2) % MOD;
    }

    for (int i = 0; i < (H-white_rows); i++) {
        ans = (ans * 2) % MOD;
    }

    for (int i = 0; i < (W-white_cols); i++) {
        ans = (ans * 2) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}