#include <iostream>
using namespace std;

bool onSegment(int x1, int y1, int x2, int y2, int x, int y) {
    if (x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2))
        return true;
    return false;
}

int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(int xp0, int yp0, int xp1, int yp1, int xp2, int yp2, int xp3, int yp3) {
    int o1 = orientation(xp0, yp0, xp1, yp1, xp2, yp2);
    int o2 = orientation(xp0, yp0, xp1, yp1, xp3, yp3);
    int o3 = orientation(xp2, yp2, xp3, yp3, xp0, yp0);
    int o4 = orientation(xp2, yp2, xp3, yp3, xp1, yp1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(xp0, yp0, xp1, yp1, xp2, yp2)) return true;
    if (o2 == 0 && onSegment(xp0, yp0, xp1, yp1, xp3, yp3)) return true;
    if (o3 == 0 && onSegment(xp2, yp2, xp3, yp3, xp0, yp0)) return true;
    if (o4 == 0 && onSegment(xp2, yp2, xp3, yp3, xp1, yp1)) return true;

    return false;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
        cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;

        if (doIntersect(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}