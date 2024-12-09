#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double minDistance = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            minDistance = min(minDistance, distance(points[i], points[j]));
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << minDistance << endl;

    return 0;
}