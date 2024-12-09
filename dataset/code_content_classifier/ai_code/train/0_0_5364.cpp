#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double shoelace(const std::vector<Point>& points) {
    double sum = 0.0;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        sum += (points[i].x * points[j].y - points[j].x * points[i].y);
    }
    return std::abs(sum) / 2.0;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Point> vertices(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vertices[i].x >> vertices[i].y;
    }

    double totalArea = 0.0;
    for (int i = 1; i < N - 1; i++) {
        std::vector<Point> triangle;
        triangle.push_back(vertices[0]);
        triangle.push_back(vertices[i]);
        triangle.push_back(vertices[i + 1]);
        totalArea += shoelace(triangle);
    }

    std::cout.precision(12);
    std::cout << totalArea << std::endl;

    return 0;
}