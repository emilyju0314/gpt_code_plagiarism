#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double getPerimeter(vector<Point>& points) {
    double perimeter = 0.0;
    for (int i = 0; i < points.size(); ++i) {
        perimeter += distance(points[i], points[(i+1) % points.size()]);
    }
    return perimeter;
}

int main() {
    int N, K;
    while (cin >> N >> K && (N != 0 || K != 0)) {
        vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        vector<double> perimeters;
        sort(points.begin(), points.end());
        do {
            bool valid = true;
            for (int i = 0; i < N; ++i) {
                Point p1 = points[i];
                Point p2 = points[(i+1) % N];
                Point p3 = points[(i+2) % N];
                if ((p3.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (p3.y - p1.y)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                perimeters.push_back(getPerimeter(points));
            }
        } while (next_permutation(points.begin(), points.end()));

        sort(perimeters.begin(), perimeters.end());
        if (perimeters.size() < K) {
            cout << -1 << endl;
        } else {
            printf("%.10lf\n", perimeters[K-1]);
        }
    }

    return 0;
}