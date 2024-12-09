#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<int>> dp1(n, std::vector<int>(n));
    std::vector<std::vector<int>> dp2(n, std::vector<int>(n));

    dp1[0][0] = grid[0][0];
    for(int i = 1; i < n; i++) {
        dp1[i][0] = dp1[i-1][0] + grid[i][0];
        dp1[0][i] = dp1[0][i-1] + grid[0][i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp1[i][j] = std::max(dp1[i-1][j], dp1[i][j-1]) + grid[i][j];
        }
    }

    dp2[n-1][n-1] = grid[n-1][n-1];
    for(int i = n-2; i >= 0; i--) {
        dp2[i][n-1] = dp2[i+1][n-1] + grid[i][n-1];
    }
    for(int i = n-2; i >= 0; i--) {
        dp2[n-1][i] = dp2[n-1][i+1] + grid[n-1][i];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            dp2[i][j] = std::max(dp2[i+1][j], dp2[i][j+1]) + grid[i][j];
        }
    }

    int max_score = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            max_score = std::max(max_score, dp1[i][j] + dp2[i][j] - grid[i][j]);
        }
    }

    std::cout << max_score << std::endl;

    return 0;
}