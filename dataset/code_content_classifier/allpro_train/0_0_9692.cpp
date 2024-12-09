#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

struct Point {
    int x, y;
};

double calcAngle(Point start, Point end) {
    double angle = atan2(end.y - start.y, end.x - start.x) * 180.0 / PI;
    return angle >= 0 ? angle : 360 + angle;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        
        vector<Point> startPoints(n), endPoints(n);
        for (int i = 0; i < n; i++) {
            cin >> startPoints[i].x >> startPoints[i].y >> endPoints[i].x >> endPoints[i].y;
        }
        
        Point start, goal;
        cin >> start.x >> start.y >> goal.x >> goal.y;
        
        // Calculate angles for each wire segment
        vector<double> angles(n);
        for (int i = 0; i < n; i++) {
            angles[i] = calcAngle(startPoints[i], endPoints[i]);
        }
        
        double minRotationAngle = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double currentRotationAngle = min(abs(angles[i] - angles[j]), 360 - abs(angles[i] - angles[j]));
                currentRotationAngle += min(abs(calcAngle(endPoints[i], start) - calcAngle(endPoints[j], goal)), 360 - abs(calcAngle(endPoints[i], start) - calcAngle(endPoints[j], goal)));
                minRotationAngle = min(minRotationAngle, currentRotationAngle);
            }
        }
        
        if (minRotationAngle < 1e8) {
            cout << fixed << minRotationAngle << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}