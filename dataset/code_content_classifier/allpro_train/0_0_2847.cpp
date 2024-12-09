#include <iostream>
#include <vector>

const int MOD = 1000000007;

int calculateCount(int N, const std::vector<std::vector<int>>& bends) {
    std::vector<long long> dp(1 << N, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                bool valid = true;
                for (int j = 0; j < bends[i].size(); j++) {
                    if ((mask & (1 << bends[i][j])) == 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[mask] += dp[mask ^ (1 << i)];
                    dp[mask] %= MOD;
                }
            }
        }
    }

    return dp[(1 << N) - 1];
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> bends(N);

    for (int i = 0; i < M; i++) {
        int Si, Di;
        std::cin >> Si >> Di;
        bends[Si - 1].push_back(Di - 1);
    }

    int count = calculateCount(N, bends);
    std::cout << count << std::endl;

    return 0;
}