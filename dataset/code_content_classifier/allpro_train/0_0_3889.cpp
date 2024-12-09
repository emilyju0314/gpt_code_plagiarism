#include <iostream>
#include <cmath>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double totalDistance = 0.0;

    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        totalDistance += distance(x1, y1, x2, y2);
    }

    std::cout << totalDistance << std::endl;

    return 0;
}