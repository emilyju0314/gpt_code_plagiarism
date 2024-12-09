#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point(double x_, double y_) : x(x_), y(y_) {}
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    int n;
    cin >> n;

    vector<pair<Point, double>> circles;

    for (int i = 0; i < n; i++) {
        double xi, yi, ri;
        cin >> xi >> yi >> ri;
        Point center(xi, yi);
        circles.push_back(make_pair(center, ri));
    }

    double minRadius = dist(p1, p2) / 2;

    for (int i = 0; i < n; i++) {
        double d1 = dist(circles[i].first, p1);
        double d2 = dist(circles[i].first, p2);
        double d = max(0.0, (d1 + d2 + circles[i].second) / 2);
        minRadius = max(minRadius, d);
    }

    cout.precision(10);
    cout << fixed << minRadius << endl;

    return 0;
}