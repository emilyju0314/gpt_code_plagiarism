#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double area(const vector<Point>& polygon) {
    double area = 0.0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return std::abs(area) / 2.0;
}

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double totalArea = area(polygon);
    double minLen = 1e9;
    double maxLen = 0.0;

    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        Point mid = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
        
        double len = dist(p1, mid);
        
        minLen = min(minLen, len);
        maxLen = max(maxLen, len);
    }

    cout << minLen << endl;
    cout << maxLen << endl;

    return 0;
}