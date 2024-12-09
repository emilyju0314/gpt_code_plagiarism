#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

const int dx[] = {0, 1};
const int dy[] = {1, 0};

int H, W;
int grid[55][55];
int dp[55][55][55][55];

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && grid[x][y] != -1;
}

int solve(int x1, int y1, int x2, int y2) {
    if (x1 == H-1 && y1 == W-1) return 0;
    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];

    int ans = -INF;
    for (int i = 0; i < 2; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        if (!isValid(nx1, ny1)) continue;

        for (int j = 0; j < 2; j++) {
            int nx2 = x2 + dx[j];
            int ny2 = y2 + dy[j];
            if (!isValid(nx2, ny2)) continue;

            int add = (grid[nx1][ny1] == grid[nx2][ny2] - 'A') + (grid[nx1][ny1] == grid[nx1][ny1] - 'a');
            ans = max(ans, add + solve(nx1, ny1, nx2, ny2));
        }
    }

    return dp[x1][y1][x2][y2] = ans;
}

int main() {
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;

        int s1, s2;
        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < W; j++) {
                if (row[j] == '.') grid[i][j] = 0;
                else if (row[j] == '#') grid[i][j] = -1;
                else grid[i][j] = row[j];
                if (grid[i][j] == 'A') s1 = i, s2 = j;
            }
        }

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, s1, s2);
        if (ans < 0) cout << "-1" << endl;
        else cout << ans << endl;
    }

    return 0;
}