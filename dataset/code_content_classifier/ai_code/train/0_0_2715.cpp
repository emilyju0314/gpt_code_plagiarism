#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

double dot_product(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double cross_product(Point p1, Point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double distance(Point p1, Point p2) {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

Point minus(Point p1, Point p2) {
    return {p1.x - p2.x, p1.y - p2.y};
}

std::pair<double, double> solve_flying_plan(int n, std::vector<Point>& vertices, Point A, Point V, int Fdown, Point U) {
    // Implement the logic to find the minimum time to air drop DravDe
    // Return {-1, -1} if no valid plan is found
    
    return {-1, -1};
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Point> vertices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vertices[i].x >> vertices[i].y;
    }
    
    Point A, V, U;
    int Fdown;
    std::cin >> A.x >> A.y >> V.x >> V.y >> V.z >> Fdown >> U.x >> U.y >> U.z;
    
    auto result = solve_flying_plan(n, vertices, A, V, Fdown, U);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(8) << result.first << " " << result.second << std::endl;
    
    return 0;
}