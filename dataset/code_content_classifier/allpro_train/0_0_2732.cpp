#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }

    std::vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        std::vector<int> ndp(n+1);
        for (int j = 0; j < n; j++) {
            if (p[j] == 0) {
                for (int k = 0; k <= n; k++) {
                    ndp[std::abs(k-j)] = (ndp[std::abs(k-j)] + dp[k]) % MOD;
                }
            }
        }
        dp = ndp;
    }

    for (int i = 0; i < n; i++) {
        std::cout << dp[std::abs(i-(q[i]-1))] << " ";
    }
    std::cout << std::endl;

    return 0;
}