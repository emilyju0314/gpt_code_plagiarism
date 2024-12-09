#include <iostream>
#include <vector>
#include <cmath>

struct Star {
    double x, y;
};

double distance(const Star& s1, const Star& s2) {
    return sqrt(pow(s2.x - s1.x, 2) + pow(s2.y - s1.y, 2));
}

int main() {
    int N, N1, N2;
    std::cin >> N >> N1;

    std::vector<Star> map1(N1);
    for (int i = 0; i < N1; i++) {
        std::cin >> map1[i].x >> map1[i].y;
    }

    std::cin >> N2;
    std::vector<Star> map2(N2);
    for (int i = 0; i < N2; i++) {
        std::cin >> map2[i].x >> map2[i].y;
    }

    for (int i = 0; i < N1; i++) {
        int closestIndex = -1;
        double minDistance = std::numeric_limits<double>::max();
        for (int j = 0; j < N2; j++) {
            double dist = distance(map1[i], map2[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestIndex = j;
            }
        }
        std::cout << i << " " << closestIndex << std::endl;
    }

    return 0;
}