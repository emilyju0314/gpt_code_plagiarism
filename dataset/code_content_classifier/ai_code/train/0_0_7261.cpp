#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int N, R, Q;
    while (true) {
        cin >> N >> R >> Q;
        if (N == 0 && R == 0 && Q == 0) break;

        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        for (int i = 0; i < Q; i++) {
            Point p1 = points[0];
            Point p2 = points[1];
            double angle = 2 * M_PI / N;

            double dx = p2.x - R;
            double dy = p2.y;

            p2.x = cos(angle) * dx - sin(angle) * dy + R;
            p2.y = sin(angle) * dx + cos(angle) * dy;

            cout << fixed << p2.x << " " << p2.y << endl;

            points[1] = p2;
        }
    }

    return 0;
}