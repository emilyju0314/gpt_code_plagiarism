#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double soil_height(vector<Point>& polygon, int d, int V) {
    double max_height = 0.0;
    int n = polygon.size();

    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        double dist = distance(p1, p2);
        double height = V / (dist * d);

        if (height > max_height) {
            max_height = height;
        }
    }

    return max_height;
}

int main() {
    while (true) {
        int n, d, V;
        cin >> n >> d >> V;

        if (n == 0 && d == 0 && V == 0) {
            break;
        }

        vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        double max_soil_height = soil_height(polygon, d, V);
        cout << fixed;
        cout.precision(6);
        cout << max_soil_height << endl;
    }

    return 0;
}