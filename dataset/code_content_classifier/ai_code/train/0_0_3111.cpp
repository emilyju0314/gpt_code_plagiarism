#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
    double x;
    double y;
};

double cross_product(Point p1, Point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double area_of_polygon(vector<Point>& polygon) {
    double area = 0.0;
    int N = polygon.size();
    for (int i = 0; i < N; i++) {
        area += cross_product(polygon[i], polygon[(i+1) % N]);
    }
    return abs(area) / 2.0;
}

int main() {
    int N, R;
    cin >> N >> R;

    vector<Point> polygon(N);
    for (int i = 0; i < N; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double total_circle_area = M_PI * R * R;

    double polygon_area = area_of_polygon(polygon);

    double blue_area = total_circle_area - polygon_area;

    cout.precision(10);
    cout << fixed << blue_area << endl;

    return 0;
}