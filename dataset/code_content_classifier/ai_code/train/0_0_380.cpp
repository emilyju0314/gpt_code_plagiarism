#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, x, y, x_, y_;
    cin >> r >> x >> y >> x_ >> y_;

    double distance = sqrt((x - x_) * (x - x_) + (y - y_) * (y - y_));
    if (distance >= 2 * r) {
        cout << 1 << endl;
    } else {
        cout << ceil(distance / (2 * r)) << endl;
    }

    return 0;
}