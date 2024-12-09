#include <iostream>
#include <vector>
#include <cmath>

struct ShootingStar {
    double px, py, pz, vx, vy, vz, r, vr;
};

double squaredDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0)
            break;

        std::vector<ShootingStar> stars(n);
        for (int i = 0; i < n; i++) {
            std::cin >> stars[i].px >> stars[i].py >> stars[i].pz >> stars[i].vx >> stars[i].vy >> stars[i].vz >> stars[i].r >> stars[i].vr;
        }

        for (int i = 0; i < n; i++) {
            double time = 0.0;
            double radius = stars[i].r;

            while (radius > 0) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        double distance = sqrt(squaredDistance(
                            stars[i].px + time * stars[i].vx,
                            stars[i].py + time * stars[i].vy,
                            stars[i].pz + time * stars[i].vz,
                            stars[j].px + time * stars[j].vx,
                            stars[j].py + time * stars[j].vy,
                            stars[j].pz + time * stars[j].vz
                        ));
                        if (distance <= radius + stars[j].r) {
                            // Stars come into contact
                            radius = 0;
                            break;
                        }
                    }
                }

                if (radius == 0)
                    break;

                radius -= stars[i].vr;
                time += 1.0;
            }

            std::cout << std::fixed;
            std::cout.precision(10);
            std::cout << time << std::endl;
        }
    }

    return 0;
}