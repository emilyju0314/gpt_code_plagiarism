#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

double area(Point p1, Point p2, Point p3) {
    return abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y)) / 2.0);
}

bool isValid(Point A, Point B, Point C) {
    return (A.x >= -100 && A.x <= 100 && A.y >= -100 && A.y <= 100 &&
            B.x >= -100 && B.x <= 100 && B.y >= -100 && B.y <= 100 &&
            C.x >= -100 && C.x <= 100 && C.y >= -100 && C.y <= 100);
}

double minPyramidHeight(Point A, Point B, Point C, Point D) {
    double baseArea = area(A, B, C);
    double sideArea1 = area(A, B, D);
    double sideArea2 = area(B, C, D);
    double sideArea3 = area(C, A, D);
    
    if (baseArea == 0 || sideArea1 == 0 || sideArea2 == 0 || sideArea3 == 0) {
        return -1;
    }
    
    double height = 3 * baseArea / sqrt(sideArea1 + sideArea2 + sideArea3);
    return height;
}

int main() {
    Point A, B, C;
    
    while (cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y) {
        if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0 && C.x == 0 && C.y == 0) {
            break;
        }
        
        Point D1 = {A.x + B.x - C.x, A.y + B.y - C.y};
        Point D2 = {B.x + C.x - A.x, B.y + C.y - A.y};
        Point D3 = {C.x + A.x - B.x, C.y + A.y - B.y};
        
        double minHeight = -1;
        if (isValid(D1, D2, D3)) {
            minHeight = minPyramidHeight(A, B, C, D1);
        }
        if (isValid(D2, D3, D1)) {
            double height2 = minPyramidHeight(A, B, C, D2);
            minHeight = (minHeight == -1) ? height2 : min(minHeight, height2);
        }
        if (isValid(D3, D1, D2)) {
            double height3 = minPyramidHeight(A, B, C, D3);
            minHeight = (minHeight == -1) ? height3 : min(minHeight, height3);
        }
        
        cout << fixed;
        cout.precision(5);
        cout << minHeight << endl;
    }
    
    return 0;
}