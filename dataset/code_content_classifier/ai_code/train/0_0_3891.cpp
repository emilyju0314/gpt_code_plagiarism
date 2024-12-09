#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Road {
    int u, v, exp, time;
};

bool compare(const Road& r1, const Road& r2) {
    return r1.exp * r2.time > r2.exp * r1.time;
}

double calculateEfficiency(std::vector<Road>& roads, int n, int start, int dest) {
    // Sort roads based on efficiency
    std::sort(roads.begin(), roads.end(), compare);

    // Calculate highest efficiency
    double maxEfficiency = 0.0;
    for(const auto& road : roads) {
        if(road.u == start) {
            maxEfficiency = std::max(maxEfficiency, double(road.exp) / road.time);
        } else if(road.v == start) {
            maxEfficiency = std::max(maxEfficiency, double(road.exp) / road.time);
        }
    }

    return maxEfficiency;
}

int main() {
    int c;
    std::cin >> c;

    for(int i = 0; i < c; i++) {
        int n, m;
        std::cin >> n >> m;

        int start, dest;
        std::cin >> start >> dest;

        std::vector<Road> roads(m);
        for(int j = 0; j < m; j++) {
            std::cin >> roads[j].u >> roads[j].v >> roads[j].exp >> roads[j].time;
        }

        double efficiency = calculateEfficiency(roads, n, start, dest);
        std::cout << std::setprecision(4) << std::fixed << efficiency << std::endl;
    }

    return 0;
}