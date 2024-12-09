#include <iostream>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long a, b, x, y;
    std::cin >> a >> b >> x >> y;

    long long common_factor = gcd(x, y);
    x /= common_factor;
    y /= common_factor;

    long long width_ratio = a / x;
    long long height_ratio = b / y;

    long long ans = std::min(width_ratio, height_ratio);
    std::cout << ans << std::endl;

    return 0;
}