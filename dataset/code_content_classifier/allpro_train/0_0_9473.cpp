#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    double xw = xb * (yw - r - yb + 0.0) / (2 * (yw - r) - y1 - y2);
    if (xw < r || xw > xb || yw - r < y1) {
        cout << "-1" << endl;
    } else {
        cout << fixed << setprecision(10) << xw << endl;
    }

    return 0;
}