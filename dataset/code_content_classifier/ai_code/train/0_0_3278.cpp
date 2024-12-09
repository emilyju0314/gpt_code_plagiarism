#include <iostream>
#include <vector>
#include <algorithm>

struct Building {
    int x_left, x_right, height;
};

bool compareBuildings(const Building& b1, const Building& b2) {
    return b1.x_left < b2.x_left;
}

int main() {
    double r;
    int n;
    
    while (std::cin >> r >> n && !(r == 0 && n == 0)) {
        std::vector<Building> buildings(n);
        std::vector<double> edges;

        for (int i = 0; i < n; i++) {
            std::cin >> buildings[i].x_left >> buildings[i].x_right >> buildings[i].height;
            edges.push_back(buildings[i].x_left);
            edges.push_back(buildings[i].x_right);
        }

        std::sort(edges.begin(), edges.end());
        edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

        double time = 0.0;
        for (size_t i = 1; i < edges.size(); i++) {
            double x_left = edges[i - 1];
            double x_right = edges[i];
            double max_height = 0.0;
            for (const Building& building : buildings) {
                if (building.x_left <= x_left && building.x_right >= x_right) {
                    max_height = std::max(max_height, static_cast<double>(building.height));
                }
            }
            if (r >= max_height) {
                double distance_to_cover = x_right - r;
                if (distance_to_cover < 0) {
                    time += (r - x_right) / 1.0;
                } else {
                    time += distance_to_cover / 1.0;
                }
            }
        }

        std::cout << std::fixed;
        std::cout.precision(4);
        std::cout << time << std::endl;
    }

    return 0;
}