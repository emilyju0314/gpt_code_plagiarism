#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool is_covered(vector<Point>& points, double r) {
    for (int i = 0; i < points.size(); i++) {
        bool covered = false;
        for (int j = 0; j < points.size(); j++) {
            if (i != j && dist(points[i], points[j]) <= 2 * r) {
                covered = true;
                break;
            }
        }
        if (!covered) {
            return false;
        }
    }
    return true;
}

double min_circle_radius(vector<Point>& points) {
    double low = 0, high = 1000;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (is_covered(points, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    cout << min_circle_radius(points) << endl;

    return 0;
}