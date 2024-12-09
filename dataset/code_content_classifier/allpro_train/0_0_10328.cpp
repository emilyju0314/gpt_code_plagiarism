#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> array(n * k);
        for (int i = 0; i < n * k; i++) {
            std::cin >> array[i];
        }

        int sum = 0;
        int skip = (n / 2) + 1;

        for (int i = k * n - skip; i >= 0; i -= skip) {
            sum += array[i];
        }

        std::cout << sum << std::endl;
    }

    return 0;
}