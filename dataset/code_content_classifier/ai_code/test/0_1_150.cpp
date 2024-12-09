#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> flavors(n);
        for(int i = 0; i < n; i++) {
            std::cin >> flavors[i];
        }

        int min_coins = *std::min_element(flavors.begin(), flavors.end());
        for(int i = 0; i < 3; i++) {
            if(min_coins % (i + 1) != 0) {
                min_coins = ((min_coins / (i + 1)) + 1) * (i + 1);
            }
        }

        std::cout << min_coins << std::endl;
    }

    return 0;
}