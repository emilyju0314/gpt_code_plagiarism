#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

bool isLineSymmetric(const std::vector<Point>& points) {
    int n = points.size();
    if (n % 2 != 0) {
        return false;
    }

    Point center = {(points[0].x + points[n - 1].x) / 2, (points[0].y + points[n - 1].y) / 2};

    for (int i = 0; i < n / 2; i++) {
        Point symmetric = {2 * center.x - points[i].x, 2 * center.y - points[i].y};
        if (std::find(points.begin(), points.end(), symmetric) == points.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    if (isLineSymmetric(points)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}