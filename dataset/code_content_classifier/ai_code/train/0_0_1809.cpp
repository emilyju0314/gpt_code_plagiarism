#include <iostream>
#include <vector>
#include <cmath>

struct Circle {
    int x, y, r;
};

bool checkIntersection(int x1, int y1, int x2, int y2, const std::vector<Circle>& circles) {
    for (const Circle& circle : circles) {
        double centerX = circle.x;
        double centerY = circle.y;
        double radius = circle.r;

        double dx = x2 - x1;
        double dy = y2 - y1;
        double dr = sqrt(dx * dx + dy * dy);

        double D = x1 * y2 - x2 * y1;

        double discriminant = radius * radius * dr * dr - D * D;
        if (discriminant < 0) {
            continue;
        }

        double sqrtDiscr = sqrt(discriminant);

        double x3 = (D * dy + (dy < 0 ? -1 : 1) * dx * sqrtDiscr) / (dr * dr);
        double y3 = (-D * dx + abs(dy) * sqrtDiscr) / (dr * dr);

        double x4 = (D * dy - (dy < 0 ? -1 : 1) * dx * sqrtDiscr) / (dr * dr);
        double y4 = (-D * dx - abs(dy) * sqrtDiscr) / (dr * dr);

        if ((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1)) {
            return true;
        }
        if ((x1 <= x4 && x4 <= x2) || (x2 <= x4 && x4 <= x1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    while (std::cin >> n >> m && n != 0 && m != 0) {
        std::vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        for (int i = 0; i < m; ++i) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (checkIntersection(x1, y1, x2, y2, circles)) {
                std::cout << "NO ";
            } else {
                std::cout << "YES ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}