#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, x;
    std::cin >> N >> x;

    std::vector<std::pair<int, int>> stars(N);
    for (int i = 0; i < N; ++i) {
        int d, c;
        std::cin >> d >> c;
        stars[i] = {d, c};
    }

    int inf = 1e9;
    std::vector<int> dp(x + 1, inf);
    dp[0] = 0;

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < N; ++j) {
            int ni = std::min(x, i + stars[j].first);
            dp[ni] = std::min(dp[ni], dp[i] + stars[j].second);
        }
    }

    if (dp[x] == inf) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[x] << std::endl;
    }

    return 0;
}