#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double max_distance(vector<Point>& polygon) {
    int n = polygon.size();
    double max_perimeter = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point midpoint = {(polygon[i].x + polygon[j].x) / 2, (polygon[i].y + polygon[j].y) / 2};
            double max_dist = 0.0;
            
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    double dist = distance(midpoint, polygon[k]);
                    max_dist = max(max_dist, dist);
                }
            }

            max_perimeter = max(max_perimeter, 2.0 * max_dist + distance(polygon[i], polygon[j]));
        }
    }

    return max_perimeter;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        double result = max_distance(polygon);
        cout << fixed << result << endl;
    }

    return 0;
}