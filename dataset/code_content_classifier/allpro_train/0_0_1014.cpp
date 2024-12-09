#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

long long dp[5][5][5];

void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (i == j || j == k || i == k || (i == 1 && k == 3) || (i == 3 && k == 1)) {
                    dp[i][j][k] = 0;
                } else {
                    dp[i][j][k] = 1;
                }
            }
        }
    }
}

int main() {
    int L, R;
    std::cin >> L >> R;

    init();

    long long ans = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if (i != j && j != k && i != k) {
                    ans = (ans + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}