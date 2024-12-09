#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countIntersectingPairs(vector<Point>& points) {
    int n = points.size();
    int intersectingPairs = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = points[j].x - points[i].x;
            int dy = points[j].y - points[i].y;
            int g = gcd(abs(dx), abs(dy));
            intersectingPairs += g - 1;
        }
    }
    
    return intersectingPairs;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int result = countIntersectingPairs(points);
    
    cout << result << endl;
    
    return 0;
}