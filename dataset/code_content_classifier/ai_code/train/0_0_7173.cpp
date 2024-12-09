#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Line {
    Point start, end;
};

double areaOfTriangle(Point p1, Point p2, Point p3) {
    return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
  
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // 1 for clockwise, 2 for counterclockwise
}

bool doIntersect(Line l1, Line l2) {
    Point p1 = l1.start, q1 = l1.end;
    Point p2 = l2.start, q2 = l2.end;
  
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
  
    if (o1 != o2 && o3 != o4)
        return true;
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false;
}

string getFortune(Line l1, Line l2, Line l3) {
    if (doIntersect(l1, l2) || doIntersect(l1, l3) || doIntersect(l2, l3)) {
        return "kyo";
    }
    
    Point p1 = {l2.start.x, l2.start.y};
    Point p2 = {l2.end.x, l2.end.y};
    Point p3 = {
        ((l1.start.x * (l1.end.y - l2.end.y) + l1.end.x * (l2.end.y - l2.start.y) + l2.end.x * (l2.start.y - l1.start.y)) /
        (l1.start.y - l2.start.y)),
        ((l1.start.y * (l1.end.x - l2.end.x) + l1.end.y * (l2.end.x - l2.start.x) + l2.end.y * (l2.start.x - l1.start.x)) /
        (l1.start.x - l2.start.x))
    };

    double area = areaOfTriangle(p1, p2, p3);
    
    if (area > 1900000) return "Daikichi";
    else if (area >= 1000000 && area < 1900000) return "Nakayoshi (chu-kichi)";
    else if (area >= 100000 && area < 1000000) return "Kichi";
    else if (area > 0 && area < 100000) return "Kokichi (syo-kichi)";
    else return "kyo";
}

int main() {
    Line l1, l2, l3;
    
    while (true) {
        cin >> l1.start.x >> l1.start.y >> l1.end.x >> l1.end.y;
        if (l1.start.x == 0 && l1.start.y == 0 && l1.end.x == 0 && l1.end.y == 0)
            break;
        
        cin >> l2.start.x >> l2.start.y >> l2.end.x >> l2.end.y;
        cin >> l3.start.x >> l3.start.y >> l3.end.x >> l3.end.y;
        
        string result = getFortune(l1, l2, l3);
        cout << result << endl;
    }
    
    return 0;
}