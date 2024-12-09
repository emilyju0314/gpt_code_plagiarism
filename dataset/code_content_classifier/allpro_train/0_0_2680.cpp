#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double minDistance(vector<Point>& points) {
    double minDist = numeric_limits<double>::max();
    
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    
    return minDist;
}

int main() {
    int N;
    cin >> N;
    
    vector<Point> points(2 * N);
    
    for (int i = 0; i < 2 * N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    double result = minDistance(points);
    
    cout << fixed;
    cout.precision(8);
    cout << result << endl;
    
    return 0;
}