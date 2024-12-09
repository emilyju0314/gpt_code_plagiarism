#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x, y;
};

bool areCollinear(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) == (p3.x - p1.x) * (p2.y - p1.y);
}

bool canDrawTwoLines(vector<Point>& points) {
    set<pair<int, int>> slopes;
    
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (points[i].x != points[j].x) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                
                slopes.insert({dx, dy});
            }
        }
    }
    
    for (auto it = slopes.begin(); it != slopes.end(); it++) {
        set<int> colinearPoints;
        
        for (int i = 0; i < points.size(); i++) {
            if (colinearPoints.count(i)) continue;
            bool allCollinear = true;
            
            for (int j = i + 1; j < points.size(); j++) {
                if (colinearPoints.count(j)) continue;
                
                if (!areCollinear(points[i], points[j], points[*colinearPoints.begin()])) {
                    allCollinear = false;
                    break;
                }
            }
            
            if (allCollinear) {
                for (int j = i + 1; j < points.size(); j++) {
                    if (areCollinear(points[i], points[j], points[*colinearPoints.begin()])) {
                        colinearPoints.insert(j);
                    }
                }
                colinearPoints.insert(i);
            }
        }
        
        if (colinearPoints.size() == points.size()) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    if (canDrawTwoLines(points)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}