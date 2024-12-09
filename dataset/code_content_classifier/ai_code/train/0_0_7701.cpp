#include <iostream>
#include <vector>
#include <cmath>

struct Line {
    int x1, y1, x2, y2;
};

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Line> lines(n);

        for (int i = 0; i < n; i++) {
            std::cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        }

        bool many = false;
        double x = 0, y = 0;

        for (double i = -10000; i <= 10000; i += 0.01) {
            for (double j = -10000; j <= 10000; j += 0.01) {
                bool valid = true;
                double dist = sqrt((i - lines[0].x1) * (i - lines[0].x1) + (j - lines[0].y1) * (j - lines[0].y1));

                for (int k = 1; k < n; k++) {
                    double new_dist = sqrt((i - lines[k].x1) * (i - lines[k].x1) + (j - lines[k].y1) * (j - lines[k].y1));
                    if (std::abs(new_dist - dist) > 1e-5) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    if (x != 0 || y != 0) {
                        many = true;
                    } else {
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (many) {
            std::cout << "Many" << std::endl;
        } else if (x == 0 && y == 0) {
            std::cout << "None" << std::endl;
        } else {
            std::cout << std::fixed;
            std::cout << std::setprecision(4);
            std::cout << x << " " << y << std::endl;
        }
    }

    return 0;
}