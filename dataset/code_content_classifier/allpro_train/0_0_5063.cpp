#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

int main() {
    int N;
    cin >> N;

    vector<Point> fans;
    for (int i = 0; i < N; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        fans.push_back(Point(x, y));
    }

    double max_radius = -1;
    vector<Point> selected_points(3);

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                Point p1 = fans[i], p2 = fans[j], p3 = fans[k];

                // Calculate the center of the circle passing through p1, p2, p3
                double A = 2*(p2.x - p1.x);
                double B = 2*(p2.y - p1.y);
                double C = 2*(p3.x - p1.x);
                double D = 2*(p3.y - p1.y);
                double E = pow(p2.x, 2) - pow(p1.x, 2) + pow(p2.y, 2) - pow(p1.y, 2);
                double F = pow(p3.x, 2) - pow(p1.x, 2) + pow(p3.y, 2) - pow(p1.y, 2);

                double det = A*D - B*C;
                double x0 = (E*D - B*F) / det;
                double y0 = (-C*E + A*F) / det;

                Point center(x0, y0);
                
                // Calculate the radius of the circle
                double radius = dist(center, p1);

                if (radius > max_radius) {
                    max_radius = radius;
                    selected_points = {p1, p2, p3};
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << selected_points[i].x << " " << selected_points[i].y << endl;
    }

    return 0;
}