#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> b(n), g(m);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> g[i];
    }

    int min_sweets = *std::max_element(b.begin(), b.end());

    for (int i = 0; i < m; i++) {
        min_sweets = std::max(min_sweets, 2 * *std::min_element(b.begin(), b.end()));
        min_sweets = std::max(min_sweets, g[i]);
    }

    std::cout << min_sweets << std::endl;

    return 0;
}