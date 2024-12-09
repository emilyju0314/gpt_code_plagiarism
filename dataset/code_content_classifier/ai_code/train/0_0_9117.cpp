#include <iostream>
#include <vector>

const int MOD = 998244353;

int countStates(int n, std::string s) {
    std::vector<int> dp(n+1, 0);

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
            if(i + 2 <= n) {
                dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int result = countStates(n, s);
        std::cout << result << std::endl;
    }

    return 0;
}