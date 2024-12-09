#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double getArea(Point a, Point b) {
    return 0.5 * a.x * b.y - 0.5 * a.y * b.x;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Point>> warehouses(n);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        warehouses[i] = vector<Point>(c);

        for (int j = 0; j < c; j++) {
            cin >> warehouses[i][j].x >> warehouses[i][j].y;
        }
    }

    double totalArea = 0.0;
    for (int i = 0; i < n; i++) {
        int c = warehouses[i].size();
        for (int j = 0; j < c; j++) {
            Point a = warehouses[i][j];
            Point b = warehouses[i][(j+1)%c];

            double angleA = atan2(a.y, a.x);
            double angleB = atan2(b.y, b.x);
            double angleDiff = angleB - angleA;

            if (angleDiff < 0) {
                angleDiff += 2 * M_PI;
            }

            if (angleDiff > M_PI) {
                continue;
            }

            totalArea += getArea(a, b);
        }
    }

    printf("%.10f\n", fabs(totalArea));

    return 0;
}