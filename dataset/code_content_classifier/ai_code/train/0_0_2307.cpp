#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double maxDistanceToMaintainConvexPolygon(vector<Point>& points){
    int n = points.size();
    double maxDist = 0;
    
    for(int i = 0; i < n; i++){
        Point p1 = points[i];
        Point p2 = points[(i+1)%n];
        Point p3 = points[(i+2)%n];
        
        double dist1 = distance(p1, p2);
        double dist2 = distance(p2, p3);
        double dist3 = distance(p1, p3);
        
        double s = (dist1 + dist2 + dist3) / 2;
        double area = sqrt(s * (s - dist1) * (s - dist2) * (s - dist3));
        double height = (2 * area) / dist1;
        
        double d = min(dist1, dist2) / height;
        maxDist = max(maxDist, d);
    }
    
    return maxDist / 2;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    
    double maxDist = maxDistanceToMaintainConvexPolygon(points);
    cout.precision(10);
    cout << maxDist << endl;
    
    return 0;
}