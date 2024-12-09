#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isConvex(Point a, Point b, Point c, Point d) {
    double c1 = cross_product(a, b, c);
    double c2 = cross_product(b, c, d);
    double c3 = cross_product(c, d, a);
    double c4 = cross_product(d, a, b);
    
    if ((c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0) || (c1 < 0 && c2 < 0 && c3 < 0 && c4 < 0)) {
        return true;
    }
    
    return false;
}

int main() {
    double xa, ya, xb, yb, xc, yc, xd, yd;
    
    while (cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
        Point a = {xa, ya};
        Point b = {xb, yb};
        Point c = {xc, yc};
        Point d = {xd, yd};
        
        if (isConvex(a, b, c, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}