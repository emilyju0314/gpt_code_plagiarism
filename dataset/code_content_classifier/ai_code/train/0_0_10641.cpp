#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct Point {
    double x, y, z;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

void findCenter(Point p[], Point& center) {
    center.x = (p[0].x + p[1].x + p[2].x + p[3].x) / 4.0;
    center.y = (p[0].y + p[1].y + p[2].y + p[3].y) / 4.0;
    center.z = (p[0].z + p[1].z + p[2].z + p[3].z) / 4.0;
}

double findRadius(Point p[], Point center) {
    double maxDist = 0.0;
    for(int i = 0; i < 4; i++) {
        double d = dist(p[i], center);
        maxDist = std::max(maxDist, d);
    }
    return maxDist;
}

int main() {
    int n;
    while(std::cin >> n) {
        if(n == 0) break;

        Point p[4];
        for(int i = 0; i < n; i++) {
            std::cin >> p[i].x >> p[i].y >> p[i].z;
        }

        // Finding all possible combinations of 4 points
        double minRadius = 1e9;
        do {
            Point center;
            findCenter(p, center);
            double radius = findRadius(p, center);
            minRadius = std::min(minRadius, radius);
        } while(std::next_permutation(p, p+n));

        std::cout << std::fixed;
        std::cout.precision(5);
        std::cout << minRadius << std::endl;
    }

    return 0;
}