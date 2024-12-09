#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    int x;
    std::cin >> x;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<int> p;
    p.push_back(x);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < std::abs(d[i]); j++) {
            if (d[i] >= 0) {
                p.push_back(p.back() + 1);
            } else {
                p.push_back(p.back() - 1);
            }
        }
    }

    std::vector<int> dp(p.size(), 1);
    std::vector<int> count(p.size(), 1);

    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (p[j] < p[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] = (count[i] + count[j]) % MOD;
                }
            }
        }
    }

    int longest_subsequence = *std::max_element(dp.begin(), dp.end());
    int total_count = 0;
    for (int i = 0; i < p.size(); i++) {
        if (dp[i] == longest_subsequence) {
            total_count = (total_count + count[i]) % MOD;
        }
    }

    std::cout << longest_subsequence << " " << total_count << std::endl;

    return 0;
}