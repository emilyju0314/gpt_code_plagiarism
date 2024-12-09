#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

std::vector<int> calcRem5(const std::string& s) {
    std::vector<int> dp(13);
    dp[0] = 1;
    for (char c : s) {
        if (c == '?') {
            std::vector<int> next(13);
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 13; j++) {
                    int next_rem = (j * 10 + i) % 13;
                    next[next_rem] = (next[next_rem] + dp[j]) % MOD;
                }
            }
            dp = next;
        } else {
            int d = c - '0';
            std::vector<int> next(13);
            for (int j = 0; j < 13; j++) {
                int next_rem = (j * 10 + d) % 13;
                next[next_rem] = (next[next_rem] + dp[j]) % MOD;
            }
            dp = next;
        }
    }
    return dp;
}

int main() {
    std::string S;
    std::cin >> S;

    std::vector<int> dp = calcRem5(S);
    std::cout << dp[5] << std::endl;

    return 0;
}