#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> points(2*n);
    for(int i = 0; i < 2*n; i++) {
        std::cin >> points[i];
    }

    // Sort the points to find the minimum and maximum x and y coordinates
    std::sort(points.begin(), points.end());

    int minX = points[n-1] - points[0];
    std::sort(points.begin() + n, points.end());
    int minY = points[2*n-1] - points[n];

    std::cout << 1LL * minX * minY << std::endl;

    return 0;
}