#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int S, a, b, c;
    cin >> S >> a >> b >> c;

    double x, y, z;

    if (a == 0 && b == 0 && c == 0) {
        x = y = z = 0.0;
    } else {
        double sum = a + b + c;
        x = S * a / sum;
        y = S * b / sum;
        z = S * c / sum;
    }

    cout << x << " " << y << " " << z << endl;

    return 0;
}