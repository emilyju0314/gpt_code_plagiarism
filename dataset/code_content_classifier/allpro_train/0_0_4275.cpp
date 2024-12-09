#include <iostream>
#include <cmath>

int main() {
    int n, x, y, c;
    std::cin >> n >> x >> y >> c;

    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int border = (m * 2 - 1) * (m * 2 - 1) + (m * 2 - 1);
        if (border >= c) {
            ans = m - 1;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    int res = std::max(ans, std::max(std::max(x, y), std::max(n - x + 1, n - y + 1)));
    std::cout << res << std::endl;

    return 0;
}