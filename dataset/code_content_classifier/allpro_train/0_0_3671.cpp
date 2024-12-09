#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, r1, x2, y2, r2, x3, y3, r3;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> x3 >> y3 >> r3;

    double a, b, c, d, e, f, k, x, y;
    a = 2 * (x2 - x1);
    b = 2 * (y2 - y1);

    c = pow(r1, 2) - pow(r2, 2) - pow(x1, 2) + pow(x2, 2) - pow(y1, 2) + pow(y2, 2);

    d = 2 * (x3 - x1);
    e = 2 * (y3 - y1);
    f = pow(r1, 2) - pow(r3, 2) - pow(x1, 2) + pow(x3, 2) - pow(y1, 2) + pow(y3, 2);

    k = (c - f * a / d) / (b - e * a / d);
    x = (c - b * k) / a;
    y = k;

    cout << fixed;
    cout.precision(5);

    cout << x << " " << y << endl;

    return 0;
}