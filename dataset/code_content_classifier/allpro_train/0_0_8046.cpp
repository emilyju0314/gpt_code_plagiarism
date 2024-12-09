#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double angle(Point p1, Point p2, Point p3) {
    double dx1 = p1.x - p2.x;
    double dy1 = p1.y - p2.y;
    double dx2 = p3.x - p2.x;
    double dy2 = p3.y - p2.y;

    double dot = dx1 * dx2 + dy1 * dy2;
    double cross = dx1 * dy2 - dy1 * dx2;

    return atan2(cross, dot) * 180 / PI;
}

int main() {
    int n;
    double r, theta;
    cin >> n >> r >> theta;

    vector<Point> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].x >> cities[i].y;
    }

    int max_carrots = 0;

    for (int i = 0; i < n; i++) {
        Point current = cities[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            Point next = cities[j];

            double dist = distance(current, next);
            if (dist <= r) {
                int carrots = 1;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    Point third = cities[k];
                    if (angle(current, next, third) <= theta) {
                        carrots++;
                    }
                }
                max_carrots = max(max_carrots, carrots);
            }
        }
    }

    cout << max_carrots << endl;

    return 0;
}