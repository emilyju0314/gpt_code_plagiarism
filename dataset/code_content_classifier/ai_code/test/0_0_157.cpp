#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

int choose(int n, int k) {
    if (k == 0) return 1;
    if (k > n) return 0;
    
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }
    
    return dp[n][k];
}

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    int count = 0;
    for (int i = 0; i <= k; i++) {
        std::string temp = s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1' && i > 0) {
                temp[j] = '0';
            }
        }
        std::sort(temp.begin(), temp.end());
        
        int ones = 0;
        for (int j = n-1; j > n-1-k; j--) {
            if (temp[j] == '1') ones++;
        }
        
        count = (count + choose(k, i) * choose(n-k, ones)) % MOD;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}