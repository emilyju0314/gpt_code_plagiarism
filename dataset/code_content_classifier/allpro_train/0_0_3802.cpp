#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

bool intersect(Line l1, Line l2) {
    double x1 = l1.p1.x, y1 = l1.p1.y;
    double x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y;
    double x4 = l2.p2.x, y4 = l2.p2.y;

    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double dx2 = x4 - x3;
    double dy2 = y4 - y3;

    double div = dx1 * dy2 - dx2 * dy1;

    if (fabs(div) < 1e-9) {
        return false; // Parallel lines
    }

    double t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / div;
    double s = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / div;

    return (t >= 0 && t <= 1 && s >= 0 && s <= 1);
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        Line* lines = new Line[n];
        for (int i = 0; i < n; i++) {
            std::cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        }

        bool hasGap = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(lines[i], lines[j])) {
                    hasGap = true;
                    break;
                }
            }
            if (hasGap) {
                break;
            }
        }

        if (hasGap) {
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }

        delete[] lines;
    }

    return 0;
}