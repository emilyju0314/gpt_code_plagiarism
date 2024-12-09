#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        std::cin >> n;

        std::vector<int> candies(n);
        for (int j = 0; j < n; j++) {
            std::cin >> candies[j];
        }

        std::sort(candies.begin(), candies.end());

        int max_gift_size = 1;
        int current_size = 1;
        for (int j = 1; j < n; j++) {
            if (candies[j] != candies[j-1]) {
                current_size++;
            }
            max_gift_size = std::max(max_gift_size, current_size);
        }

        std::cout << max_gift_size << std::endl;
    }

    return 0;
}