#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> ratings;

        for (int k = 1; k <= n; k++) {
            int increment = n / k;
            ratings.push_back(increment);
        }

        std::sort(ratings.begin(), ratings.end());
        ratings.erase(std::unique(ratings.begin(), ratings.end()), ratings.end());

        std::cout << ratings.size() << std::endl;
        for (int i = 0; i < ratings.size(); i++) {
            std::cout << ratings[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}