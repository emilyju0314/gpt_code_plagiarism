#include <iostream>

using namespace std;

bool isOnSameSide(int x1, int y1, int x2, int y2, int xm1, int ym1, int xm2, int ym2) {
    int dx1 = x2 - x1;
    int dy1 = y2 - y1;
    int dx2 = xm2 - xm1;
    int dy2 = ym2 - ym1;
    return (dx1 * dy2 - dx2 * dy1 >= 0);
}

int main() {
    int xv, yv, xp, yp, xw1, yw1, xw2, yw2, xm1, ym1, xm2, ym2;
    cin >> xv >> yv >> xp >> yp >> xw1 >> yw1 >> xw2 >> yw2 >> xm1 >> ym1 >> xm2 >> ym2;

    if (isOnSameSide(xv, yv, xp, yp, xw1, yw1, xm1, ym1) != isOnSameSide(xv, yv, xp, yp, xw2, yw2, xm1, ym1) ||
        isOnSameSide(xv, yv, xp, yp, xw1, yw1, xm2, ym2) != isOnSameSide(xv, yv, xp, yp, xw2, yw2, xm2, ym2)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}