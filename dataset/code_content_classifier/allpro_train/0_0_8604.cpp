#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::cout << n + m - 1 << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << i << " 1" << std::endl;
    }
    for (int j = 2; j <= m; j++) {
        std::cout << "1 " << j << std::endl;
    }

    return 0;
}