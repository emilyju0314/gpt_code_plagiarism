#include <iostream>
#include <vector>

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

// Function to calculate reflection of point p1 over point p2
Point reflectPoint(Point p1, Point p2) {
    int refl_x = 2*p2.x - p1.x;
    int refl_y = 2*p2.y - p1.y;

    return Point(refl_x, refl_y);
}

int main() {
    int n, j;
    std::cin >> n >> j;

    int m0_x, m0_y;
    std::cin >> m0_x >> m0_y;

    Point m0(m0_x, m0_y);

    std::vector<Point> points;
    for(int i = 0; i < n; i++) {
        int a_x, a_y;
        std::cin >> a_x >> a_y;
        points.push_back(Point(a_x, a_y));
    }

    // Finding the desired point Mj
    Point mj = m0;
    for(long long i = 1; i <= j; i++) {
        Point next_point = reflectPoint(points[(i-1) % n], mj);
        mj = next_point;
    }

    // Output the coordinates of Mj
    std::cout << mj.x << " " << mj.y << std::endl;

    return 0;
}