#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n, k;
    cin >> n >> k;

    Point points[100];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double total_length = 0;
    for (int i = 1; i < n; i++) {
        total_length += distance(points[i-1], points[i]);
    }

    double total_time = total_length / 50 * k;

    cout << fixed;
    cout.precision(9);
    cout << total_time << endl;

    return 0;
}