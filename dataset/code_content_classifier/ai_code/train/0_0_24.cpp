#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A == 0 && B == 0 && C == 0) {
        cout << -1 << endl;
    } else if (A == 0 && B == 0) {
        cout << 0 << endl;
    } else {
        int discriminant = B*B - 4*A*C;

        if (discriminant > 0) {
            double x1 = (-B + sqrt(discriminant)) / (2*A);
            double x2 = (-B - sqrt(discriminant)) / (2*A);
            cout << 2 << endl;
            cout << fixed << setprecision(10) << x1 << endl;
            cout << fixed << setprecision(10) << x2 << endl;
        } else if (discriminant == 0) {
            double x = -B / (2*A);
            cout << 1 << endl;
            cout << fixed << setprecision(10) << x << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}