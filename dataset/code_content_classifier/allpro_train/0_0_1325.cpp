#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long x, y, n;
        std::cin >> x >> y >> n;

        long long max_k = (n - y) / x * x + y;
        std::cout << max_k << std::endl;
    }

    return 0;
}