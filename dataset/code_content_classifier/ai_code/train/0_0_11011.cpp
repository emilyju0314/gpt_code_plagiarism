#include <iostream>
#include <string>
#include <vector>

const int MOD = 998244353;

int countDepth(const std::string& s) {
    int depth = 0;
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }
        depth = std::max(depth, -balance);
    }
    return depth;
}

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int totalDepth = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (s[j - 1] == '(') {
                dp[j] = dp[j - 1];
            } else if (s[j - 1] == ')') {
                dp[j] = dp[j - 1];
            } else {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
            totalDepth = (totalDepth + countDepth(s.substr(j - 1, i - j + 1))) % MOD;
        }
    }

    std::cout << totalDepth << std::endl;

    return 0;
}