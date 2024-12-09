#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        long long ans = 0;
        long long maxVal = 0;

        for (int i = 1; i <= x2; i++) {
            for (int j = 1; j <= y2; j++) {
                maxVal = std::max(maxVal, (long long)i + j - 1);
                ans += (i + j - 2) % 10;
            }
        }

        if ((long long)x2 + y2 - 1 > maxVal) {
            std::cout << "...";
            std::cout.width(10);
            std::cout.fill('0');
            std::cout << ans % 10000000000 << std::endl;
        } else {
            std::cout << ans % 10000000000 << std::endl;
        }
    }

    return 0;
}