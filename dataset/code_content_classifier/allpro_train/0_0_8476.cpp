#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
};

Point getCentroid(vector<Point>& polygon) {
    double cx = 0, cy = 0;
    int N = polygon.size();
    for (int i = 0; i < N; i++) {
        cx += polygon[i].x;
        cy += polygon[i].y;
    }
    return Point(cx / N, cy / N);
}

Point getIntersectionPoint(Point centroid) {
    double slope = -centroid.x / centroid.y;
    double a = centroid.x + slope * centroid.y;
    double b = centroid.x - slope * centroid.y;
    
    double x = a / (1 + slope * slope);
    double y = slope * x;
    
    return Point(x, y);
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        
        vector<Point> polygon(N);
        for (int i = 0; i < N; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }
        
        Point centroid = getCentroid(polygon);
        Point intersectionPoint = getIntersectionPoint(centroid);
        
        cout << fixed;
        cout.precision(15);
        cout << intersectionPoint.x << " " << intersectionPoint.y << endl;
    }
    
    return 0;
}