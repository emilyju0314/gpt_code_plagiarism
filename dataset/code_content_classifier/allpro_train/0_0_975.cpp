#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> coins(n+1, 0);
    for (int i = 0; i < k; ++i) {
        int a, b;
        std::cin >> a >> b;
        coins[a] = b;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (coins[i+1] >= 2) {
            ++count;
            if (coins[i+1] > 2) {
                coins[i] += (coins[i+1] - 2);
                coins[i+2] += 1;
            }
        }

        if (coins[i+1] >= 2 && coins[i] >= 1 && coins[i+2] >= 1) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    if (count == 0) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }

    return 0;
}