#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double arena_area = area(x1, y1, x2, y2, x3, y3);

    cout << fixed << setprecision(8) << arena_area << endl;

    return 0;
}