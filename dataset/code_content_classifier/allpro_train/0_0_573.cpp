#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    int minPointsToRemove = 0;
    for (int i = 0; i < n - 1; i++) {
        if (points[i+1] - points[i] > 2*d) {
            minPointsToRemove += 2;
        }
    }

    std::cout << minPointsToRemove << std::endl;

    return 0;
}