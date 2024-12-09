#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ranges(n);
    for(int i = 0; i < n; i++) {
        std::cin >> ranges[i].first >> ranges[i].second;
    }

    double expected_price = 0.0;
    for(int i = 0; i < n; i++) {
        double p_lower = double(ranges[i].first) / 2.0 + 0.5;
        double p_upper = std::min(double(ranges[i].second + 1), double(ranges[(i + 1) % n].first)) - 1;
        expected_price += (p_lower + p_upper) / 2.0 / n;
    }

    std::cout << std::fixed << std::setprecision(10) << expected_price << std::endl;

    return 0;
}