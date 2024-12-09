#include <iostream>
#include <cmath>

int main() {
    int N, K;
    std::cin >> N >> K;

    double base = std::sqrt(3) / 2;
    double ans = -1;

    for (int i = 3; i <= N; i++) {
        double area = (i-2) * (i-1) * i / 6 * base;
        if (K <= area) {
            ans = std::sqrt(2 * K / ((i-2) * (i-1))) / base;
            break;
        }
        K -= area;
    }

    std::cout << std::fixed;
    std::cout.precision(14);
    std::cout << ans << std::endl;

    return 0;
}