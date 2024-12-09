#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    long long total_combinations = 0;
    vector<vector<long long>> dp(r, vector<long long>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dp[i][j] = k;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ax + i <= n && bx + i <= n && ay + j <= m && by + j <= m) {
                if (ax + i != bx + i || ay + j != by + j) {
                    dp[i][j] = (dp[i][j] * dp[i-1][j-1]) % MOD;
                }
                total_combinations = (total_combinations + dp[i][j]) % MOD;
            }
        }
    }

    cout << total_combinations << endl;

    return 0;
}