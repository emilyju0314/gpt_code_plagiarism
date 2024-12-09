#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        std::cin >> houses[i];
    }

    std::sort(houses.begin(), houses.end());

    double d = 0;
    for (int i = 1; i < n; i++) {
        d = std::max(d, (double)(houses[i] - houses[i-1]) / 2.0);
    }

    std::cout << std::fixed << std::setprecision(6) << d << std::endl;
    std::cout << houses[0] + d << " " << (houses[0] + houses[1]) / 2.0 << " " << houses[n-1] - d << std::endl;

    return 0;
}