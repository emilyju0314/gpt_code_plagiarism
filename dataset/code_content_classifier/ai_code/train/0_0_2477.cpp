#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

long long cross_product(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int main() {
    int n;
    long long S;
    cin >> n >> S;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Find any three non-collinear points
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                long long area = abs(cross_product(points[i], points[j], points[k]));
                if (area <= 4*S) {
                    cout << points[i].x << " " << points[i].y << endl;
                    cout << points[j].x << " " << points[j].y << endl;
                    cout << points[k].x << " " << points[k].y << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}