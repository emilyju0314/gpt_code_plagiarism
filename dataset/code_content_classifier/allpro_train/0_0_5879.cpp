#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

Point intersect(Point p1, Point p2, Point p3, Point p4) {
    Point intersect;
    double A1 = p2.y - p1.y;
    double B1 = p1.x - p2.x;
    double C1 = A1 * p1.x + B1 * p1.y;

    double A2 = p4.y - p3.y;
    double B2 = p3.x - p4.x;
    double C2 = A2 * p3.x + B2 * p3.y;

    double determinant = A1 * B2 - A2 * B1;

    if (determinant == 0) {
        intersect.x = numeric_limits<double>::infinity();
        intersect.y = numeric_limits<double>::infinity();
    } else {
        intersect.x = (B2 * C1 - B1 * C2) / determinant;
        intersect.y = (A1 * C2 - A2 * C1) / determinant;
    }

    return intersect;
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int caseNum = 1;
    int N;
    cin >> N;

    while (N != 0) {
        Point initial, destination;
        cin >> initial.x >> initial.y >> destination.x >> destination.y;

        vector<Line> electrodes(N);
        vector<Point> intersections;

        for (int i = 0; i < N; i++) {
            cin >> electrodes[i].p1.x >> electrodes[i].p1.y >> electrodes[i].p2.x >> electrodes[i].p2.y;
        }

        for (Line electrode : electrodes) {
            Point intersectP = intersect(electrode.p1, electrode.p2, initial, destination);
            intersections.push_back(intersectP);
        }

        sort(intersections.begin(), intersections.end(), [](Point a, Point b) { return distance(a, initial) < distance(b, initial); });

        double shortestDist = numeric_limits<double>::infinity();

        for (Point intersectP : intersections) {
            if (intersectP.x != numeric_limits<double>::infinity()) {
                double dist = distance(initial, intersectP) + distance(intersectP, destination);
                shortestDist = min(shortestDist, dist);
            }
        }

        cout << "Case " << caseNum << ": ";
        if (shortestDist == numeric_limits<double>::infinity()) {
            cout << "Impossible" << endl;
        } else {
            cout << fixed << setprecision(5) << shortestDist << endl;
        }

        caseNum++;
        cin >> N;
    }

    return 0;
}