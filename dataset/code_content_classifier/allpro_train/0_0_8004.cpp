#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (k > n + m - 2) {
        std::cout << -1 << std::endl;
    } else {
        int ans = std::max(n / (k + 1) * m, m / (k + 1) * n);
        std::cout << ans << std::endl;
    }

    return 0;
}