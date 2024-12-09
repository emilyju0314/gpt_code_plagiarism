#include <iostream>
#include <vector>

const int MOD = 1000000007;

struct Button {
    int room;
    int coins;
};

int main() {
    int N, M;
    
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        // Initialize graph and visited arrays
        std::vector<std::vector<Button>> graph(N + 1);
        std::vector<bool> visited(N + 1, false);

        // Read warp button information
        for (int i = 0; i < M; i++) {
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }

        int Q;
        std::cin >> Q;

        // Process each adventure
        for (int q = 0; q < Q; q++) {
            int d, e;
            std::cin >> d >> e;

            std::vector<int> dp(N + 1, MOD);
            dp[1] = 0;

            // Dynamic programming to calculate the minimum number of button presses
            for (int i = 1; i <= N; i++) {
                for (const Button& btn : graph[i]) {
                    dp[btn.room] = std::min(dp[btn.room], dp[i] + btn.coins);
                }
            }

            // Output the result modulo MOD
            if (dp[d] == e) {
                std::cout << "1" << std::endl;
            } else {
                std::cout << "0" << std::endl;
            }
        }
    }

    return 0;
}