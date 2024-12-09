#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<Point>> spots(n, std::vector<Point>(3));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> spots[i][j].x >> spots[i][j].y;
        }
    }

    double perimeter = 0.0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            perimeter += distance(spots[i][j], spots[i][(j + 1) % 3]);
        }
    }

    std::cout << perimeter << std::endl;

    return 0;
}