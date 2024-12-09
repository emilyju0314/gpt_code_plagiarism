#include <iostream>

using namespace std;

bool areParallel(int xp0, int yp0, int xp1, int yp1, int xp2, int yp2, int xp3, int yp3) {
    int dx1 = xp1 - xp0;
    int dy1 = yp1 - yp0;
    int dx2 = xp3 - xp2;
    int dy2 = yp3 - yp2;
    return dx1 * dy2 == dx2 * dy1;
}

bool areOrthogonal(int xp0, int yp0, int xp1, int yp1, int xp2, int yp2, int xp3, int yp3) {
    int dx1 = xp1 - xp0;
    int dy1 = yp1 - yp0;
    int dx2 = xp3 - xp2;
    int dy2 = yp3 - yp2;
    return dx1 * dx2 + dy1 * dy2 == 0;
}

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
        cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;

        if(areParallel(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3)) {
            cout << "2" << endl;
        } else if(areOrthogonal(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}