#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        int candies = *std::min_element(a.begin(), a.end());
        int oranges = *std::min_element(b.begin(), b.end());

        long long moves = 0;
        for (int i = 0; i < n; i++) {
            moves += std::max(a[i] - candies, b[i] - oranges);
        }

        std::cout << moves << std::endl;
    }

    return 0;
}