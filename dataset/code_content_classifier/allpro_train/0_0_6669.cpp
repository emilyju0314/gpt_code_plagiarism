#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    
    Point(int x, int y) : x(x), y(y) {}
};

vector<Point> points;
set<pair<int, int>> slopes;

int symmetricalPoints(Point p) {
    int minPoints = INT_MAX;
    for (auto& point : points) {
        int dx1 = p.x - point.x;
        int dy1 = p.y - point.y;
        int dx2 = -dx1;
        int dy2 = -dy1;
        
        if (dx1 == 0 && dy1 == 0) continue;
        
        int gcd = abs(__gcd(dx1, dy1));
        
        int num1 = slopes.count({dx1 / gcd, dy1 / gcd});
        int num2 = slopes.count({dx2 / gcd, dy2 / gcd});
        
        minPoints = min(minPoints, num1 + num2);
    }
    
    return minPoints;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        
        if (t == 1) {
            points.push_back(Point(x, y));
            for (auto& point : points) {
                int dx = x - point.x;
                int dy = y - point.y;
                
                if (dx == 0 && dy == 0) continue;
                
                int gcd = abs(__gcd(dx, dy));
                
                slopes.insert({dx / gcd, dy / gcd});
            }
        }
        else if (t == 2) {
            for (auto& point : points) {
                int dx = x - point.x;
                int dy = y - point.y;
                
                if (dx == 0 && dy == 0) continue;
                
                int gcd = abs(__gcd(dx, dy));
                
                slopes.erase({dx / gcd, dy / gcd});
            }
            points.erase(remove_if(points.begin(), points.end(), [&](const Point& p) { return p.x == x && p.y == y; }), points.end());
        }
        else if (t == 3) {
            cout << symmetricalPoints(Point(x, y)) << endl;
        }
    }
    
    return 0;
}