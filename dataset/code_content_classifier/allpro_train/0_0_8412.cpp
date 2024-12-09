#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000003

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if(i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if(j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                count++;
            }
        }
    }

    if(count == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << dp[n - 1][m - 1] << std::endl;
    }

    return 0;
}