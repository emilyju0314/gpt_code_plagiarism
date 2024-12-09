#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    int min_distance = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (prices[i] > 0 && prices[i] <= k) {
            int distance = abs(m - (i + 1)) * 10;
            if (distance < min_distance) {
                min_distance = distance;
            }
        }
    }

    std::cout << min_distance << std::endl;

    return 0;
}