#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        int min_cost = INT_MAX;
        for(int i = 0; i < n; i++) {
            int cost;
            std::cin >> cost;
            if(cost < min_cost) {
                min_cost = cost;
            }
        }

        int min_coins = (min_cost/3) * 2 + (min_cost%3 > 0 ? 1 : 0);

        std::cout << min_coins << std::endl;
    }

    return 0;
}