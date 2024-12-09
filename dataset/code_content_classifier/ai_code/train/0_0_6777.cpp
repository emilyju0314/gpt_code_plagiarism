#include <iostream>
#include <cmath>

int shortestPathLength(int x_A, int y_A, int x_B, int y_B, int x_F, int y_F) {
    int distance = abs(x_A - x_B) + abs(y_A - y_B);
    if ((x_A == x_B && x_B == x_F && ((y_A < y_F && y_F < y_B) || (y_B < y_F && y_F < y_A))) ||
        (y_A == y_B && y_B == y_F && ((x_A < x_F && x_F < x_B) || (x_B < x_F && x_F < x_A)))) {
        distance += 2;
    }
    return distance;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int x_A, y_A, x_B, y_B, x_F, y_F;
        std::cin >> x_A >> y_A >> x_B >> y_B >> x_F >> y_F;
        
        int pathLength = shortestPathLength(x_A, y_A, x_B, y_B, x_F, y_F);
        std::cout << pathLength << std::endl;
    }

    return 0;
}