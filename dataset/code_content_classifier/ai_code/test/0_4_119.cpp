#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> towers(n);
        for(int i = 0; i < n; i++) {
            std::cin >> towers[i];
        }

        int min_height = *std::min_element(towers.begin(), towers.end());
        int max_height = *std::max_element(towers.begin(), towers.end());

        int min_operations = max_height - min_height;

        std::cout << min_operations << std::endl;
    }

    return 0;
}