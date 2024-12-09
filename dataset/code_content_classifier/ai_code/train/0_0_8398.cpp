#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

Point center;
double radius;

void computeCircle(const vector<Point>& points) {
    int n = points.size();

    double sumX = 0, sumY = 0, sumX2 = 0, sumY2 = 0, sumXY = 0;
    
    for(int i = 0; i < n; i++) {
        sumX += points[i].x;
        sumY += points[i].y;
        sumX2 += points[i].x * points[i].x;
        sumY2 += points[i].y * points[i].y;
        sumXY += points[i].x * points[i].y;
    }

    double A = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double B = (sumY - A * sumX) / n;

    center.x = -A / 2;
    center.y = -B / 2;
    
    radius = sqrt(center.x * center.x + center.y * center.y - (sumX2 + sumY2) / n);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    computeCircle(points);

    cout << fixed;
    cout.precision(3);

    cout << center.x << " " << center.y << " " << -radius << endl;

    return 0;
}