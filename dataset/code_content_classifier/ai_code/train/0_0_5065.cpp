#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

void applyExtension(vector<Point>& segments, int yi, int l) {
    segments[yi].x += l;
}

void applyRotation(vector<Point>& segments, int yi, int a) {
    Point& pivot = segments[yi];
    for (int i = yi + 1; i < segments.size(); i++) {
        double x = segments[i].x - pivot.x;
        double y = segments[i].y - pivot.y;
        double angle = a * M_PI / 180.0;
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        segments[i].x = pivot.x + new_x;
        segments[i].y = pivot.y + new_y;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> segments(n + 1);
    for (int i = 1; i <= n; i++) {
        segments[i].x = i - 1;
        segments[i].y = 0;
    }

    for (int i = 0; i < m; i++) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        if (xi == 1) {
            applyExtension(segments, yi, zi);
        } else if (xi == 2) {
            applyRotation(segments, yi, zi);
        }

        cout << fixed;
        cout << segments[n].x << " " << segments[n].y << endl;
    }

    return 0;
}