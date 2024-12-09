#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double getIntersectionArea(Point a, Point b) {
    return 0.5 * fabs(crossProduct(a, b));
}

int main() {
    int n;
    cin >> n;

    vector<vector<Point>> warehouses(n);

    for (int i = 0; i < n; i++) {
        int numCorners;
        cin >> numCorners;

        warehouses[i].resize(numCorners);

        for (int j = 0; j < numCorners; j++) {
            cin >> warehouses[i][j].x >> warehouses[i][j].y;
        }
    }

    double totalArea = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < warehouses[i].size(); j++) {
            Point a = warehouses[i][j];
            Point b = warehouses[i][(j + 1) % warehouses[i].size()];

            totalArea += getIntersectionArea(a, b);
        }
    }

    cout << fixed << setprecision(10) << totalArea;

    return 0;
}