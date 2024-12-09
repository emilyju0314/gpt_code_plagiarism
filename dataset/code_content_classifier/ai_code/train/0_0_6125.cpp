#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1000000007;

int main() {
    int a, b, c, A, B, C;
    std::cin >> a >> b >> c >> A >> B >> C;

    std::vector<std::vector<std::vector<int>>> dp(A, std::vector<std::vector<int>>(B, std::vector<int>(C, 0)));

    dp[0][0][0] = 1;

    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            for (int k = 0; k < C; ++k) {
                if ((i || j || k) && (i < a || j < b || k < c)) {
                    int& res = dp[i][j][k];
                    if (i) res += dp[(i + A - a) % A][j][k];
                    if (j) res += dp[i][(j + B - b) % B][k];
                    if (k) res += dp[i][j][(k + C - c) % C];
                    res %= MOD;
                }
            }
        }
    }

    int total = dp[A - 1][B - 1][C - 1];

    for (int i = 1; i < A; ++i) {
        total = (long long)total * i % MOD;
    }

    std::cout << total << std::endl;

    return 0;
}