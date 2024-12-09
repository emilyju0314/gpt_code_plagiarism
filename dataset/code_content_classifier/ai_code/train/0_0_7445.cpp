#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

double dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

Point subtract(Point p1, Point p2) {
    return {p1.x - p2.x, p1.y - p2.y};
}

Point project(Point p, Point p1, Point p2) {
    Point vec = subtract(p2, p1);
    double projection_length = dot(subtract(p, p1), vec) / dot(vec, vec);
    return {p1.x + projection_length * vec.x, p1.y + projection_length * vec.y};
}

int main() {
    Point p1, p2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        Point p;
        std::cin >> p.x >> p.y;
        Point projection = project(p, p1, p2);
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << projection.x << " " << projection.y << std::endl;
    }

    return 0;
}