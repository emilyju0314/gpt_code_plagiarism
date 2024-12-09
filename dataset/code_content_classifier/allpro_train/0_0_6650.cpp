#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    vector<int> rows(H), columns(W);
    for (int i = 0; i < H; i++) {
        rows[i] = i;
    }
    for (int j = 0; j < W; j++) {
        columns[j] = j;
    }

    long long ans = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char ch = grid[i][j];
            if (grid[rows[i]][columns[j]] != ch) {
                rows[i] = max(rows[i], rows[H - 1 - i]);
                columns[j] = max(columns[j], columns[W - 1 - j]);
                ans = (ans * 2) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}