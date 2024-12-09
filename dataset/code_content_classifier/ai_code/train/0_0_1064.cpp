#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double calcSpeed(vector<Point> points) {
    int n = points.size() - 1;
    double min_speed = 1.0;
    
    for (int i = 1; i < n; i++) {
        double angle = atan2(points[i].y, points[i].x);
        if (angle <= 0) angle += 2 * M_PI;
        
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double a1 = atan2(points[j].y, points[j].x);
                double a2 = atan2(points[(j+1) % n].y, points[(j+1) % n].x);
                if (a1 <= 0) a1 += 2 * M_PI;
                if (a2 <= 0) a2 += 2 * M_PI;
                
                if (a1 > a2) swap(a1, a2); // Make sure a1 is less than a2
                
                if (a1 <= angle && angle <= a2) {
                    double d = dist(points[j], points[i]) / min_speed;
                    min_speed = max(min_speed, dist(points[(j+1) % n], points[(j+2) % n]) / d);
                }
            }
        }
    }
    
    return min_speed;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n+1);
    for (int i = 0; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    double min_speed = calcSpeed(points);
    
    cout << fixed;
    cout.precision(7);
    cout << min_speed << endl;
    
    return 0;
}