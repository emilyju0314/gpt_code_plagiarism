#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x, y, p;
    std::cin >> n >> x >> y >> p;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    std::sort(weights.begin(), weights.end());

    long long total_weights = 0;
    for (int i = 0; i < n; i++) {
        total_weights += static_cast<long long>(weights[i]) * (1 << x);
        total_weights %= p;
    }

    total_weights *= (1 << y) - 1;
    total_weights %= p;

    std::cout << total_weights << std::endl;

    return 0;
}