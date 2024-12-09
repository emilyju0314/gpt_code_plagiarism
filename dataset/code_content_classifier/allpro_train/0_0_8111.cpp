#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    int minDistance = points[1] - points[0];
    for (int i = 1; i < n - 1; i++) {
        minDistance = std::min(minDistance, points[i + 1] - points[i]);
    }

    int totalPoints = 0;
    for (int i = 0; i < n - 1; i++) {
        totalPoints += (points[i + 1] - points[i] - minDistance) / minDistance;
    }

    std::cout << totalPoints << std::endl;

    return 0;
}