#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y, idx;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].idx = i + 1;
    }

    sort(points.begin(), points.end(), compareX);

    std::vector<int> path;
    for(int i = 0; i < n; i++) {
        path.push_back(points[i].idx);
    }

    for(int i = 0; i < n; i++) {
        std::cout << path[i] << " ";
    }

    return 0;
}