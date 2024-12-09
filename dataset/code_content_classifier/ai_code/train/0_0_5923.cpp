#include <iostream>
#include <cmath>

struct Circle {
    int x, y, r;
};

int main() {
    int n, d;
    std::cin >> n >> d;

    Circle circles[n];
    for (int i = 0; i < n; i++) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int max_points = 0;
    for (double angle = 0; angle < 2 * M_PI; angle += 0.01) {
        double dx = d * cos(angle);
        double dy = d * sin(angle);
        bool hit = true;
        for (int i = 0; i < n; i++) {
            double cx = circles[i].x;
            double cy = circles[i].y;
            double dist = sqrt((cx * cx) + (cy * cy));
            if (dist < circles[i].r) {
                hit = false;
                break;
            }
            double nx = cx + dx;
            double ny = cy + dy;
            double new_dist = sqrt((nx * nx) + (ny * ny));
            if (new_dist < circles[i].r) {
                hit = false;
                break;
            }
        }
        if (hit) {
            max_points++;
        }
    }

    std::cout << max_points << std::endl;

    return 0;
}