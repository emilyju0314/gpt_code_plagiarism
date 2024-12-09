#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        std::string books;
        
        std::cin >> N >> books;

        std::vector<int> shelves(4*N);
        for (int i = 0; i < 4*N; ++i) {
            shelves[i] = books[i] == 'Y' ? i/4 + 1 : 0;
        }

        std::vector<int> dp(4*N, 1e9);
        dp[0] = 0;

        for (int i = 1; i < 4*N; ++i) {
            if (shelves[i] == 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = std::min(dp[i-1] + 1, dp[i-2] + 1);
            }
        }

        std::cout << dp[4*N-1] << std::endl;
    }

    return 0;
}