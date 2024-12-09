#include <iostream>

using namespace std;

int main() {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    int dx = bx - ax;
    int dy = by - ay;
    int ex = cx - bx;
    int ey = cy - by;

    if (dx * dx + dy * dy == ex * ex + ey * ey && dx * ey != dy * ex) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}