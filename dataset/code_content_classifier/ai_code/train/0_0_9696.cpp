#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x;
    int y;
};

double compute_autocorrelation(const std::vector<Point>& points, double r) {
    double sum = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
        sum += (points[i].y * points[i + 1].y) * exp(-r * abs(points[i + 1].x - points[i].x));
    }
    return sum;
}

int main() {
    int n;
    double r;

    while (true) {
        std::cin >> n >> r;

        if (n == 0 && r == 0) {
            break;
        }

        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        double result = compute_autocorrelation(points, r);
        std::cout << result << std::endl;
    }

    return 0;
}