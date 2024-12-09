#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int tallest_height = 0;
    for(int i = 1; i <= n; i++) {
        int height = i * 2 + std::min(n - i, m) * 3;
        tallest_height = std::max(tallest_height, height);
    }

    for(int i = 1; i <= m; i++) {
        int height = i * 3 + std::min(m - i, n) * 2;
        tallest_height = std::max(tallest_height, height);
    }

    std::cout << tallest_height << std::endl;

    return 0;
}