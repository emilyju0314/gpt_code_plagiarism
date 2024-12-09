#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

bool isVisible(Point A, Point B, Point P) {
    // Implement the visibility check logic here
    return true; // Placeholder for actual implementation
}

int countWatchtowerPoints(Point A, Point B, vector<Point> polygon) {
    int count = 0;
    for (int i = min(A.x, B.x); i <= max(A.x, B.x); i++) {
        Point towerPoint = {i, A.y};
        bool visible = true;
        for (int j = 1; j < polygon.size(); j++) {
            if (!isVisible(towerPoint, P[j], polygon[j]) {
                visible = false;
                break;
            }
        }
        if (visible) count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    Point A = polygon[0];
    Point B = polygon[1];
    
    cout << countWatchtowerPoints(A, B, polygon) << endl;
    
    return 0;
}