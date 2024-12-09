#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double area(Point a, Point b, Point c) {
    return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2.0);
}

double minUncoveredArea(vector<Point>& polygon) {
    double minArea = 1e9; // Initialize with a large value
    
    for(int i = 0; i < polygon.size(); i++) {
        double currArea = area(polygon[i], polygon[(i+1)%polygon.size()], polygon[(i+2)%polygon.size()]);
        minArea = min(minArea, currArea);
    }
    
    return minArea/2.0; // Return half of the min area
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    
    for(int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    cout << fixed << minUncoveredArea(polygon) << endl;
    
    return 0;
}