#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> flavors(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> flavors[i];
        }

        int min_coins = *std::min_element(flavors.begin(), flavors.end());
        for (int i = 0; i < n; ++i) {
            if (flavors[i] % 2 == 0) {
                min_coins = std::min(min_coins, std::min(flavors[i]/2*3, flavors[i]));
            } else {
                min_coins = std::min(min_coins, flavors[i]/2*3+1);
            }
        }

        std::cout << min_coins << std::endl;
    }

    return 0;
}