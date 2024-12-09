#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> sequence(n);
    for(int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int m = sequence[0].length();
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int len = 0;
            for(int k = 0; k < m; k++) {
                if(sequence[i][k] != sequence[j][k]) {
                    break;
                }
                len++;
            }
            
            dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + len);
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + len);
            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] + len);
        }
    }
    
    int max_len = 0;
    for(int i = 0; i <= n; i++) {
        max_len = std::max(max_len, dp[i][n - i]);
    }

    int min_s = 2 * m * n - max_len;
    
    std::cout << min_s << std::endl;

    return 0;
}