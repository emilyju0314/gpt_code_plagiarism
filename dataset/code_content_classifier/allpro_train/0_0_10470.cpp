#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double area(vector<Point>& points) {
    double result = 0.0;
    for (int i = 0; i < points.size(); i++) {
        Point a = points[i];
        Point b = points[(i + 1) % points.size()];
        result += crossProduct(a, b);
    }
    return abs(result) / 2.0;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double result = area(points);
    cout << fixed << setprecision(9) << result << endl;

    return 0;
}