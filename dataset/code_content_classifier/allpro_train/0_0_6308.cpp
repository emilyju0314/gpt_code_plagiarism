#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double PI = 3.14159265358979323846;

struct Point {
    double x, y;
};

double angle(Point A, Point B, Point C) {
    double a = atan2(B.y - A.y, B.x - A.x);
    double b = atan2(C.y - B.y, C.x - B.x);
    double ang = b - a;
    if (ang < 0) ang += 2 * PI;
    return ang;
}

int main() {
    double L, R;
    int N;

    while (true) {
        cin >> L >> R >> N;
        if (L == 0 && R == 0 && N == 0) break;

        vector<Point> vertices(N);
        for (int i = 0; i < N; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }

        // Calculate angle increment for each turn
        double angleIncrement = 2 * PI * R;

        // Calculate angles between consecutive vertices
        vector<double> angles(N);
        for (int i = 0; i < N; i++) {
            angles[i] = angle(vertices[i], vertices[(i + 1) % N], vertices[(i + 2) % N]);
        }

        // Determine maximum angle the bar can rotate before getting stuck
        double maxAngle = 0;
        for (int i = 0; i < N; i++) {
            maxAngle += angles[i];
            if (maxAngle >= angleIncrement) {
                maxAngle = angleIncrement;
                break;
            }
        }

        // Calculate final position of end A
        double finalX = L * cos(maxAngle) + vertices[0].x;
        double finalY = L * sin(maxAngle) + vertices[0].y;

        cout << fixed;
        cout.precision(10);
        cout << finalX << " " << finalY << endl;
    }

    return 0;
}