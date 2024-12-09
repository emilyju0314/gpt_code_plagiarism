#include <iostream>
#include <cmath>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    double det = a * d - b * c;
    double norm = std::max(std::abs(a), std::abs(b));
    norm = std::max(norm, std::abs(c));
    norm = std::max(norm, std::abs(d));

    double ans = sqrt(det*det + norm*norm) / (2.0 * std::abs(det));
    std::cout << ans << std::endl;

    return 0;
}