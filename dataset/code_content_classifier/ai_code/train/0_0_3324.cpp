#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> coupons;
    for (int i = 0; i < m; i++) {
        int qi, wi;
        std::cin >> qi >> wi;
        coupons.push_back(std::make_pair(qi, wi));
    }

    std::sort(coupons.begin(), coupons.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    long long total_money = 0;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n && coupons.size() > 0) {
            total_money += coupons.front().second;
            coupons.erase(coupons.begin());
        }
    }

    std::cout << total_money << '\n';

    return 0;
}