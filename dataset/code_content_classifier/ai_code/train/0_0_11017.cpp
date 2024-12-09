#include <iostream>
#include <cmath>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        int ans = std::ceil(n / 2.0);
        std::cout << ans << std::endl;
    }

    return 0;
}