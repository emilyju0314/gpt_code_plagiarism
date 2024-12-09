#include <iostream>
#include <cmath>
#include <vector>

struct Star {
    double x, y, a, r;
};

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double calculateInterstellarDistance(std::vector<Star>& stars, int m, int l) {
    double totalDistance = 0.0;

    for (int i = m; i < l; i++) {
        totalDistance += calculateDistance(stars[i].x, stars[i].y, stars[i+1].x, stars[i+1].y);
    }

    return totalDistance;
}

int main() {
    int N, M, L;
    std::vector<Star> stars;

    while (true) {
        std::cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) {
            break;
        }

        stars.resize(N);

        for (int i = 0; i < N; i++) {
            std::cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
        }

        double totalInterstellarDistance = calculateInterstellarDistance(stars, M-1, L-1);
        std::cout << totalInterstellarDistance << std::endl;
    }

    return 0;
}