#include <iostream>
#include <vector>
#include <cmath>

bool hasNonPerfectSquareSubsequence(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        int product = array[i];
        for (int j = i + 1; j < array.size(); j++) {
            product *= array[j];
            if (std::sqrt(product) == std::round(std::sqrt(product))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }

        if (hasNonPerfectSquareSubsequence(array)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}