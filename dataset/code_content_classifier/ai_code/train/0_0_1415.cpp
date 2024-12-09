#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> positions(k);
        for (int i = 0; i < k; i++) {
            std::cin >> positions[i];
        }

        std::vector<int> temperatures(k);
        for (int i = 0; i < k; i++) {
            std::cin >> temperatures[i];
        }

        std::vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int minTemp = INT_MAX;
            for (int j = 0; j < k; j++) {
                minTemp = std::min(minTemp, temperatures[j] + std::abs(positions[j] - (i + 1)));
            }
            result[i] = minTemp;
        }

        for (int i = 0; i < n; i++) {
            std::cout << result[i] << (i == n-1 ? "\n" : " ");
        }
    }

    return 0;
}