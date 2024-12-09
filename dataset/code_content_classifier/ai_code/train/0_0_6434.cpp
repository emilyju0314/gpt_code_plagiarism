#include <iostream>
using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    // Calculate cross product to determine if the hero should turn left, go straight, or turn right
    int cross_product = (xb - xa) * (yc - yb) - (yb - ya) * (xc - xb);
    
    if (cross_product == 0) {
        cout << "TOWARDS" << endl;
    } else if (cross_product > 0) {
        cout << "LEFT" << endl;
    } else {
        cout << "RIGHT" << endl;
    }

    return 0;
}