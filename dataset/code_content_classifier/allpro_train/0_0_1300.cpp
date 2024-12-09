#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Circle {
    double radius;
    double x, y;
};

double distance(Circle c1, Circle c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2)) - c1.radius - c2.radius;
}

int main() {
    int N;
    while (true) {
        std::cin >> N;
        if (N == 0) break;

        std::vector<Circle> circles(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> circles[i].radius >> circles[i].x >> circles[i].y;
        }

        double min_distance = std::numeric_limits<double>::max();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double d = distance(circles[i], circles[j]);
                if (d < min_distance) {
                    min_distance = d;
                }
            }
        }

        std::cout << std::fixed;
        std::cout.precision(5);
        std::cout << min_distance << std::endl;
    }

    return 0;
}