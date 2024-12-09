#include <iostream>
#include <cmath>

const double pi = 3.14159265358979323846;

struct Circle {
    double x, y, r;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        Circle circles[n];
        double total_length = 0.0;

        for (int i = 0; i < n; i++) {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        for (int i = 0; i < n; i++) {
            double d = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j && distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y) < circles[i].r + circles[j].r) {
                    d = std::max(d, distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y) + circles[j].r);
                }
            }
            total_length += 2 * pi * (circles[i].r + d);
        }

        std::cout << std::fixed << total_length << std::endl;
    }

    return 0;
}