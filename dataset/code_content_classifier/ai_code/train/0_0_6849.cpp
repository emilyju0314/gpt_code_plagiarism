#include <iostream>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        long long a, b, c;
        std::cin >> a >> b >> c;

        long long total = a + b + c;
        long long max_candies = total / 2;

        // Ensure both Alice and Bob have the same number of candies
        max_candies = std::min(max_candies, total - total / 2);

        std::cout << max_candies << std::endl;
    }

    return 0;
}