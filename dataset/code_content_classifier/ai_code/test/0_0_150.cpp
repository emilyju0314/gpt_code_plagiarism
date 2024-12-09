#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> flavors(n);
        for (int i = 0; i < n; i++) {
            std::cin >> flavors[i];
        }

        long long total_coins = 0;
        long long min_amount = *min_element(flavors.begin(), flavors.end());

        // Calculate the minimum number of coins needed
        for (int i = 0; i < n; i++) {
            total_coins += flavors[i] - min_amount;
        }

        std::cout << total_coins << std::endl;
    }

    return 0;
}