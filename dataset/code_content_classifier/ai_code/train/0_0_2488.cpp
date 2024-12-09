#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.14159265358979323846;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

pair<double, double> getAngles(Point center, Point p1, Point p2) {
    double angle1 = atan2(p1.y - center.y, p1.x - center.x);
    double angle2 = atan2(p2.y - center.y, p2.x - center.x);
    return make_pair(angle1, angle2);
}

int main() {
    int n;
    cin >> n;

    vector<Point> centers(n);
    vector<double> radii(n);
    for (int i = 0; i < n; i++) {
        cin >> centers[i].x >> centers[i].y >> radii[i];
    }

    vector<pair<double, int>> events;
    for (int i = 0; i < n; i++) {
        vector<pair<double, int>> arcs;
        for (int j = 0; j < n; j++) {
            if (i != j && dist(centers[i], centers[j]) < radii[i] + radii[j]) {
                double d2 = dist(centers[i], centers[j]);
                double a = acos((radii[i] * radii[i] + d2 * d2 - radii[j] * radii[j]) / (2 * radii[i] * d2));
                double angle1 = atan2(centers[j].y - centers[i].y, centers[j].x - centers[i].x) - a;
                double angle2 = atan2(centers[j].y - centers[i].y, centers[j].x - centers[i].x) + a;
                arcs.push_back(make_pair(angle1, 1));
                arcs.push_back(make_pair(angle2, -1));
            }
        }

        sort(arcs.begin(), arcs.end());

        for (auto arc : arcs) {
            events.push_back(make_pair(arc.first, arc.second));
        }
    }

    sort(events.begin(), events.end());

    int regions = 1;
    int active_arcs = 1;
    for (int i = 0; i < events.size(); i++) {
        active_arcs += events[i].second;
        if (active_arcs == 1) {
            regions++;
        }
    }

    cout << regions << endl;

    return 0;
}