#include <iostream>
#include <vector>
#include <cmath>

struct Star {
    double x, y, z;
};

struct Telescope {
    double x, y, z, phi;
};

double angleBetween(const Star& star, const Telescope& telescope) {
    return acos((star.x * telescope.x + star.y * telescope.y + star.z * telescope.z) / (sqrt(star.x * star.x + star.y * star.y + star.z * star.z) * sqrt(telescope.x * telescope.x + telescope.y * telescope.y + telescope.z * telescope.z)));
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Star> stars(n);
        for (int i = 0; i < n; i++) {
            std::cin >> stars[i].x >> stars[i].y >> stars[i].z;
        }

        int m;
        std::cin >> m;
        std::vector<Telescope> telescopes(m);
        std::vector<bool> visible(n, false);

        for (int i = 0; i < m; i++) {
            std::cin >> telescopes[i].x >> telescopes[i].y >> telescopes[i].z >> telescopes[i].phi;
            for (int j = 0; j < n; j++) {
                double angle = angleBetween(stars[j], telescopes[i]);
                if (angle < telescopes[i].phi) {
                    visible[j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visible[i]) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}