#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> hours;
    for (int i = 1; i <= n; i++) {
        int light;
        std::cin >> light;
        hours.push_back({light, i});
    }

    std::sort(hours.begin(), hours.end());

    int minLight = hours[n-k].first;
    std::cout << minLight << std::endl;

    std::cout << hours[n-k].second;
    for (int i = n-k+1; i < n; i++) {
        std::cout << " " << hours[i].second;
    }
    std::cout << std::endl;

    return 0;
}