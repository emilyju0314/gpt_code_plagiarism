#include <iostream>
#include <algorithm>

int main() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    int res = 0;
    int rem = (4 - (n % 4)) % 4;

    if (rem == 1) {
        res = std::min({a, b + c, 3 * c});
    } else if (rem == 2) {
        res = std::min({2 * a, b, 2 * c});
    } else if (rem == 3) {
        res = std::min({3 * a, a + c, b});
    }

    std::cout << res << std::endl;

    return 0;
}