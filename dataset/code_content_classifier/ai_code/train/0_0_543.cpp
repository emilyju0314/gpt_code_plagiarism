#include <iostream>

int main() {
    int y, k, n;
    std::cin >> y >> k >> n;

    bool found = false;
    for (int x = 1; x <= n - y; x++) {
        if ((x + y) <= n && (x + y) % k == 0) {
            std::cout << x << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << -1;
    }

    return 0;
}