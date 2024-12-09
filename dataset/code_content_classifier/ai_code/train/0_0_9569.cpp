#include <iostream>
#include <vector>
#include <algorithm>

bool is_cube(const std::vector<std::vector<int>>& points) {
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            int dist = 0;
            for (int k = 0; k < 3; k++) {
                dist += abs(points[i][k] - points[j][k]);
            }
            if (dist == 4) {
                // If the distance between two points is 4, it is a possible edge length of a cube
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> points(8, std::vector<int>(3));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> points[i][j];
        }
    }

    if (!is_cube(points)) {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    std::sort(points.begin(), points.end());

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << points[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}