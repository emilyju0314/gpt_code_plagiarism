#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    while (true) {
        int n, m;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            std::cin >> prices[i];
        }

        int max_sum = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[i] + prices[j] <= m) {
                    max_sum = std::max(max_sum, prices[i] + prices[j]);
                }
            }
        }

        if (max_sum == -1) {
            std::cout << "NONE" << std::endl;
        } else {
            std::cout << max_sum << std::endl;
        }
    }

    return 0;
}