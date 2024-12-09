#include <iostream>
#include <cmath>

struct Point {
    double x, y;
    
    void print() {
        std::cout << x << " " << y << std::endl;
    }
};

void kochCurve(Point p1, Point p2, int depth) {
    if (depth == 0) {
        p1.print();
        p2.print();
    } else {
        Point s, t, u;
        
        s.x = (2 * p1.x + 1 * p2.x) / 3.0;
        s.y = (2 * p1.y + 1 * p2.y) / 3.0;
        
        t.x = (1 * p1.x + 2 * p2.x) / 3.0;
        t.y = (1 * p1.y + 2 * p2.y) / 3.0;
        
        double angle = M_PI / 3.0;
        u.x = s.x + (t.x - s.x) * cos(angle) - (t.y - s.y) * sin(angle);
        u.y = s.y + (t.x - s.x) * sin(angle) + (t.y - s.y) * cos(angle);
        
        kochCurve(p1, s, depth - 1);
        s.print();
        kochCurve(s, u, depth - 1);
        u.print();
        kochCurve(u, t, depth - 1);
        t.print();
        kochCurve(t, p2, depth - 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    
    Point p1 = {0.0, 0.0};
    Point p2 = {100.0, 0.0};
    
    kochCurve(p1, p2, n);
    
    p2.print();
    
    return 0;
}