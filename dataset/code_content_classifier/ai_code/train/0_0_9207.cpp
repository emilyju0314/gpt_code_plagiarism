#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, r1, R1, x2, y2, r2, R2;
    cin >> x1 >> y1 >> r1 >> R1;
    cin >> x2 >> y2 >> r2 >> R2;

    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (d >= R1 + r2 || d >= R2 + r1) {
        cout << "0" << endl;
    } else if (d <= abs(R1 - r2) && d <= abs(R2 - r1)) {
        cout << "0" << endl;
    } else if (d <= abs(R1 - r2) || d <= abs(R2 - r1)) {
        cout << "1" << endl;
    } else {
        cout << "2" << endl;
    }

    return 0;
}