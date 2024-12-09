#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    std::vector<std::string> labyrinth(n);
    for(int i = 0; i < n; i++) {
        std::cin >> labyrinth[i];
    }

    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(labyrinth[i][j] == 'R') continue;

            if(i > 0 && labyrinth[i-1][j] != 'R') {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
            if(j > 0 && labyrinth[i][j-1] != 'R') {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    std::cout << dp[n-1][m-1] << std::endl;

    return 0;
}