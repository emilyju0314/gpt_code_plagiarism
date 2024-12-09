#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> tiles(n);
    for(int i = 0; i < n; i++) {
        std::cin >> tiles[i];
    }

    std::vector<int> counts(m+2, 0);
    for(int tile : tiles) {
        counts[tile]++;
    }

    std::vector<int> dp(m+2, 0);
    for(int i = m; i >= 1; i--) {
        dp[i] = std::min(counts[i], std::min(dp[i+1], dp[i+2]));
    }

    int maxTriples = 0;
    for(int i = 1; i <= m; i++) {
        maxTriples = std::max(maxTriples, dp[i] + dp[i+1] + dp[i+2]);
    }

    std::cout << maxTriples << std::endl;

    return 0;
}