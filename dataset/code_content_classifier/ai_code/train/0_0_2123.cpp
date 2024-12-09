#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007
#define MAXN 500

using namespace std;

int n;
int k;
bool blocked_square[MAXN][MAXN];
long long dp[MAXN][MAXN][2];

int dx[] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1,  1,  2};

bool valid(int x, int y) {
    return x >= 0 && x < MAXN && y >= 0 && y < MAXN && !blocked_square[x][y];
}

long long solve(int x, int y, int moves_left, int last_move) {
    if (moves_left == 0) {
        return 1;
    }
    if (dp[x][y][last_move] != -1) {
        return dp[x][y][last_move];
    }
    long long ans = 0;
    for (int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (valid(new_x, new_y)) {
            ans = (ans + solve(new_x, new_y, moves_left - 1, i % 2)) % MOD;
        }
    }
    return dp[x][y][last_move] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        blocked_square[x + 200][y + 200] = true;
    }
    long long ans = solve(200, 200, k, 0);
    cout << ans << endl;
    return 0;
}