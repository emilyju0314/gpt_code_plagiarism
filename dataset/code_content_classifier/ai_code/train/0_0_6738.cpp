#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int H, W, K;
vector<string> grid;
vector<vector<int>> fractal;

bool isValid(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

void dfs(int r, int c, int level) {
    if (!isValid(r, c) || grid[r][c] == '.') {
        return;
    }
    if (fractal[r][c] == -1 || fractal[r][c] < level) {
        fractal[r][c] = level;
        dfs(r - 1, c, level);
        dfs(r + 1, c, level);
        dfs(r, c - 1, level);
        dfs(r, c + 1, level);
    }
}

int main() {
    cin >> H >> W >> K;
    grid.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    fractal.assign(H, vector<int>(W, -1));
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (grid[r][c] == '#') {
                dfs(r, c, K);
            }
        }
    }

    long long ans = 0;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (fractal[r][c] == -1) {
                ans += 1;
            }
        }
    }

    cout << ans % MOD << endl;

    return 0;
}