#include <iostream>
using namespace std;

bool doIntersect(int ax1, int ay1, int ax2, int ay2, int ax3, int ay3, int ax4, int ay4,
                 int bx1, int by1, int bx2, int by2, int bx3, int by3, int bx4, int by4) {

    int res1 = (bx1 - ax1) * (ay2 - ay1) - (ax2 - ax1) * (by1 - ay1);
    int res2 = (bx2 - ax1) * (ay2 - ay1) - (ax2 - ax1) * (by2 - ay1);
    int res3 = (bx3 - ax1) * (ay2 - ay1) - (ax2 - ax1) * (by3 - ay1);
    int res4 = (bx4 - ax1) * (ay2 - ay1) - (ax2 - ax1) * (by4 - ay1);

    int res5 = (ax1 - bx1) * (by2 - by1) - (bx2 - bx1) * (ay1 - by1);
    int res6 = (ax2 - bx1) * (by2 - by1) - (bx2 - bx1) * (ay2 - by1);
    int res7 = (ax3 - bx1) * (by2 - by1) - (bx2 - bx1) * (ay3 - by1);
    int res8 = (ax4 - bx1) * (by2 - by1) - (bx2 - bx1) * (ay4 - by1);

    if (((res1 * res2) <= 0) || ((res3 * res4) <= 0) || ((res5 * res6) <= 0) || ((res7 * res8) <= 0))
        return true;

    return false;
}

int main() {
    int ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4;
    int bx1, by1, bx2, by2, bx3, by3, bx4, by4;

    cin >> ax1 >> ay1 >> ax2 >> ay2 >> ax3 >> ay3 >> ax4 >> ay4;
    cin >> bx1 >> by1 >> bx2 >> by2 >> bx3 >> by3 >> bx4 >> by4;

    // Check for intersection
    if (doIntersect(ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4, bx1, by1, bx2, by2, bx3, by3, bx4, by4)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}