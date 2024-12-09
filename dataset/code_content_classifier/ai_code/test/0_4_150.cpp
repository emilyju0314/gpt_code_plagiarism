#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> flavors(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> flavors[i];
        }

        long long minimum_coins = 0;
        long long min_cost = flavors[0];
        for (int i = 0; i < n; ++i) {
            if (flavors[i] < min_cost) {
                min_cost = flavors[i];
            }
            minimum_coins += flavors[i] / 3;
        }

        minimum_coins += min_cost % 3;
        std::cout << minimum_coins << std::endl;
    }

    return 0;
}