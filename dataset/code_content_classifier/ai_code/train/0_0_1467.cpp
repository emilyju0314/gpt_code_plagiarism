#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double distanceFromLine(Point p, Point p1, Point p2) {
    double A = p2.y - p1.y;
    double B = p1.x - p2.x;
    double C = p2.x * p1.y - p1.x * p2.y;

    return abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<Point> polygon(n);
        for(int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        double maxDistance = 0.0;
        for(int i = 0; i < n; i++) {
            Point p1 = polygon[i];
            Point p2 = polygon[(i+1)%n];

            double curDistance = 0.0;
            for(int j = 0; j < n; j++) {
                curDistance = max(curDistance, distanceFromLine(polygon[j], p1, p2));
            }

            maxDistance = max(maxDistance, curDistance);
        }

        cout << fixed;
        cout.precision(6);
        cout << maxDistance << endl;
    }

    return 0;
}