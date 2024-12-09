#include <iostream>
#include <vector>
#include <algorithm>

struct Road {
    int city1;
    int city2;
    int length;
};

bool compareRoads(const Road& r1, const Road& r2) {
    return r1.length < r2.length;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<Road> roads(m);
    for (int i = 0; i < m; i++) {
        std::cin >> roads[i].city1 >> roads[i].city2 >> roads[i].length;
    }

    std::sort(roads.begin(), roads.end(), compareRoads);

    std::vector<int> capitalRoads;
    for (int i = 0; i < m; i++) {
        if (roads[i].city1 == 1 || roads[i].city2 == 1) {
            capitalRoads.push_back(i + 1);
        }
    }

    if (capitalRoads.size() < k) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << k << std::endl;
        for (int i = 0; i < k; i++) {
            std::cout << capitalRoads[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}