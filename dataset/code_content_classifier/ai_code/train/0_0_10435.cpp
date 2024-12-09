#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    std::sort(points.begin(), points.end());

    for(int i = 0; i < n; i++) {
        std::cout << i + 1 << " ";
    }

    return 0;
}