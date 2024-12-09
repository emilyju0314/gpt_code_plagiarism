#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Monster {
    double x, y;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) break;

        std::vector<Monster> monsters(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> monsters[i].x >> monsters[i].y;
        }

        double shortest_distance = 16.0;
        do {
            bool safe = true;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    double dist_i = distance(0, 0, monsters[i].x, monsters[i].y);
                    double dist_j = distance(4, 0, monsters[j].x, monsters[j].y);
                    double dist_ij = distance(monsters[i].x, monsters[i].y, monsters[j].x, monsters[j].y);
                    if (dist_i <= dist_ij && dist_j <= dist_ij) {
                        safe = false;
                        break;
                    }
                }
                if (!safe) break;
            }

            if (safe) {
                double distance_to_boss = distance(0, 0, 4, 0);
                shortest_distance = std::min(shortest_distance, distance_to_boss);
            }
        } while (std::next_permutation(monsters.begin(), monsters.end()));

        if (shortest_distance == 16.0) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << shortest_distance << std::endl;
        }
    }

    return 0;
}