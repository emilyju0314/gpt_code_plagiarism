#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double check(vector<Point>& buildings, double radius) {
    double left = -1e4, right = 1e4, top = 1e4, bottom = -1e4;
    for (auto& building : buildings) {
        left = min(left, building.x);
        right = max(right, building.x);
        top = min(top, building.y);
        bottom = max(bottom, building.y);
    }

    Point center = { (left + right) / 2, (top + bottom) / 2 };
    double rad = max(dist(center, {left, top}), dist(center, {left, bottom}));
    rad = max(rad, dist(center, {right, top}));
    rad = max(rad, dist(center, {right, bottom}));

    double min_radius = 0;
    for (auto& building : buildings) {
        double d = dist(center, building);
        min_radius = max(min_radius, d - radius + EPS);
    }

    return max(rad, min_radius);
}

int main() {
    int n;
    double r;
    cin >> n >> r;

    vector<Point> buildings(n);
    for (int i = 0; i < n; i++) {
        cin >> buildings[i].x >> buildings[i].y;
    }

    double left = 0, right = 1e6; // initial search space
    while (right - left > EPS) {
        double mid = (left + right) / 2;
        if (check(buildings, mid) <= r) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed << setprecision(10) << right * right * M_PI << endl;

    return 0;
}