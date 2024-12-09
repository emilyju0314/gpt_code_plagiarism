#include <iostream>

int main() {
    int n, k, l, c, d, p, nl, np;
    std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_milliliters = k * l;
    int total_slices = c * d;
    int total_salt = p;

    int max_toasts = std::min({total_milliliters / nl, total_slices, total_salt}) / n;

    std::cout << max_toasts << std::endl;

    return 0;
}