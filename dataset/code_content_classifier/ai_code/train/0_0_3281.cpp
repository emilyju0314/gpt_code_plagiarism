#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        double vw, vc;
        cin >> vw >> vc;

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        // Calculating the minimum time required to get to the village
        double total_distance = distance(points[0], points[n-1]);
        double horizontal_distance = points[n-1].x - points[0].x;
        double vertical_distance = points[n-1].y;

        double time_walk = total_distance / vw;
        double time_tunnel = sqrt(horizontal_distance * horizontal_distance + vertical_distance * vertical_distance) / vc;

        double min_time = max(time_walk, time_tunnel);
        cout << fixed;
        cout.precision(6);
        cout << min_time << endl;
    }

    return 0;
}