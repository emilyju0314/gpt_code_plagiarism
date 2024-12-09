#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double totalLength = 0;
    for (int i = 0; i < N; i++) {
        totalLength += dist(points[i], points[(i + 1) % N]);
    }

    double minRoute = totalLength;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double route = totalLength - dist(points[i], points[(i + 1) % N]) - dist(points[j], points[(j + 1) % N]) + dist(points[i], points[j]) + dist(points[(i + 1) % N], points[(j + 1) % N]);
            minRoute = min(minRoute, route);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << minRoute << endl;

    return 0;
}