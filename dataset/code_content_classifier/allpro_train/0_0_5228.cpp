#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double area(Point a, Point b, Point c) {
    return abs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2.0);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double max_area = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    double current_area = area(points[i], points[j], points[k]) + area(points[i], points[j], points[l]);
                    max_area = max(max_area, current_area);
                }
            }
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << max_area << endl;

    return 0;
}