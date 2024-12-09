#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    double min_radius;
    
    if (d >= r1 + r2) {
        min_radius = (d - r1 - r2) / 2.0;
    } else if (d + min(r1, r2) <= max(r1, r2)) {
        min_radius = max(r1, r2) - (d + min(r1, r2));
    } else {
        min_radius = 0;
    }
    
    cout << fixed;
    cout.precision(10);
    cout << min_radius << endl;

    return 0;
}