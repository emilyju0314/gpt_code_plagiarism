#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int c1x, c1y, c1r, c2x, c2y, c2r;
    cin >> c1x >> c1y >> c1r;
    cin >> c2x >> c2y >> c2r;

    double d = sqrt((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));

    double a = (c1r * c1r - c2r * c2r + d * d) / (2 * d);
    double h = sqrt(c1r * c1r - a * a);

    double x1 = c1x + a * (c2x - c1x) / d + h * (c2y - c1y) / d;
    double y1 = c1y + a * (c2y - c1y) / d - h * (c2x - c1x) / d;

    double x2 = c1x + a * (c2x - c1x) / d - h * (c2y - c1y) / d;
    double y2 = c1y + a * (c2y - c1y) / d + h * (c2x - c1x) / d;

    if (x1 < x2 || (x1 == x2 && y1 < y2)) {
        cout << fixed << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    } else {
        cout << fixed << x2 << " " << y2 << " " << x1 << " " << y1 << endl;
    }

    return 0;
}