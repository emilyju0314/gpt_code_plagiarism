#include <iostream>

int main() {
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;

    int x, y;
    if (n == 1) {
        x = a;
        y = a;
    } else {
        x = std::min(a + 1, k - a + 1);
        y = std::min(k - a, b) + 1 + (b % k == 0 ? k : 0);
    }

    std::cout << x << " " << n*k - y << std::endl;

    return 0;
}