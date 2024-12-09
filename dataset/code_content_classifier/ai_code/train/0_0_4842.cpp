#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double calculate_area(vector<Point>& polygon, Point& knife_direction) {
    double min_area = 1e9;

    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        Point ab = {b.x - a.x, b.y - a.y};
        Point ap = {knife_direction.x - a.x, knife_direction.y - a.y};

        double cross = cross_product(ab, ap);
        double area = abs(cross) / 2.0;

        min_area = min(min_area, area);
    }

    return min_area;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        int vx, vy;
        cin >> vx >> vy;

        vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        Point knife_direction = {vx, vy};
        double area = calculate_area(polygon, knife_direction);

        cout << fixed;
        cout.precision(7);
        cout << area << endl;
    }

    return 0;
}