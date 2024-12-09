#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

struct Building {
    int num;
    int x;
    int y;
};

double distance(const Building& b1, const Building& b2) {
    return std::sqrt(std::pow(b1.x - b2.x, 2) + std::pow(b1.y - b2.y, 2));
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Building> buildings(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> buildings[i].num >> buildings[i].x >> buildings[i].y;
        }

        int m;
        std::cin >> m;
        for (int i = 0; i < m; ++i) {
            int start, goal;
            std::cin >> start >> goal;

            std::vector<bool> visited(n, false);
            std::vector<int> route;
            route.push_back(start);
            visited[start - 1] = true;

            while (start != goal) {
                double minDist = std::numeric_limits<double>::max();
                int nextBuilding = -1;

                for (int j = 0; j < n; ++j) {
                    if (!visited[j] && distance(buildings[start - 1], buildings[j]) < 50) {
                        double dist = distance(buildings[start - 1], buildings[j]);
                        if (dist < minDist) {
                            minDist = dist;
                            nextBuilding = buildings[j].num;
                        }
                    }
                }

                if (nextBuilding == -1) {
                    std::cout << "NA" << std::endl;
                    break;
                }

                route.push_back(nextBuilding);
                visited[nextBuilding - 1] = true;
                start = nextBuilding;
            }

            if (start == goal) {
                for (int k = 0; k < route.size(); ++k) {
                    std::cout << route[k] << (k == route.size() - 1 ? "\n" : " ");
                }
            }
        }
    }

    return 0;
}