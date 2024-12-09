#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

bool isInsideTriangle(Point A, Point B, Point C, Point P) {
    int o1 = (A.x - P.x) * (B.y - A.y) - (B.x - A.x) * (A.y - P.y);
    int o2 = (B.x - P.x) * (C.y - B.y) - (C.x - B.x) * (B.y - P.y);
    int o3 = (C.x - P.x) * (A.y - C.y) - (A.x - C.x) * (C.y - P.y);

    return (o1 >= 0 && o2 >= 0 && o3 >= 0) || (o1 <= 0 && o2 <= 0 && o3 <= 0);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int xp1, yp1, xp2, yp2, xp3, yp3, xk, yk, xs, ys;
        cin >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3 >> xk >> yk >> xs >> ys;

        Point A = {xp1, yp1};
        Point B = {xp2, yp2};
        Point C = {xp3, yp3};
        Point K = {xk, yk};
        Point S = {xs, ys};

        bool blocked = isInsideTriangle(A, B, C, K) != isInsideTriangle(A, B, C, S);
        
        if(blocked) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }

    return 0;
}