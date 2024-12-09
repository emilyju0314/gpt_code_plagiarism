#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

Point subtract(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

Point add(const Point& a, const Point& b) {
    return {a.x + b.x, a.y + b.y};
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Point> vertices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vertices[i].x >> vertices[i].y;
    }

    std::vector<double> ratios(m);
    for (int i = 0; i < m; i++) {
        std::cin >> ratios[i];
    }

    double total_area = 0.0;
    for (int i = 0; i < n; i++) {
        total_area += cross(vertices[i], vertices[(i + 1) % n]);
    }

    std::vector<Point> centers(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Point diff = subtract(vertices[(j + 1) % n], vertices[j]);
            centers[i] = add(centers[i], add(vertices[j], {diff.y, -diff.x}) * (cross(vertices[j], vertices[(j + 1) % n]) * ratios[i] / total_area));
        }
    }

    for (int i = 0; i < m; i++) {
        std::cout << centers[i].x << " " << centers[i].y << std::endl;
    }

    return 0;
}